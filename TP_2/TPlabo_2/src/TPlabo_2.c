/*
 ============================================================================
 Name        : TPlabo_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include "Entidades.h"
#include "ArrayPassenger.h"
#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void) {

	int opcionIngresada;
	int flagCarga = 0;

	setbuf(stdout, NULL);

	initPassengers(passenger, LEN);

	while (!(opcionIngresada == 6)) {

		MostrarMenuPrincipal();

		opcionIngresada = PedirOpcion(6);

		flagCarga = MenuSwitch(opcionIngresada, flagCarga);

	}

	return EXIT_SUCCESS;
}
