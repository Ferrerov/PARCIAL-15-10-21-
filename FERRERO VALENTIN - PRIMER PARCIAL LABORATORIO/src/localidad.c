#include "localidad.h"

void InicializarLocalidades(eLocalidad localidades[], int tam)
{
	for(int i = 0; i<tam; i++)
	{
		localidades[i].isEmpty = LIBRE;
	}
}

int BuscarLocalidad(int* idLocalidad, char localidad[], eLocalidad localidades[], int tamLocalidades)
{
	int retorno = -1;

	for(int i = 0; i < tamLocalidades; i++)
	{
		if(localidades[i].isEmpty == OCUPADO && strcmp(localidad, localidades[i].localidad) == 0)
		{
			*idLocalidad = localidades[i].idLocalidad;
			retorno = 0;
			break;
		}
	}

	return retorno;
}
int NuevaLocalidad(int* idLocalidad, eLocalidad localidades[], int tamLocalidades)
{
	int retorno = -1;
	char auxLocalidad[50];
	int auxIdLocalidad;

	GetString("\nIngrese la localidad: ", auxLocalidad);
	if(BuscarLocalidad(&auxIdLocalidad, auxLocalidad, localidades,tamLocalidades) != 0)
	{
		for(int i = 0; i < tamLocalidades; i++)
		{
			if(localidades[i].isEmpty == LIBRE)
			{
				strcpy(localidades[i].localidad, auxLocalidad);
				localidades[i].idLocalidad = i;
				*idLocalidad = localidades[i].idLocalidad;
				localidades[i].isEmpty = OCUPADO;
				retorno = 0;
				break;
			}
		}
	}
	else
	{
		*idLocalidad = auxIdLocalidad;
		retorno = 0;
	}
	return retorno;
}

void VerLocalidadPorId(char localidad[], eLocalidad localidades[], int tamLocalidad, int idLocalidad)
{
	for(int i=0; i<tamLocalidad; i++)
	{
		if(localidades[i].isEmpty == OCUPADO && localidades[i].idLocalidad == idLocalidad)
		{
			strcpy(localidad, localidades[i].localidad);
		}
	}
}

int VerUnaLocalidad(eLocalidad localidad[], int tamLocalidades, int idLocalidad)
{
	int retorno = -1;

	for(int i = 0; i < tamLocalidades; i++)
	{
		if(localidad[i].isEmpty == OCUPADO && localidad[i].idLocalidad == idLocalidad)
		{
			printf("\n|%*d|%*s|", -11, localidad[i].idLocalidad, -20,  localidad[i].localidad);
			retorno = 0;
			break;
		}
	}
	return retorno;
}

int VerListadoDeLocalidades(eLocalidad localidad[], int tamLocalidad)
{
	int retorno = -1;

	for(int i=0; i < tamLocalidad; i++)
	{
		if(VerUnaLocalidad(localidad, tamLocalidad, localidad[i].idLocalidad) == 0)
		{
			retorno = 0;
		}
	}
	return retorno;
}


