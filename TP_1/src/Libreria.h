/*
 * Libreria.h
 *
 *  Created on: Apr 11, 2022
 *      Author: gb
 */

#ifndef LIBRERIA_H_
#define LIBRERIA_H_

// Aca Escribimos los prototipos de nuestras funciones. Seria como declarar las funciones.

void MostrarMenuPrincipal(float precioVueloAerolineas, float precioVueloLatam, float kilometros);
int PedirOpcion();
float IngresarKilometros(float kilometros);
float IngresarPrecioVuelo();
void Opciones(int opcionIngresada);
char MostrarMenuOpcion2();
float CalcularDebito(float precioVuelo);
float CalcularCredito(float precioVuelo);
float CalcularBitcoin(float precioVuelo);
float CalcularPrecioPorKilometro(float precioVuelo, float kilometros);
float CalcularDiferencia(float precioVueloAerolineas, float precioVueloLatam);
void MostrarCostos(float debitoAerolineas, float debitoLatam,
		float creditoAerolineas, float creditoLatam, float bitcoinAerolineas,
		float bitcoinLatam, float precioPorKilometroAerolineas,
		float precioPorKilometroLatam, float diferencia, float kilometros,
		float precioVueloAerolineas, float precioVueloLatam);

#endif /* LIBRERIA_H_ */
