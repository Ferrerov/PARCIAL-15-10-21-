#ifndef ABMPEDIDOS_H_
#define ABMPEDIDOS_H_
#include "input.h"
#include "ABMclientes.h"

#define PENDIENTE 0
#define COMPLETADO 1

typedef struct
{
	int idPedido;
	int estadoPedido;
	int idCliente;
	float kilosTotales;
	float HDPE;
	float LDPE;
	float PP;
	int isEmpty;
}ePedido;

/// @fn void inicializarPedidos(ePedido[], int)
/// @brief inicializa el array de pedidos, estableciendo isEmpty en LIBRE
/// @param datosPedido estructura de datos de pedidos
/// @param tam tamaño del array de pedidos
void InicializarPedidos(ePedido datosPedido[], int tam);

/// @fn int cargarPedido(ePedido[], int, eCliente[], int, int*, int)
/// @brief da de alta un pedido
/// @param datosPedido estructura de datos de pedidos
/// @param tamPedidos tamaño del array de pedidos
/// @param datosCliente estructura de datos de clientes
/// @param tamCliente tamaño del array de clientes
/// @param pIdPedido devuelve el id de pedido generado
/// @param reintentos cantidad de oportunidades que se le dan al usuario para ingresar los datos
/// @return devuelve 0 si se pudo cargar el array, -1 si no se pudo
int CargarPedido( ePedido datosPedido[], int tamPedidos, eCliente datosCliente[], int tamCliente, int* pIdPedido, int reintentos);

/// @fn int verListaPedidosPendientes(eCliente[], int, ePedido[], int)
/// @brief  muestra todos los pedidos pendientes
/// @param datosCliente
/// @param tamCliente tamaño del array de clientes
/// @param datosPedido estructura de datos de pedidos
/// @param tamPedido tamaño del array de pedidos
/// @return devuelve 0 si se pudo cargar el array, -1 si no se pudo
int VerListaPedidosPendientes(eCliente datosCliente[], int tamCliente, ePedido datosPedido[], int tamPedido);

/// @fn int verUnPedidoPendiente(ePedido[], int, int)
/// @brief  muestra un pedido pendiente en especifico
/// @param datosPedido estructura de datos de pedidos
/// @param tamPedido tamaño del array de pedidos
/// @param idCliente recibe el idCliente
/// @return devuelve 0 si se pudo cargar el array, -1 si no se pudo
int VerUnPedidoPendiente(ePedido datosPedido[], int tamPedido, int idCliente);

/// @fn int buscarIdPedido(ePedido[], int, int, int*)
/// @brief busca un id de pedido
/// @param datosPedido estructura de datos de pedidos
/// @param tam tamaño del array de pedido
/// @param reintentos cantidad de oportunidades que se le dan al usuario para ingresar los datos
/// @param pIndice devuelve la posicion del array en donde se encuentra el idPedido
/// @return devuelve 0 si se pudo cargar el array, -1 si no se pudo
int BuscarIdPedido(ePedido datosPedido[], int tam, int reintentos, int* pIndice);

/// @fn int procesarResiduos(ePedido[], int, int)
/// @brief procesa los residuos
/// @param datosPedido estructura de datos de pedidos
/// @param tamPedido tamaño del array de pedidos
/// @param reintentos cantidad de oportunidades que se le dan al usuario para ingresar los datos
/// @return devuelve 0 si se pudo cargar el array, -1 si no se pudo
int ProcesarResiduos(ePedido datosPedido[], int tamPedido, int reintentos);

#endif /* ABMPEDIDOS_H_ */
