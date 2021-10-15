#include "ABMclientes.h"

void inicializarClientes(eCliente datosCliente[],int tam)
{
    for(int i = 0; i < tam; i++) {
    	datosCliente[i].isEmpty = LIBRE;
    }
}

int cargarDatosCliente(eCliente datosCliente[], int tam, int* pIdCliente)
{
	int retorno = -1;
	for(int i = 0; i < tam; i++)
	{
		if(datosCliente[i].isEmpty == LIBRE)
		{
			getString("Ingrese el nombre de la empresa: ", datosCliente[i].empresa, 50);
			getString("Ingrese el cuit de la empresa (Sin guiones): \n", datosCliente[i].cuit, 50);
			while(strlen(datosCliente[i].cuit) != 12)
			{
				getString("Error, ingrese un cuit válido (Sin guiones): \n", datosCliente[i].cuit, 50);
			}
			getString("Ingrese la dirección de la empresa: ", datosCliente[i].direccion, 50);
			getString("Ingrese la localidad: ", datosCliente[i].localidad, 50);
			datosCliente[i].idCliente = i +1;
			*pIdCliente = datosCliente[i].idCliente;
			datosCliente[i].isEmpty = OCUPADO;
			retorno = 0;
			break;
		}
	}

	return retorno;
}

int mostrarUnCliente(eCliente datosCliente)
{
	int retorno = -1;
	if(datosCliente.isEmpty == OCUPADO)
			{
				printf("\n|%-11d|%-30s|%-13s|%-30s|%-50s",datosCliente.idCliente,datosCliente.empresa,datosCliente.cuit,datosCliente.direccion,datosCliente.localidad);
				retorno = 0;
			}
	return retorno;
}

int verListaClientes(eCliente datosCliente[], int tam)
{
	int retorno = -1;
	printf("\n|%*s|%*s|%*s|%*s|%*s", -11, "ID CLIENTE", -30, "NOMBRE DE LA EMPRESA",-13,"CUIT",-30 ,"DIRECCION", -30,"LOCALIDAD");
	printf("\n----------------------------------------------------------------------------------------------------------------------");

	for(int i = 0; i < tam; i++)
	{
		if(mostrarUnCliente(datosCliente[i]) == 0)
		{
			retorno = 0;
		}
	}
	return retorno;
}

int buscarIdCliente(eCliente datosCliente[], int tam, int reintentos, int* pIndice)//PUEDE IR EN BIBLIOTECA NEXO
{
	int retorno = -1;
	int idBuscar;

	do
	{
		reintentos--;

		getNumber(&idBuscar, "\nIngrese el ID del cliente: ", "\nError, ID fuera de rango. Ingrese nuevamente: ", 1, tam, 5);

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

int modificarCliente(eCliente datosCliente[], int tam, int reintentos)
{
	int retorno = -1;
	int indiceId;

	if(buscarIdCliente(datosCliente, tam, reintentos, &indiceId) == 0)
	{
		getString("Ingrese la nueva dirección de la empresa: ", datosCliente[indiceId].direccion, 50);
		getString("Ingrese la nueva localidad: ", datosCliente[indiceId].localidad, 50);
		retorno = 0;
	}

	return retorno;
}

int bajaCliente(eCliente datosCliente[], int tam, int reintentos)
{
	int retorno = -1;
	int idBaja;
	char respuesta;

	do
	{
		reintentos--;
		getNumber(&idBaja, "\nIngrese el ID del cliente a dar de baja: ","\nError, ID fuera de rango. Ingrese nuevamente: ", 1,100, 5);

		for(int i = 0; i < tam; i++)
		{
			if(datosCliente[i].isEmpty == OCUPADO && datosCliente[i].idCliente == idBaja)
			{
				printf("\nEsta seguro que desea dar de baja al cliente? (s/n): ");
				fflush(stdin);
				scanf("%c", &respuesta);
				while(!(respuesta == 's' || respuesta == 'n'))
				{
					printf("\nError, ingrese una opción válida: ");
					printf("\nEsta seguro que desea dar de baja al cliente? (s/n)");
					fflush(stdin);
					scanf("%c", &respuesta);
				}

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
		printf("\nNo se ha podido dar de baja, se ha cancelado la operación. ");
		printf("\nPulse una tecla para continuar");
		getchar();
	}

	return retorno;
}

