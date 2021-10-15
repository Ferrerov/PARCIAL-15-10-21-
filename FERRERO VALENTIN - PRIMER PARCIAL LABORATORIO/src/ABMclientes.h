#ifndef ABMCLIENTES_H_
#define ABMCLIENTES_H_

#include "input.h"

#define LIBRE 0
#define OCUPADO 1

typedef struct
{
	char empresa[50];
	char cuit[13];
	char direccion[50];
	char localidad[50];
	int idCliente;
	int isEmpty;
}eCliente;

/// @fn void inicializarClientes(eCliente[], int)
/// @brief inicializa el array de clientes, poniendo en "LIBRE" el isEmpty
/// @param datosCliente estructura de datos de los clientes
/// @param tam  tamaño del array de clientes
void inicializarClientes(eCliente datosCliente[],int tam);

/// @fn int cargarDatosCliente(eCliente[], int, int*)
/// @brief da de alta un cliente
/// @param datosCliente estructura de datos de los clientes
/// @param tam  tamaño del array de clientes
/// @param pIdCliente devuelve mediante un puntero al id de cliente generado
/// @return devuelve 0 si se pudo cargar el array, -1 si no se pudo
int cargarDatosCliente(eCliente datosCliente[], int tam, int* pIdCliente);

/// @fn int mostrarUnCliente(eCliente)
/// @brief muestra en pantalla los datos de un cliente
/// @param datosCliente estructura de datos de los clientes
/// @return devuelve 0 si se pudo cargar el array, -1 si no se pudo
int mostrarUnCliente(eCliente datosCliente);

/// @fn int verListaClientes(eCliente[], int)
/// @brief muestra todos los datos de todos los clientes
/// @param datosCliente estructura de datos de los clientes
/// @param tam  tamaño del array de clientes
/// @return devuelve 0 si se pudo cargar el array, -1 si no se pudo
int verListaClientes(eCliente datosCliente[], int tam);

/// @fn int buscarIdCliente(eCliente[], int, int, int*)
/// @brief busca el id del cliente
/// @param datosCliente estructura de datos de los clientes
/// @param tam  tamaño del array de clientes
/// @param reintentos cantidad de oportunidades que se le dan al usuario para ingresar los datos
/// @param pIndice devuelve la posicion del array en donde se encuentra el idcliente
/// @return devuelve 0 si se pudo cargar el array, -1 si no se pudo
int buscarIdCliente(eCliente datosCliente[], int tam, int reintentos, int* pIndice);

/// @fn int modificarCliente(eCliente[], int, int)
/// @brief modifica datos del cliente
/// @param datosCliente estructura de datos de los clientes
/// @param tam  tamaño del array de clientes
/// @param reintentos cantidad de oportunidades que se le dan al usuario para ingresar los datos
/// @return devuelve 0 si se pudo cargar el array, -1 si no se pudo
int modificarCliente(eCliente datosCliente[], int tam, int reintentos);

/// @fn int bajaCliente(eCliente[], int, int)
/// @brief da de baja un cliente (isEmpty en LIBRE)
/// @param datosCliente estructura de datos de los clientes
/// @param tam  tamaño del array de clientes
/// @param reintentos cantidad de oportunidades que se le dan al usuario para ingresar los datos
/// @returndevuelve 0 si se pudo cargar el array, -1 si no se pudo
int bajaCliente(eCliente datosCliente[], int tam, int reintentos);

#endif /* ABMCLIENTES_H_ */
