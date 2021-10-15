#include "informes.h"

int contadorPendientes(int* pCantidad, int idCliente, ePedido datosPedido[], int tamPedido)
{
	int retorno = -1;
	int contador = 0;

	for(int i = 0; i < tamPedido; i++)
	{
		if(datosPedido[i].isEmpty == OCUPADO && datosPedido[i].estadoPedido == PENDIENTE)
		{
			if(datosPedido[i].idCliente == idCliente)
			{
				contador++;
			}
		}
	}
	*pCantidad = contador;

	return retorno;
}

int informarClientes(eCliente datosCliente[], int tamCliente, ePedido datosPedido[], int tamPedido)
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
		if(mostrarUnCliente(datosCliente[i]) == 0)
		{
			contadorPendientes(&cantidad, datosCliente[i].idCliente, datosPedido, tamPedido);
			printf("\n(Pedidos de recoleccion pendientes: %d)\n", cantidad);
			flagEncabezado = -1;
			retorno = 0;
		}
	}

	return retorno;
}

int clientesPorPedido(int idClientePedido, eCliente datosCliente[], int tamClientes)
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

int informarPendientes(eCliente datosCliente[], int tamCliente, ePedido datosPedido[], int tamPedido)
{
	int retorno = -1;

	for(int i = 0; i < tamPedido; i++)
	{
		if(datosPedido[i].estadoPedido == PENDIENTE && datosPedido[i].isEmpty == OCUPADO)
		{
			clientesPorPedido(datosPedido[i].idCliente, datosCliente, tamCliente);
			printf("\nCantidad de kilos totales: %d\n" , datosPedido[i].kilosTotales);
		}
	}
	return retorno;
}

int informarProcesados(eCliente datosCliente[], int tamCliente, ePedido datosPedido[], int tamPedido)
{
	int retorno = -1;

	for(int i = 0; i < tamPedido; i++)
		{
			if(datosPedido[i].estadoPedido == COMPLETADO)
			{
				clientesPorPedido(datosPedido[i].idCliente, datosCliente, tamCliente);
				printf("\nCantidad de kilos de HDPE: %d\n" , datosPedido[i].HDPE);
				printf("\nCantidad de kilos de LDPE: %d\n" , datosPedido[i].LDPE);
				printf("\nCantidad de kilos de PP: %d\n" , datosPedido[i].PP);
			}

		}

	return retorno;
}

int verListaLocalidades(eCliente datosCliente[], int tamCliente)
{
	int retorno = -1;

	printf("\nLocalidades: ");
	for(int i = 0; i< tamCliente; i++)
	{
		if(datosCliente[i].isEmpty == OCUPADO)
		{
			printf("\n%s", datosCliente[i].localidad);
			retorno = 0;
		}
	}

	return retorno;
}

int pedirLocalidad(eCliente datosCliente[], int tamCliente, int* pIndice)
{
	int retorno = -1;
	char localidad[50];

	getString("\nIngrese una localidad: ", localidad, 50);

	for(int i = 0; i< tamCliente; i++)
	{
		if(datosCliente[i].isEmpty == OCUPADO && strcmp(datosCliente[i].localidad, localidad) == 0)
		{
			*pIndice = i;
			retorno = 0;
			break;
		}
	}

	return retorno;
}

int informarPendientesPorLocalidad(eCliente datosCliente[], int tamCliente, ePedido datosPedido[], int tamPedido)
{
	int retorno = -1;
	int cantidad;
	int indice;

	verListaLocalidades(datosCliente, tamCliente);
	if(pedirLocalidad(datosCliente, tamCliente, &indice)==0)
	{
		printf("\nPedidos pendientes para la siguiente localidad: %s", datosCliente[indice].localidad);
		contadorPendientes(&cantidad, datosCliente[indice].idCliente, datosPedido, tamPedido);
		printf("\nLa cantidad de pedidos pendies es de: %d\n", cantidad);
		retorno = 0;
	}
	return retorno;
}

int promedioPolipropileno(ePedido datosPedido[], int tamPedido, int idCliente, float* pPromedio)
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

int informarPolipropilenoPromedio(eCliente datosCliente[], int tamCliente, ePedido datosPedido[], int tamPedido)
{
	int retorno = -1;
	float promedio;

	for(int i = 0; i < tamCliente; i++)
	{
		if(datosCliente[i].isEmpty == OCUPADO && promedioPolipropileno(datosPedido, tamPedido, datosCliente[i].idCliente, &promedio) == 0)
		{
			printf("\n|%*s|" , -30, "NOMBRE DE LA EMPRESA");
			printf("\n---------------------------------------------");
			printf("\n|%*f|", -30, promedio);
			retorno = 0;
		}
	}
	return retorno;
}
