#ifndef INPUT_H_
#define INPUT_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>

/// @fn void getString(char[], char[], int)
/// @brief solicita al usuario una cadena de caracteres
/// @param message
/// @param string
/// @param tam
void getString(char message[],char string[],int tam);

/// @fn int getNumber(int*, char[], char[], int, int, int)
/// @brief solicita al usuario un numero entero
/// @param pResult devuelve como puntero el numero solicitado
/// @param message mensaje que pide el numero
/// @param errorMessage mensaje en caso de que el numero sea erroneo
/// @param min numero minimo a pedir
/// @param max numero maximo a pedir
/// @param retries cantidad de oportunidades que se le dan al usuario para ingresar los datos
/// @return devuelve 0 si se pudo cargar el array, -1 si no se pudo
int getNumber(int* pResult, char message[], char errorMessage[], int min, int max, int retries);

/// @fn int stringValidation(int*)
/// @brief  si la cadena de caracteres no tiene digitos, lo convierte a entero
/// @param pResult devuelve el numero entero
/// @return devuelve 0 si se pudo cargar el array, -1 si no se pudo
int stringValidation(int* pResult);

/// @fn int numberValidation(char[])
/// @brief  verifica si la cadena de caracteres tiene algun digito invalido
/// @param string devuelve la cadena de caracteres
/// @return devuelve 0 si se pudo cargar el array, -1 si no se pudo
int numberValidation(char string[]);

#endif /* INPUT_H_ */
