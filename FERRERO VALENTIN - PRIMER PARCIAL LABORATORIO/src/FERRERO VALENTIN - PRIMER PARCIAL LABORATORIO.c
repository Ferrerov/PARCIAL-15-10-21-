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

#define TAM_CLIENTES 100
#define TAM_PEDIDOS 1000

int main(void) {
	setbuf(stdout, NULL);

		int respuesta;

        eCliente datosCliente[TAM_CLIENTES] = {
        											{"TRANS-CEREAL", "20432613926" , "Saavedra 1346" , "Villegas", 1,1},
													{"EL TIO", "26432623428" , "Mitre 167" , "Trenque Lauquen", 2,1},
													{"Me piace", "28235463972" , "Llorente 456" , "Cuenca" ,3,1},
													{"EL PUESTITO", "25345214582" , "Oleaga 2345" , "Piedritas" , 4,1}
        								      };
        ePedido datosPedido[TAM_PEDIDOS] = {
													{1,PENDIENTE,4,450,0,0,0,OCUPADO},
													{2,PENDIENTE,2,1000,0,0,0,OCUPADO},
													{3,PENDIENTE,1,150,0,0,0,OCUPADO},
													{4,PENDIENTE,3,3200,0,0,0,OCUPADO}
										   };



        //inicializarClientes(datosCliente, TAM_CLIENTES);
        //inicializarPedidos(datosPedido, TAM_CLIENTES);

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
	    	printf("11. Salir.\n");

	        getNumber(&respuesta, "\nIngrese una opción: ", "\nError, ingrese una opción válida: ", 1, 11, INT_MAX);

	    	int idCliente;
	    	int idPedido;

	    	switch(respuesta){
	    	    case 1:
	    	    	printf("Usted ha seleccionado la opción 1: Dar de alta un cliente.\n");
	    	    	if(cargarDatosCliente(datosCliente, TAM_CLIENTES, &idCliente) == 0)
	    	    	{
	    	    		printf("\nSe ha dado de alta el cliente. \nNumero de ID de cliente: %d", idCliente);
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
	    	    	verListaClientes(datosCliente, TAM_CLIENTES);
	    	    	if(modificarCliente(datosCliente, TAM_CLIENTES, 5)==0)
	    	    	{
	    	    		printf("\nSe ha modificado el cliente deseado. ");
	    	    	}
	    	    	else
	    	    	{
	    	    		printf("\nNo se ha podido modificar al cliente deseado. ");
	    	    	}

	    	    	printf("\nPulse una tecla para continuar");
					getchar();
	    	        break;
	    	    case 3:
	    	    	printf("Usted ha seleccionado la opción 3: Dar de baja un cliente.\n");
	    	    	verListaClientes(datosCliente, TAM_CLIENTES);
	    	    	if(bajaCliente(datosCliente, TAM_CLIENTES, 5) == 0)
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
	    	    	verListaClientes(datosCliente, TAM_CLIENTES);
	    	    	if(cargarPedido(datosPedido, TAM_PEDIDOS, datosCliente, TAM_CLIENTES, &idPedido, 5) == 0)
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
	    	    	if(verListaPedidosPendientes(datosCliente, TAM_CLIENTES, datosPedido, TAM_PEDIDOS) == 0)
	    	    	{
	    	    		procesarResiduos(datosPedido, TAM_PEDIDOS, 5);
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
	    	    	if(informarClientes(datosCliente, TAM_CLIENTES, datosPedido, TAM_PEDIDOS) == 0)
	    	    	{
	    	    		printf("\nLista de clientes:  ");
	    	    	}
	    	    	else
	    	    	{
	    	    		printf("\nNo hay clientes que mostrar.");
	    	    	}
	    	    	break;
	    	    case 7:
	    	    	printf("Usted ha seleccionado la opción 7: Ver pedidos de recoleccion pendientes.\n");
	    	    	if(informarPendientes(datosCliente, TAM_CLIENTES, datosPedido, TAM_PEDIDOS) == 0)
	    	    	{
						printf("\nLista de pedidos de recoleccion pendientes:  ");
					}
					else
					{
						printf("\nNo hay pedidos de recoleccion pendientes.");
					}

	    	    	printf("\nPulse una tecla para continuar");
					getchar();
	    	    	break;
	    	    case 8:
	    	    	printf("Usted ha seleccionado la opción 8: Ver pedidos de recoleccion procesados.\n");
	    	    	if(informarProcesados(datosCliente, TAM_CLIENTES, datosPedido, TAM_PEDIDOS) == 0)
	    	    	{
						printf("\nLista de pedidos de recoleccion procesados:  ");
					}
					else
					{
						printf("\nNo hay pedidos de recoleccion procesados.");
					}

	    	    	printf("\nPulse una tecla para continuar");
					getchar();
	    	    	break;
	    	    case 9:
	    	    	printf("Usted ha seleccionado la opción 9: Ver pedidos de recoleccion por localidad.\n");
	    	    	if(informarPendientesPorLocalidad(datosCliente, TAM_CLIENTES, datosPedido, TAM_PEDIDOS) == 0)
	    	    	{
						printf("\nLista de pedidos de recoleccion por localidad:  ");
					}
					else
					{
						printf("\nNo hay pedidos para mostrar.");
					}

	    	    	printf("\nPulse una tecla para continuar");
					getchar();
	    	    	break;
	    	    case 10:
	    	    	printf("Usted ha seleccionado la opción 10: Ver polipropileno reciclado promedio por cliente.\n");
	    	    	if(informarPolipropilenoPromedio(datosCliente, TAM_CLIENTES, datosPedido, TAM_PEDIDOS) == 0)
	    	    	{
						printf("\nLista de polipropileno reciclado promedio por cliente:  ");
					}
					else
					{
						printf("\nNo hay clientes que mostrar.");
					}

	    	    	printf("\nPulse una tecla para continuar");
					getchar();
	    	    	break;
	    	    case 11:
	    	    	break;
	    	}

	    }while(respuesta != 11);
	return EXIT_SUCCESS;
}
