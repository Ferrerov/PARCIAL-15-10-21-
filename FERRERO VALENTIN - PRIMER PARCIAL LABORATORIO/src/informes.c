#include "informes.h"

int ContadorEstadoPedido(int* pCantidad, int idCliente, int estadoPedido,ePedido datosPedido[], int tamPedido)
{
	int retorno = -1;
	int contador = 0;

	for(int i = 0; i < tamPedido; i++)
	{
		if(datosPedido[i].isEmpty == OCUPADO && datosPedido[i].estadoPedido == estadoPedido && datosPedido[i].idCliente == idCliente)
		{
			contador++;
		}
	}
	*pCantidad = contador;

	return retorno;
}

int InformarClientes(eLocalidad datosLocalidad[], eCliente datosCliente[], int tamCliente, ePedido datosPedido[], int tamPedido)
{
	int retorno = -1;
	int cantidad;
	int flagEncabezado = -1;

	for(int i = 0; i < tamCliente; i++)
	{
		if(flagEncabezado != 0)
		{
			printf("\n|%*s|%*s|%*s|%*s|%*s", -11, "ID CLIENTE", -30, "NOMBRE DE LA EMPRESA",-13,"CUIT",-30 ,"DIRECCION", -30,"LOCALIDAD");
			printf("\n----------------------------------------------------------------------------------------------------------------------");
			flagEncabezado = 0;
		}
		if(MostrarUnCliente(datosCliente[i], datosLocalidad, tamCliente) == 0)
		{
			ContadorEstadoPedido(&cantidad, datosCliente[i].idCliente, PENDIENTE, datosPedido, tamPedido);
			printf("\n(Pedidos de recoleccion pendientes: %d)\n", cantidad);
			flagEncabezado = -1;
			retorno = 0;
		}
	}

	return retorno;
}

int ClientesPorPedido(int idClientePedido, eCliente datosCliente[], int tamClientes)
{
	int retorno = -1;

	for(int i = 0; i < tamClientes; i++)
	{
		if(idClientePedido == datosCliente[i].idCliente && datosCliente[i].isEmpty == OCUPADO)
		{
			printf("\n|%*s|%*s|",-13,"CUIT",-30 ,"DIRECCION");
			printf("\n----------------------------------------------");
			printf("\n|%*s|%*s|", -13, datosCliente[i].cuit, -30, datosCliente[i].direccion);
			printf("\n----------------------------------------------");
			retorno = 0;
		}
	}

	return retorno;
}

int InformarPendientes(eCliente datosCliente[], int tamCliente, ePedido datosPedido[], int tamPedido)
{
	int retorno = -1;

	for(int i = 0; i < tamPedido; i++)
	{
		if(datosPedido[i].estadoPedido == PENDIENTE && datosPedido[i].isEmpty == OCUPADO)
		{
			ClientesPorPedido(datosPedido[i].idCliente, datosCliente, tamCliente);
			printf("\nCantidad de kilos totales: %.2f\n" , datosPedido[i].kilosTotales);
		}
	}
	return retorno;
}

int InformarProcesados(eCliente datosCliente[], int tamCliente, ePedido datosPedido[], int tamPedido)
{
	int retorno = -1;

	for(int i = 0; i < tamPedido; i++)
		{
			if(datosPedido[i].estadoPedido == COMPLETADO)
			{
				ClientesPorPedido(datosPedido[i].idCliente, datosCliente, tamCliente);
				printf("\nCantidad de kilos de HDPE: %.2f\n" , datosPedido[i].HDPE);
				printf("\nCantidad de kilos de LDPE: %.2f\n" , datosPedido[i].LDPE);
				printf("\nCantidad de kilos de PP: %.2f\n" , datosPedido[i].PP);
			}

		}

	return retorno;
}

