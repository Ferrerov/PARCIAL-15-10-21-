/*
 ============================================================================
 Name        : FERRERO.c
 Author      : Ferrero Valentin
 Version     :
 Copyright   : 
 Description : Resolución primer parcial de Laboratorio de Computacion I
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "ABMclientes.h"
#include "ABMpedidos.h"
#include "informes.h"
#include "localidad.h"
#include "hardcodeo.h"

#define TAM_CLIENTES 100
#define TAM_PEDIDOS 1000

int main(void) {
	setbuf(stdout, NULL);

		int respuesta;
    	int flagCarga = -1;

        eCliente datosCliente[TAM_CLIENTES];/* = {
        											{"TRANS-CEREAL", "20432613926" , "Saavedra 1346" , "Villegas", 1,1},
													{"EL TIO", "26432623428" , "Mitre 167" , "Trenque Lauquen", 2,1},
													{"Me piace", "28235463972" , "Llorente 456" , "Cuenca" ,3,1},
													{"EL PUESTITO", "25345214582" , "Oleaga 2345" , "Piedritas" , 4,1}
        								      };*/
        ePedido datosPedido[TAM_PEDIDOS];/* = {
													{1,PENDIENTE,4,450,0,0,0,OCUPADO},
													{2,PENDIENTE,2,1000,0,0,0,OCUPADO},
													{3,PENDIENTE,1,150,0,0,0,OCUPADO},
													{4,PENDIENTE,3,3200,0,0,0,OCUPADO}
										   };*/
        eLocalidad datosLocalidad[TAM_CLIENTES];

        HardcodearClientes(datosCliente, 12);
        HardcodearLocalidad(datosLocalidad, 6);
        HardcodearPedidos(datosPedido, 20);

        //InicializarClientes(datosCliente, TAM_CLIENTES);
        //InicializarPedidos(datosPedido, TAM_PEDIDOS);
        //InicializarLocalidades(datosLocalidad, TAM_CLIENTES);

	    do{
	    	printf("\n1. Dar de alta un cliente.\n");
	    	printf("2. Modificar datos de un cliente.\n");
	    	printf("3. Dar de baja un cliente.\n");
	    	printf("4. Crear pedido de recolección.\n");
	    	printf("5. Procesar residuos por pedido.\n");
	    	printf("6. Ver datos de clientes.\n");
	    	printf("7. Ver pedidos de recoleccion pendientes.\n");
	    	printf("8. Ver pedidos de recoleccion procesados.\n");
	    	printf("9. Ver pedidos de recoleccion por localidad.\n");
	    	printf("10. Ver polipropileno reciclado promedio por cliente.\n");
	    	printf("11. Ver cliente con mas pedidos pendientes.\n");
	    	printf("12. Ver cliente con mas pedidos completados.\n");
	    	printf("13. Salir.\n");

	    	GetInt(&respuesta, "\nIngrese una opción: ", "\nError, ingrese una opción válida: ", 1, 13, INT_MAX);

	    	int idCliente;
	    	int idPedido;

	    	switch(respuesta){
	    	    case 1:
	    	    	printf("Usted ha seleccionado la opción 1: Dar de alta un cliente.\n");
	    	    	if(CargarDatosCliente(datosCliente, datosLocalidad, TAM_CLIENTES, &idCliente) == 0)
	    	    	{
	    	    		printf("\nSe ha dado de alta el cliente. \nNumero de ID de cliente: %d", idCliente);
	    	    		flagCarga = 0;
	    	    	}
	    	    	else
	    	    	{
	    	    		printf("\nNo se ha podido dar de alta el cliente.");
	    	    	}

	    	    	printf("\nPulse una tecla para continuar");
	    	    	getchar();
	    	        break;
	    	    case 2:
	    	    	printf("Usted ha seleccionado la opción 2: Modificar datos de un cliente.\n");
	    	    	VerListaClientes(datosCliente, datosLocalidad, TAM_CLIENTES);
	    	    	if(flagCarga == 0 && ModificarCliente(datosCliente, datosLocalidad, TAM_CLIENTES, 5)==0)
	    	    	{
	    	    		printf("\nSe ha modificado el cliente deseado. ");
	    	    	}
	    	    	else
	    	    	{
	    	    		printf("\nNo se ha podido modificar. ");
	    	    	}

	    	    	printf("\nPulse una tecla para continuar");
					getchar();
	    	        break;
	    	    case 3:
	    	    	printf("Usted ha seleccionado la opción 3: Dar de baja un cliente.\n");
	    	    	VerListaClientes(datosCliente, datosLocalidad, TAM_CLIENTES);
	    	    	if(flagCarga == 0 && BajaCliente(datosCliente, TAM_CLIENTES, 5) == 0)
	    	    	{
	    	    		printf("\nSe ha dado de baja el cliente deseado. ");
	    	    	}
	    	    	else
	    	    	{
	    	    		printf("\nNo se ha podido dar de baja al cliente deseado. ");
	    	    	}

	    	    	printf("\nPulse una tecla para continuar");
					getchar();
	    	    	break;
	    	    case 4:
	    	    	printf("Usted ha seleccionado la opción 4: Crear pedido de recolección.\n");
	    	    	VerListaClientes(datosCliente, datosLocalidad, TAM_CLIENTES);
	    	    	if(flagCarga == 0 && CargarPedido(datosPedido, TAM_PEDIDOS, datosCliente, TAM_CLIENTES, &idPedido, 5) == 0)
					{
						printf("\nSe ha cargado el pedido. \nNumero de ID de pedido: %d", idPedido);
					}
					else
					{
						printf("\nNo se ha podido cargar el pedido.");
					}

	    	    	printf("\nPulse una tecla para continuar");
					getchar();
	    	    	break;
	    	    case 5:
	    	    	printf("Usted ha seleccionado la opción 5: Procesar residuos por pedido.\n");
	    	    	if(flagCarga == 0 && VerListaPedidosPendientes(datosCliente, TAM_CLIENTES, datosPedido, TAM_PEDIDOS) == 0)
	    	    	{
	    	    		ProcesarResiduos(datosPedido, TAM_PEDIDOS, 5);
	    	    	}
	    	    	else
	    	    	{
	    	    		printf("\nNo hay pedidos para procesar. ");
	    	    	}

	    	    	printf("\nPulse una tecla para continuar");
					getchar();
	    	    	break;
	    	    case 6:
	    	    	printf("Usted ha seleccionado la opción 6: Ver datos de clientes.\n");
	    	    	if(flagCarga != 0 || InformarClientes(datosLocalidad, datosCliente, TAM_CLIENTES, datosPedido, TAM_PEDIDOS) != 0)
	    	    	{
	    	    		printf("\nNo hay clientes que mostrar.");
	    	    	}
	    	    	break;
	    	    case 7:
	    	    	printf("Usted ha seleccionado la opción 7: Ver pedidos de recoleccion pendientes.\n");
	    	    	if(flagCarga != 0 || InformarPendientes(datosCliente, TAM_CLIENTES, datosPedido, TAM_PEDIDOS) != 0)
	    	    	{
						printf("\nNo hay pedidos de recoleccion pendientes.");
					}

	    	    	printf("\nPulse una tecla para continuar");
					getchar();
	    	    	break;
	    	    case 8:
	    	    	printf("Usted ha seleccionado la opción 8: Ver pedidos de recoleccion procesados.\n");
	    	    	if(flagCarga != 0 || InformarProcesados(datosCliente, TAM_CLIENTES, datosPedido, TAM_PEDIDOS) != 0)
	    	    	{
						printf("\nNo hay pedidos de recoleccion procesados.");
					}

	    	    	printf("\nPulse una tecla para continuar");
					getchar();
	    	    	break;
	    	    case 9:
	    	    	printf("Usted ha seleccionado la opción 9: Ver pedidos de recoleccion por localidad.\n");
	    	    	if(flagCarga != 0 || InformarPendientesPorLocalidad(datosLocalidad, datosCliente, TAM_CLIENTES, datosPedido, TAM_PEDIDOS) != 0)
	    	    	{
						printf("\nNo hay pedidos para mostrar.");
					}

	    	    	printf("\nPulse una tecla para continuar");
					getchar();
	    	    	break;
	    	    case 10:
	    	    	printf("Usted ha seleccionado la opción 10: Ver polipropileno reciclado promedio por cliente.\n");
	    	    	if(flagCarga != 0 || InformarPolipropilenoPromedio(datosCliente, TAM_CLIENTES, datosPedido, TAM_PEDIDOS) != 0)
	    	    	{
						printf("\nNo hay clientes que mostrar.");
					}

	    	    	printf("\nPulse una tecla para continuar");
					getchar();
	    	    	break;
	    	    case 11:
	    	    	printf("Usted ha seleccionado la opción 11: Ver cliente con mas pedidos pendientes.\n");
	    	    	if(flagCarga != 0 || InformarClienteMasPendientes(datosCliente, TAM_CLIENTES, datosPedido, TAM_PEDIDOS) != 0)
	    	    	{
	    	    		printf("\nNo hay clientes con pedidos pendientes que mostrar.");
	    	    	}
	    	    	break;
	    	    case 12:
	    	    	printf("Usted ha seleccionado la opción 12: Ver cliente con mas pedidos pendientes.\n");
	    	    	if(flagCarga != 0 || InformarClienteMasCompletados(datosCliente, TAM_CLIENTES, datosPedido, TAM_PEDIDOS) != 0)
					{
	    	    		printf("\nNo hay clientes con pedidos completos que mostrar.");
	    	    	}
					break;
	    	    case 13:
					break;
	    	}

	    }while(respuesta != 13);
	return EXIT_SUCCESS;
}
