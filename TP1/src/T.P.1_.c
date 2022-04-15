/*************************************************************
 German R. Belli
 --Division 1ºF--

 T.P.:1
 *************************************************************/

#include "Libreria.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);

	// Declaro las variables que voy a utilizar. Algunas fueron inicializadas para realizar validaciones.
	int opcionIngresada;
	float kilometros = 0;
	float precioVueloAerolineas = 0;
	float precioVueloLatam = 0;
	char empresaDeVuelo;
	float debitoAerolineas = 0;
	float creditoAerolineas;
	float bitcoinAerolineas;
	float precioPorKilometroAerolineas;
	float debitoLatam = 0;
	float creditoLatam;
	float bitcoinLatam;
	float precioPorKilometroLatam;
	float diferencia;

	while (!(opcionIngresada == 6)) { //Mientras que la opcion ingresada NO sea 6 hacer lo siguiente:

		MostrarMenuPrincipal(precioVueloAerolineas, precioVueloLatam, // Muestra Menu Principal por pantalla
				kilometros);
		opcionIngresada = PedirOpcion(); // Carga la variable 'opcionIngresada' con lo que devuelve la funcion validado

		switch (opcionIngresada) { //Condiciona el programa segun lo que se ingresa

		case 1:			 // Si la variable 'opcionIngresada' es = a '1': hacer lo siguiente:

			kilometros = IngresarKilometros(kilometros); // carga la variable 'kilometros' con un unmero validado por la funcion.
			break;

		case 2:
			//Muestro Menu de opcion 2
			do {
				printf("\n********************************************");
				printf("\nPrecio cargado de Aerolineas: $%.2f\n",
						precioVueloAerolineas);
				printf("Precio cargado de Latam: $%.2f", precioVueloLatam);

				empresaDeVuelo = MostrarMenuOpcion2();

				switch (empresaDeVuelo) {

				case 'y':
					precioVueloAerolineas = IngresarPrecioVuelo();

					break;

				case 'z':
					precioVueloLatam = IngresarPrecioVuelo();

					break;
				}
			} while (!(empresaDeVuelo == 'q')); //Mientras no se ingrese 'q' mostrar el menu de la Opcion 2

			break;

		case 3:

			// Valido para que ingresen primero los datos necesarios de las 2 primeras opciones del menu Principal.
			if (!((kilometros == 0) || (precioVueloAerolineas == 0)
					|| (precioVueloLatam == 0))) {

				debitoAerolineas = CalcularDebito(precioVueloAerolineas);
				creditoAerolineas = CalcularCredito(precioVueloAerolineas);
				bitcoinAerolineas = CalcularBitcoin(precioVueloAerolineas);
				precioPorKilometroAerolineas = CalcularPrecioPorKilometro(
						precioVueloAerolineas, kilometros);

				debitoLatam = CalcularDebito(precioVueloLatam);
				creditoLatam = CalcularCredito(precioVueloLatam);
				bitcoinLatam = CalcularBitcoin(precioVueloLatam);
				precioPorKilometroLatam = CalcularPrecioPorKilometro(
						precioVueloLatam, kilometros);
				diferencia = CalcularDiferencia(precioVueloAerolineas,
						precioVueloLatam);

				printf(	"---------------------------------------------------------");
				printf("\n\n Se han calculado los costos Correctamente. \n\n");
				printf(	"---------------------------------------------------------\n\n");

			} else {  //Muestro mensaje de error.
				printf("------------------------------------------------------------------");
				printf("\nPrimero debe ingresar cantidad de kilometros en la Opcion 1."
								"\nTambien los precios de los vuelos en la Opcion2.\n");
				printf("------------------------------------------------------------------\n\n");
			}

			break;

		case 4:
			// Valido para que ingresen primero los datos correspondientes a las primeras 2 opciones del menu principal
			// Verificando las variables debito me aseguro que se hayan calculado los costos mediante la Opcion 3.

			if (!((kilometros == 0) || (precioVueloAerolineas == 0)
					|| (precioVueloLatam == 0) || (debitoLatam == 0)
					|| (debitoAerolineas == 0))) {

				//Llamo a la funcion que muestra lo calculado por pantalla pasandole los datos correspondientes.
				MostrarCostos(debitoAerolineas, debitoLatam, creditoAerolineas,
						creditoLatam, bitcoinAerolineas, bitcoinLatam,
						precioPorKilometroAerolineas, precioPorKilometroLatam,
						diferencia, kilometros, precioVueloAerolineas,
						precioVueloLatam);

				//Muestro mensaje de error.
			} else {
				printf("------------------------------------------------------------------");
				printf("\nPrimero debe Calcular los costos ingresando a la Opcion 3.\n");
				printf("------------------------------------------------------------------\n\n");
			}
			break;

		case 5:
			// Hardcodeo los datos para realizar los calculos sin pedir por teclado
			kilometros = 7090;
			precioVueloAerolineas = 162965;
			precioVueloLatam = 159339;

			// Cargo las variables
			debitoAerolineas = CalcularDebito(precioVueloAerolineas);
			creditoAerolineas = CalcularCredito(precioVueloAerolineas);
			bitcoinAerolineas = CalcularBitcoin(precioVueloAerolineas);
			precioPorKilometroAerolineas = CalcularPrecioPorKilometro(
					precioVueloAerolineas, kilometros);

			debitoLatam = CalcularDebito(precioVueloLatam);
			creditoLatam = CalcularCredito(precioVueloLatam);
			bitcoinLatam = CalcularBitcoin(precioVueloLatam);
			precioPorKilometroLatam = CalcularPrecioPorKilometro(
					precioVueloLatam, kilometros);
			diferencia = CalcularDiferencia(precioVueloAerolineas,
					precioVueloLatam);

			//Llamo a la funcion que muestra lo calculado por pantalla pasandole los datos correspondientes.
			MostrarCostos(debitoAerolineas, debitoLatam, creditoAerolineas,
					creditoLatam, bitcoinAerolineas, bitcoinLatam,
					precioPorKilometroAerolineas, precioPorKilometroLatam,
					diferencia, kilometros, precioVueloAerolineas,
					precioVueloLatam);

			break;

		case 6:
			//Mensaje de despedida
			printf("\n\n***** Se termino el programa *****\n\n");

			break;
		}

	}
	return 0;
}