int InformarPendientesPorLocalidad(eLocalidad localidades[], eCliente datosCliente[], int tamCliente, ePedido datosPedido[], int tamPedido)
{
	int retorno = -1;
	int idLocalidad;
	char auxLocalidad[50];
	int cantidadPendientes;

	VerListadoDeLocalidades(localidades, tamCliente);
	if(BuscarLocalidad(&idLocalidad, auxLocalidad, localidades, tamCliente)==0)
	{
		for(int i = 0; i < tamCliente; i++)
		{
			if(datosCliente[i].idLocalidad == idLocalidad &&
					ContadorEstadoPedido(&cantidadPendientes, datosCliente[i].idCliente, PENDIENTE, datosPedido, tamPedido) == 0)
			{
				retorno = 0;
				printf("\nLocalidad seleccionada: %s" , auxLocalidad);
				printf("\nCantidad de pedidos pendientes: %d", cantidadPendientes);
			}
		}
	}
	else
	{
		printf("\nNo se ha encontrado la localidad ingresada.");
	}

	return retorno;
}

int PromedioPolipropileno(ePedido datosPedido[], int tamPedido, int idCliente, float* pPromedio)
{
	int retorno = -1;
	int acumulador = 0;
	float contador = 0;

	for(int i = 0; i < tamPedido; i++)
	{
		if(idCliente == datosPedido[i].idCliente && datosPedido[i].estadoPedido == COMPLETADO)
		{
			if( datosPedido[i].HDPE > 0)
			{
				acumulador = acumulador + datosPedido[i].HDPE;
				contador++;
				retorno = 0;
			}
		}
	}
	*pPromedio = acumulador / contador;

	return retorno;
}

int InformarPolipropilenoPromedio(eCliente datosCliente[], int tamCliente, ePedido datosPedido[], int tamPedido)
{
	int retorno = -1;
	float promedio;

	for(int i = 0; i < tamCliente; i++)
	{
		if(datosCliente[i].isEmpty == OCUPADO && PromedioPolipropileno(datosPedido, tamPedido, datosCliente[i].idCliente, &promedio) == 0)
		{
			printf("\n|%*s|" , -30, "NOMBRE DE LA EMPRESA");
			printf("\n---------------------------------------------");
			printf("\n|%*f|", -30, promedio);
			retorno = 0;
		}
	}
	return retorno;
}

int BuscarMaxEstadoPedido(int* pIndice, int* pCantidad, int estadoPedido,eCliente datosCliente[], int tamCliente, ePedido datosPedido[], int tamPedido)
{
	int retorno = -1;
	int cantidad;
	int cantidadMax = 0;

	for(int i = 0; i < tamCliente; i++)
	{
		ContadorEstadoPedido(&cantidad, datosCliente[i].idCliente, estadoPedido, datosPedido, tamPedido);
		if(cantidad > cantidadMax)
		{
			cantidadMax = cantidad;
			*pIndice = datosCliente[i].idCliente;
		}
	}
	*pCantidad = cantidadMax;

	return retorno;
}

int InformarClienteMasPendientes(eCliente datosCliente[], int tamCliente, ePedido datosPedido[], int tamPedido)
{
	int retorno = -1;
	int indice;
	int cantidad;

	if(BuscarMaxEstadoPedido(&indice, &cantidad, PENDIENTE, datosCliente, tamCliente, datosPedido, tamPedido) == 0)
	{
		printf("\nEl cliente que mas pedidos pendientes tiene es: %s", datosCliente[indice].empresa);
		printf("\nLa cantidad de pedidos pendientes es de: %d", cantidad);
		retorno = 0;
	}

	return retorno;
}

int InformarClienteMasCompletados(eCliente datosCliente[], int tamCliente, ePedido datosPedido[], int tamPedido)
{
	int retorno = -1;
	int indice;
	int cantidad;

	if(BuscarMaxEstadoPedido(&indice, &cantidad, COMPLETADO, datosCliente, tamCliente, datosPedido, tamPedido) == 0)
	{
		printf("\nEl cliente que mas pedidos completados tiene es: %s", datosCliente[indice].empresa);
		printf("\nLa cantidad de pedidos completados es de: %d", cantidad);
		retorno = 0;
	}

	return retorno;
}
