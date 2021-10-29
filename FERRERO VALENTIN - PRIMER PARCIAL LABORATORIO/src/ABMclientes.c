#include "ABMclientes.h"

void InicializarClientes(eCliente datosCliente[],int tam)
{
    for(int i = 0; i < tam; i++) {
    	datosCliente[i].isEmpty = LIBRE;
    }
}

int CargarDatosCliente(eCliente datosCliente[], eLocalidad localidad[], int tam, int* pIdCliente)
{
	int retorno = -1;
	for(int i = 0; i < tam; i++)
	{
		if(datosCliente[i].isEmpty == LIBRE)
		{
			GetString("Ingrese el nombre de la empresa: ", datosCliente[i].empresa);
			GetString("Ingrese el cuit de la empresa (Sin guiones): \n", datosCliente[i].cuit);
			while(strlen(datosCliente[i].cuit) != 11)
			{
				GetString("Error, ingrese un cuit v�lido (Sin guiones): \n", datosCliente[i].cuit);
			}
			GetString("Ingrese la direcci�n de la empresa: ", datosCliente[i].direccion);
			//GetString("Ingrese la localidad: ", datosCliente[i].localidad);
			NuevaLocalidad(&datosCliente[i].idLocalidad, localidad, tam);
			datosCliente[i].idCliente = i +1;
			*pIdCliente = datosCliente[i].idCliente;
			datosCliente[i].isEmpty = OCUPADO;
			retorno = 0;
			break;
		}
	}

	return retorno;
}

int MostrarUnCliente(eCliente datosCliente, eLocalidad datosLocalidad[], int tam)
{
	int retorno = -1;
	char auxLocalidad[50];
	if(datosCliente.isEmpty == OCUPADO)
			{
				VerLocalidadPorId(auxLocalidad, datosLocalidad, tam, datosCliente.idLocalidad);
				printf("\n|%-11d|%-30s|%-13s|%-30s|%-50s",
						datosCliente.idCliente,
						datosCliente.empresa,
						datosCliente.cuit,
						datosCliente.direccion,
						auxLocalidad);
				retorno = 0;
			}
	return retorno;
}

int VerListaClientes(eCliente datosCliente[], eLocalidad datosLocalidad[], int tam)
{
	int retorno = -1;
	printf("\n|%*s|%*s|%*s|%*s|%*s", -11, "ID CLIENTE", -30, "NOMBRE DE LA EMPRESA",-13,"CUIT",-30 ,"DIRECCION", -30,"LOCALIDAD");
	printf("\n----------------------------------------------------------------------------------------------------------------------");

	for(int i = 0; i < tam; i++)
	{
		if(MostrarUnCliente(datosCliente[i], datosLocalidad, tam) == 0)
		{
			retorno = 0;
		}
	}
	return retorno;
}

int BuscarIdCliente(eCliente datosCliente[], int tam, int reintentos, int* pIndice)//PUEDE IR EN BIBLIOTECA NEXO
{
	int retorno = -1;
	int idBuscar;

	do
	{
		reintentos--;

		GetInt(&idBuscar, "\nIngrese el ID del cliente: ", "\nError, ID fuera de rango. Ingrese nuevamente: ", 1, tam, 5);

		for(int i = 0; i < tam; i++)
		{
			if(datosCliente[i].isEmpty == OCUPADO &&  datosCliente[i].idCliente == idBuscar)
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

int ModificarCliente(eCliente datosCliente[], eLocalidad localidad[], int tam, int reintentos)
{
	int retorno = -1;
	int indiceId;

	if(BuscarIdCliente(datosCliente, tam, reintentos, &indiceId) == 0)
	{
		GetString("Ingrese la nueva direcci�n de la empresa: ", datosCliente[indiceId].direccion);
		NuevaLocalidad(&datosCliente[indiceId].idLocalidad, localidad, tam);
		retorno = 0;
	}

	return retorno;
}

int BajaCliente(eCliente datosCliente[], int tam, int reintentos)
{
	int retorno = -1;
	int idBaja;
	char respuesta;

	do
	{
		reintentos--;
		GetInt(&idBaja, "\nIngrese el ID del cliente a dar de baja: ","\nError, ID fuera de rango. Ingrese nuevamente: ", 1,100, 5);

		for(int i = 0; i < tam; i++)
		{
			if(datosCliente[i].isEmpty == OCUPADO && datosCliente[i].idCliente == idBaja)
			{
				GetYesNo("\nEsta seguro que desea dar de baja al cliente? (s/n): ", "\nError, ingrese una opci�n v�lida: ", &respuesta, 5);

				if(respuesta == 's')
				{
					datosCliente[i].isEmpty = LIBRE;
					retorno = 0;
				}
			}
		}

	}while(retorno != 0 && reintentos > 0);
	if (retorno != 0)
	{
		printf("\nNo se ha podido dar de baja, se ha cancelado la operaci�n. ");
		printf("\nPulse una tecla para continuar");
		getchar();
	}

	return retorno;
}

