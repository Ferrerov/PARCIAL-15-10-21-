#ifndef INFORMES_H_
#define INFORMES_H_

#include "ABMclientes.h"
#include "ABMpedidos.h"
#include "input.h"
#include "localidad.h"


/// @fn int ContadorEstadoPedido(int*, int, ePedido[], int)
/// @brief cuenta cuantos pedidos pendientes hay
/// @param pCantidad devuelve por puntero la cantidad de pedidos en estado pendiente
/// @param idCliente envia el id de cliente a buscar
/// @param datosPedido estructura de datos de pedidos
/// @param tamPedido tama?o del array de pedidos
/// @return devuelve 0 si se pudo cargar el array, -1 si no se pudo
int ContadorEstadoPedido(int* pCantidad, int idCliente, int estadoPedido, ePedido datosPedido[], int tamPedido);

/// @fn int informarClientes(eCliente[], int, ePedido[], int)
/// @brief informa todos los clientes con su cantidad de pedidos pendientes
/// @param datosCliente estructura de datos de clientes
/// @param tamCliente tama?o del array de clientes
/// @param datosPedido estructura de datos de pedidos
/// @param tamPedido tama?o del array de pedidos
/// @return devuelve 0 si se pudo cargar el array, -1 si no se pudo
int InformarClientes(eLocalidad datosLocalidades[], eCliente datosCliente[], int tamCliente, ePedido datosPedido[], int tamPedido);

/// @fn int informarPendientes(eCliente[], int, ePedido[], int)
/// @brief informa cada pedido con el cliente que lo realizo
/// @param datosCliente estructura de datos de clientes
/// @param tamCliente tama?o del array de clientes
/// @param datosPedido estructura de datos de pedidos
/// @param tamPedido tama?o del array de pedidos
/// @return devuelve 0 si se pudo cargar el array, -1 si no se pudo
int InformarPendientes(eCliente datosCliente[], int tamCliente, ePedido datosPedido[], int tamPedido);

/// @fn int informarProcesados(eCliente[], int, ePedido[], int)
/// @brief  informa la cantidad de pedidos en estado pendiente con los kilos y cuit y direccion del cliente
/// @param datosCliente estructura de datos de clientes
/// @param tamCliente tama?o del array de clientes
/// @param datosPedido estructura de datos de pedidos
/// @param tamPedido tama?o del array de pedidos
/// @return devuelve 0 si se pudo cargar el array, -1 si no se pudo
int InformarProcesados(eCliente datosCliente[], int tamCliente, ePedido datosPedido[], int tamPedido);

/// @fn int InformarPendientesPorLocalidad(eLocalidad[], eCliente[], int, ePedido[], int)
/// @brief informa la cantidad de pedidos pendientes que hay para una localidad ingresada por el usuario
/// @param localidades estructura de datos de localidades
/// @param datosCliente estructura de datos de clientes
/// @param tamCliente tama?o del array de clientes
/// @param datosPedido estructura de datos de pedidos
/// @param tamPedido tama?o del array de pedidos
/// @return devuelve 0 si se encontro la localidad y -1 si no se enocntro
int InformarPendientesPorLocalidad(eLocalidad localidades[], eCliente datosCliente[], int tamCliente, ePedido datosPedido[], int tamPedido);

/// @fn int promedioPolipropileno(ePedido[], int, int, float*)
/// @brief calcula el polipropileno promedio por cliente
/// @param datosPedido estructura de datos de pedidos
/// @param tamPedido tama?o del array de pedidos
/// @param idCliente envia el idCliente a realcionar con los pedidos
/// @param pPromedio devuelve el promedio de kilos por cliente
/// @return devuelve 0 si se pudo cargar el array, -1 si no se pudo
int PromedioPolipropileno(ePedido datosPedido[], int tamPedido, int idCliente, float* pPromedio);

/// @fn int informarPolipropilenoPromedio(eCliente[], int, ePedido[], int)
/// @brief informa el polipropileno promedio por cliente
/// @param datosCliente estructura de datos de clientes
/// @param tamCliente tama?o del array de clientes
/// @param datosPedido tama?o del array de pedidos
/// @param tamPedido tama?o del array de pedidos
/// @return devuelve 0 si se pudo cargar el array, -1 si no se pudo
int InformarPolipropilenoPromedio(eCliente datosCliente[], int tamCliente, ePedido datosPedido[], int tamPedido);

/// @fn int BuscarMaxEstadoPedido(int*, int*, int, eCliente[], int, ePedido[], int)
/// @brief busca el cliente con la mayor cantidad de pedidos en un estado especifico
/// @param pIndice devuelve como puntero el indice del array de cliente que mas pedidos tiene
/// @param pCantidad devuelve como puntero la cantidad de pedidos que resulto ser la mayor
/// @param estadoPedido se?ala que estado de pedido se busca, si PENDIENTE o COMPLETADO
/// @param datosCliente estructura de datos de clientes
/// @param tamCliente tama?o del array de clientes
/// @param datosPedido tama?o del array de pedidos
/// @param tamPedidotama?o del array de pedidos
/// @return devuelve 0 si se encontro un maximo y -1 si no se encontro
int BuscarMaxEstadoPedido(int* pIndice, int* pCantidad, int estadoPedido,eCliente datosCliente[], int tamCliente, ePedido datosPedido[], int tamPedido);;

/// @fn int InformarClienteMasPendientes(eCliente[], int, ePedido[], int)
/// @brief imprime en pantalla el cliente con mas pedidos pendientes
/// @param datosCliente estructura de datos de clientes
/// @param tamCliente tama?o del array de clientes
/// @param datosPedido tama?o del array de pedidos
/// @param tamPedido tama?o del array de pedidos
/// @return devuelve 0 si hay clientes que informar y -1 si no los hay
int InformarClienteMasPendientes(eCliente datosCliente[], int tamCliente, ePedido datosPedido[], int tamPedido);

/// @fn int InformarClienteMasCompletados(eCliente[], int, ePedido[], int)
/// @brief imprime en pantalla el cliente con mas pedidos completados
/// @param datosCliente estructura de datos de clientes
/// @param tamCliente tama?o del array de clientes
/// @param datosPedido tama?o del array de pedidos
/// @param tamPedido tama?o del array de pedidos
/// @return devuelve 0 si hay clientes que informar y -1 si no los hay
int InformarClienteMasCompletados(eCliente datosCliente[], int tamCliente, ePedido datosPedido[], int tamPedido);

#endif /* INFORMES_H_ */
