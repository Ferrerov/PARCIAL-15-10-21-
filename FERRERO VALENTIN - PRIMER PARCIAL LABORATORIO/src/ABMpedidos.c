#include "ABMpedidos.h"

void InicializarPedidos(ePedido datosPedido[], int tam)
{
    for(int i = 0; i < tam; i++) {
    	datosPedido[i].isEmpty = LIBRE;
    }
}

int CargarPedido( ePedido datosPedido[], int tamPedidos, eCliente datosCliente[], int tamCliente, int* pIdPedido, int reintentos)
{
	int retorno = -1;
	int indiceCliente;

	if(BuscarIdCliente(datosCliente, tamCliente, reintentos, &indiceCliente) == 0)
	{
		for(int i = 0; i < tamPedidos; i++)
		{
			if(datosPedido[i].isEmpty == LIBRE)
			{
				if(GetFloat(&datosPedido[i].kilosTotales, "\nIngrese la cantidad de kilos totales a recolectar: ", "\nError, por favor ingrese la catnidad de kilos totales: ", 1, INT_MAX, 5) == 0)
				{
					datosPedido[i].estadoPedido = PENDIENTE;
					datosPedido[i].idCliente = datosCliente[indiceCliente].idCliente;
					datosPedido[i].idPedido = i + 1;
					*pIdPedido = datosPedido[i].idPedido;
					datosPedido[i].isEmpty = OCUPADO;
					retorno = 0;
					break;
				}
			}
		}
	}
	if(retorno != 0)
	{
			printf("\nNo se ha podido cargar el pedido, se ha cancelado la operación. ");
	}
	return retorno;
}

int VerListaPedidosPendientes(eCliente datosCliente[], int tamCliente, ePedido datosPedido[], int tamPedido)
{
	int retorno = -1;

	for(int i = 0; i < tamCliente; i++)
	{
		if(datosCliente[i].isEmpty == OCUPADO && VerUnPedidoPendiente(datosPedido, tamPedido, datosCliente[i].idCliente) == 0)
		{
			retorno = 0;
		}
	}

	return retorno;
}

int VerUnPedidoPendiente(ePedido datosPedido[], int tamPedido, int idCliente)
{
	int retorno = -1;
	int flagEncabezado = -1;

	for(int i = 0; i < tamPedido; i++)
	{
		if(datosPedido[i].idCliente == idCliente && datosPedido[i].estadoPedido == PENDIENTE)
		{
			if(flagEncabezado != 0)
			{
				printf("\n---------------------------");
				printf("\n|%*s|%*s|", -11, "ID PEDIDO", -11, "KILOS TOTALES");
				printf("\n---------------------------");
				flagEncabezado = 0;
			}
			printf("\n|%*d|%*f", -11, datosPedido[i].idPedido, -11, datosPedido[i].kilosTotales);
			retorno = 0;
		}
	}
	return retorno;
}

int BuscarIdPedido(ePedido datosPedido[], int tam, int reintentos, int* pIndice)// SE PUEDE IR  ANEXO
{
	int retorno = -1;
	int idBuscar;

	do
	{
		reintentos--;

		GetInt(&idBuscar, "\nIngrese el ID del pedido: ", "\nError, ID fuera de rango. Ingrese nuevamente: ", 1, tam, 5);

		for(int i = 0; i < tam; i++)
		{
			if(datosPedido[i].isEmpty == OCUPADO &&  datosPedido[i].idPedido == idBuscar)
			{
				*pIndice = i;
				reintentos = 0;
				retorno = 0;
				break;
			}
		}
		if(retorno != 0)
		{
			printf("ID no encontrado.");
		}
	}while(reintentos > 0);

	return retorno;
}

int ProcesarResiduos(ePedido datosPedido[], int tamPedido, int reintentos)
{
	int retorno = -1;
	int indicePedido;
	int verificador = 0;
	float controlKilos;

	do
	{
		if(BuscarIdPedido(datosPedido, tamPedido, reintentos, &indicePedido) == 0)
		{
			controlKilos = datosPedido[indicePedido].kilosTotales;

			verificador = (GetFloat(&datosPedido[indicePedido].HDPE, "\nIngrese la cantidad de kilos de plastico HDPE: ", "\nError, cantidad incorrecta. Ingrese nuevamente: ", 0, INT_MAX, 5) + verificador);
			controlKilos = controlKilos - datosPedido[indicePedido].HDPE;

			verificador = (GetFloat(&datosPedido[indicePedido].LDPE, "\nIngrese la cantidad de kilos de plastico LDPE: ", "\nError, cantidad incorrecta. Ingrese nuevamente: ", 0, INT_MAX, 5) + verificador);
			controlKilos = controlKilos - datosPedido[indicePedido].LDPE;

			verificador = (GetFloat(&datosPedido[indicePedido].PP, "\nIngrese la cantidad de kilos de plastico PP: ", "\nError, cantidad incorrecta. Ingrese nuevamente: ", 0, INT_MAX, 5) + verificador);
			controlKilos = controlKilos - datosPedido[indicePedido].PP;
		}

		if(!(controlKilos < 0))
		{
			retorno = 0;
			break;
		}
		else
		{
			printf("\nLa cantidad de kilos ingresada excede los kilos totales declarados. Por favor reingrese los datos: ");
		}
	}while( retorno != 0);

	if(verificador == 0)
	{
		datosPedido[indicePedido].estadoPedido = COMPLETADO;
	}
	else
	{
		retorno = -1;
		printf("\nNo se ha podido completar el procesamiento, se ha cancelado la operación. ");
	}

	return retorno;
}

