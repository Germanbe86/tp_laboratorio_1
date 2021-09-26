/*
 ============================================================================
 Name        : TP1.c
 Author      : German Romeo Belli
 Version     :
 Copyright   : Your copyright notice
 Division    : E
 ============================================================================
 */
#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "BibliotecaCalculadora.h"

int main(void) {

	setbuf(stdout, NULL);

	int flag;
	int opcion;
	float numeroA;
	float numeroB;
	float resultadoSuma;
	float resultadoResta;
	float resultadoMultiplicacion;
	float resultadoDivision;
	double resultadoFactorialA;
	double resultadoFactorialB;

	flag = 1;

	// Saludo al usuario

	printf("\nBienvenido a la Calculadora\n");

	//Pongo en cero los numeros para mostrarlos asi en el menu de opciones.
	numeroA = 0;
	numeroB = 0;

	while (flag == 1) {      //Se crea este punto para que el programa vuelva a correr desde aca cuando lo necesitemos(mostrar menu, etc)
		do {
			MenuPrincipal(numeroA, numeroB);

			scanf("%d", &opcion);  // Guardo en la variable "opcion" lo ingresado por teclado


		} while ((opcion < 1) || (opcion > 5));     // Aca limito el ingreso del usuario

		switch (opcion) {
		case 1:
			printf("\n   Ingresar 1er operando\n ");
			scanf("%f", &numeroA);

			flag = 1; // volvemos a la linea 42 para volver a mostrar el menu
			break;

		case 2:
			printf("\n   Ingresar 2do operando\n ");
			scanf("%f", &numeroB);

			flag = 1;

			break;

		case 3:
			resultadoSuma = CalcularSuma(numeroA, numeroB);      // le cargo a las variables creadas en el main lo que
			resultadoResta = CalcularResta(numeroA, numeroB);   // me devuelven las funciones para luego imprimirlas por pantalla
			resultadoDivision = CalcularDivision(numeroA, numeroB);
			resultadoMultiplicacion = CalcularMultiplicacion(numeroA, numeroB);
			resultadoFactorialA = CalcularFactorial(numeroA);
			resultadoFactorialB = CalcularFactorial(numeroB);

			printf("\nSe Calcularon todas las operaciones\n ");          // Avisamos al usuario lo que hizo el programa
			printf(	"\nSi desea ver los resultados seleccione la opcion 4 del menu...\n\n");

			flag = 1;

			break;

		case 4:

			printf("\n El resultado de %.2f + %.2f es: %.2f", numeroA, numeroB,   // Imprimimos los numeros ingresados y devuelto por la funcion
					resultadoSuma);													// el %.2f es para redondear el flotante solo a 2 decimales.
			printf("\n El resultado de %.2f - %.2f es: %.2f", numeroA, numeroB,
					resultadoResta);

			if (resultadoDivision == 0) {          // usamos este metodo en la funcion (ver funcion en biblioteca) ya que ninguna division entre 2 numeros puede dar cero
				printf("\n No se puede dividir por cero");
			} else {
				printf("\n El resultado de %.2f / %.2f es: %.2f", numeroA, numeroB,
						resultadoDivision);
			}
			printf("\n El resultado de %.2f * %.2f es: %.2f", numeroA, numeroB,
					resultadoMultiplicacion);
			printf("\n El factorial de %.2f es: %.2f", numeroA,
					resultadoFactorialA);
			printf("\n El factorial de %.2f es: %.2f\n\n", numeroB,
					resultadoFactorialB);

			flag = 1;

			break;

		case 5:

			printf("\n   ---- Se Termino el programa ---- ");  // Avisamos que se termino el programa
			flag = 0;
			break;
		}

	}

	return EXIT_SUCCESS;
}
