#include "hardcodeo.h"

char empresa[12][50] =
		{
		"Don Rosendo",
		"Transporte El Tio",
		"El Cruce",
		"Chirizola SA",
		"Zamperetti",
		"Trans. Cereal SA",
		"Graros",
		"Cliba",
		"Don Isidro",
		"Repartos Monti",
		"Cerezo",
		"ACA"};

char cuit[12][13] =
		{
		"23300956289",
		"20076327638",
		"20108720779",
		"20261333008",
		"20076791172",
		"20920347690",
		"20003704050",
		"20164427901",
		"20100329779",
		"24179177587",
		"20064966422",
		"20374204972"};

char direccion[12][50] =
		{
		"Mitre 3776",
		"Balbín 3765",
		"Garay 489",
		"Cosentino 617",
		"Av 25 De Mayo 205",
		"D'Onofrio 158",
		"Sarmiento Oeste 474",
		"Italia 150",
		"Ameghino 245",
		"Castelli 1855",
		"Gral Paz 5445",
		"Belgrano 1222"};

char localidad[6][50] =
		{
		"Trenque Lauquen",
		"Piedritas",
		"General Villegas",
		"Cuenca",
		"Bunge",
		"Charlone"
		};

int idLocalidad[12] = {1,4,2,5,3,6,1,3,1,5,6,1};
int idCliente[20] = {1,2,5,2,5,3,6,7,2,4,2,9,11,4,2,8,6,2,1,3};
float kilosTotales[20] = {150,250,5460,1200,750,300,650,200,550,100,275,970,2900,1800,500,900,850,1350,1500,1600};

void hardcodearLocalidad(eLocalidad datosLocalidad[], int tamLocalidad)
{
	for(int i=0; i<tamLocalidad; i++)
	{
		datosLocalidad[i].idLocalidad = i+1;
		strcpy(datosLocalidad[i].localidad,localidad[i]);
		datosLocalidad[i].isEmpty = OCUPADO;
	}
}

void hardcodearClientes(eCliente datosCliente[], int tamClientes)
{
	for(int i=0; i<tamClientes; i++)
	{
		datosCliente[i].idCliente = i+1;
		strcpy(datosCliente[i].empresa,empresa[i]);
		strcpy(datosCliente[i].cuit,cuit[i]);
		strcpy(datosCliente[i].direccion,direccion[i]);
		datosCliente[i].idLocalidad = idLocalidad[i];
		datosCliente[i].isEmpty = OCUPADO;
	}
}

void hardcodearPedidos(ePedido datosPedido[], int tamPedidos)
{
	for(int i=0; i<tamPedidos; i++)
	{
		datosPedido[i].idPedido = i+1;
		datosPedido[i].estadoPedido = PENDIENTE;
		datosPedido[i].idCliente = idCliente[i];
		datosPedido[i].idPedido = i+1;
		datosPedido[i].kilosTotales = kilosTotales[i];
		datosPedido[i].isEmpty = OCUPADO;
	}
}


