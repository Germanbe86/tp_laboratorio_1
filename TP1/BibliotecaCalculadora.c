/*
 * BibliotecaCalculadora.c
 *
 *  Created on: Sep 25, 2021
 *      Author: gb
 */

#include "BibliotecaCalculadora.h"
#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


/// \fn: void MenuPrincipal(float, float)
/// \brief: Le pasamos dos flotantes para que los cargue en el menu A=x  B=y
/// \param A: Es el primer operando
/// \param B: Es el segundo operando
/// No devuelve nada. Esta hecha, mas que nada, para mostrar el menu de opciones
void MenuPrincipal(float A, float B) {

	printf("\n ---------------------------------------------\n ");
	printf("\n   Introduzca una opcion (del 1 al 5)\n ");
	printf("\n   1. Ingresar 1er operando (%.2f=x)", A);
	printf("\n   2. Ingresar 2do operando (%.2f=y)", B);
	printf("\n   3. Calcular todas las operaciones.");
	printf("\n   4. Informar resultados.");
	printf("\n   5. Salir\n");
	printf("\n ---------------------------------------------\n ");

}
/// \fn: float CalcularSuma(float, float)
/// \brief: Suma dos numeros flotantes que le pasamos por parametro
/// \param A: Primer numero ingresado
/// \param B: Segundo Numero Ingreasado
/// \return: Devuelve un flotante resultante de la suma de A y B
float CalcularSuma(float A, float B) {

	float suma;

	suma = A + B;

	return suma;

}
/// \fn: float CalcularResta(float, float)
/// \brief: Resta dos numeros flotantes que le pasamos por parametro
/// \param A: Primer numero ingresado
/// \param B: Segundo Numero Ingreasado
/// \return: Devuelve un flotante resultante de la resta entre A y B
float CalcularResta(float A, float B) {

	float resta;

	resta = A - B;

	return resta;
}

/// \fn: float CalcularDivision(float, float)
/// \brief: Divide dos numeros flotantes que le pasamos por parametro
/// \param A:Dividendo
/// \param B:Divisor
/// \return:Devuelve un flotante resultante de la division entre A y B
float CalcularDivision(float A, float B) {

	float division;

	if (B == 0) {    // Como ninguna division entre dos numeros puede dar cero, usamos este numero para avisar que ingresaron un 0 en el divisor

		division = 0;

	} else {

		division = A / B;
	}
	return division;
}

/// \fn float CalcularMultiplicacion(float, float)
/// \brief: Divide dos numeros flotantes que le pasamos por parametro
/// \param A:Primer numero ingresado
/// \param B:Segundo Numero Ingreasado
/// \return: Devuelve un flotante resultante de la multiplicacion entre A y B
float CalcularMultiplicacion(float A, float B) {

	float multiplicacion;

	multiplicacion = A * B;

	return multiplicacion;
}

/// \fn double CalcularFactorial(int)
/// \brief:Calcula el factorial del numero pasado por parametro
/// \param numero: Numero pasado desde el main
/// \return: Devuelve el factorial del numero ingresado desde el main
double CalcularFactorial(int numero) {

	double factorial;

	if (numero == 0) {
		factorial = 1;
	} else {
		factorial = numero * CalcularFactorial(numero - 1);
	}

	return factorial;
}


