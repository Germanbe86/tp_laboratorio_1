#include "Libreria.h"
#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


/// \fn void MostrarMenuPrincipal(float, float, float)
/// \brief : Le paso tres flotantes para que los vaya mostrando en el menu principal.
/// \param precioVueloAerolineas
/// \param precioVueloLatam
/// \param kilometros
/// No devuelve nada. Esta hecha para mostrar el menu de opciones por pantalla.
void MostrarMenuPrincipal(float precioVueloAerolineas, float precioVueloLatam,
		float kilometros) {

	printf("\n****************** MENU PRINCIPAL **************************");
	printf("\n\n*** Vuelos de Latam y Aerolíneas Argentinas ***\n\n");
	printf("1. Ingresar Kilometros: %.2f\n", kilometros);
	printf("2. Ingresar Precio de Vuelos: (Aerolineas= %.2f, Latam= %.2f)\n",
			precioVueloAerolineas, precioVueloLatam);
	printf("3. Calcular todos los costos\n");
	printf("4. Informar Resultados\n");
	printf("5. Carga forzada de datos\n");
	printf("6. Salir\n\n");
	printf("Ingrese una opcion del 1 al 6: \n");

}

/// \fn int PedirOpcion()
/// \brief: Pide al usuario un numero dentro de un rango y valida que este bien ingresado.(Opciones del menu principal)
/// \return: Devuelve el numero ingresado por teclado validado.(Solo Numeros entre el 1 y el 6)
int PedirOpcion() {

	int numeroIngresado;

	scanf("%d", &numeroIngresado);
	while ((numeroIngresado < 1) || (numeroIngresado > 6)) {

		printf("\nLa opcion ingresada no existe.\n");
		printf("Ingrese una opcion del 1 al 6: ");
		scanf("%d", &numeroIngresado);
	}
	return (numeroIngresado);
}

/// \fn float IngresarKilometros(float)
/// \brief: Pide y valida los kilometros Ingresados.Muestra mensaje de error si es necesario.(Opcion 1 del menu principal)
/// \param kilometros
/// \return: Devuelve los kilometros ingresados validados.(no podran ser menor a 1 km)
float IngresarKilometros(float kilometros) {

	printf("-----------------------------------------------------------\n\n");

	printf("Ingrese cantidad de kilometros: ");
	scanf("%f", &kilometros);
	printf("\nKilometros cargados: %.2f\n\n", kilometros);

	while (kilometros < 1) {
		printf("\nKilometros cargados: %.2f\n", kilometros);
		printf("\nLos kilometros deben ser mayor a 0\n");
		printf("Ingrese cantidad de kilometros: ");
		scanf("%f", &kilometros);
		printf("\nKilometros cargados: %.2f\n", kilometros);

	}
	return (kilometros);
}
/// \fn char MostrarMenuOpcion2()
/// \brief: Muestra el Menu de la Opcion 2 del Menu Principal y valida que el ingreso sea correcto.
/// \return: Devuelve la opcion ingresada validada.(solo puede ser 'y', 'z' o 'q')
char MostrarMenuOpcion2() {
	char empresaDeVuelo;

	printf("\n\nOpciones: \n");
	printf("\nPresione 'y': para cargar el precio de Aerolíneas\n");
	printf("Presione 'z': para cargar el precio de Latam\n");
	printf("Presione 'q': para volver al menu principal\n");
	printf("\nIngrese una opcion: \n");
	__fpurge(stdin);
	scanf("%c", &empresaDeVuelo);

	while (!((empresaDeVuelo == 'y') || (empresaDeVuelo == 'z')
			|| (empresaDeVuelo == 'q'))) {

		printf(
				"\n-----------------------------------------------------------\n");
		printf("Se ingreso una letra incorrecta. Vuelva a Ingresar.");

		printf("\n\nOpciones: \n");
		printf("\nPresione 'y': para cargar el precio de Aerolíneas\n");
		printf("Presione 'z': para cargar el precio de Latam\n");
		printf("Presione 'q': para volver al menu principal\n");
		printf("\nIngrese una opcion: \n");
		__fpurge(stdin);
		scanf("%c", &empresaDeVuelo);
	}
	return (empresaDeVuelo);
}



/// \fn float IngresarPrecioVuelo()
/// \brief: Pide ingreso de un numero. Valida que sea mayor a cero mostrando mensaje de error si fuera necesario.
/// \return: Devuelve precio validado.
float IngresarPrecioVuelo() {

	float precioVuelo;

	printf("Ingrese precio de Vuelo: $");
	scanf("%f", &precioVuelo);
	while (precioVuelo < 1) {
		printf("\nLos precios deben ser mayor a $0\n");
		printf("Ingrese precio de Vuelo: $");
		scanf("%f", &precioVuelo);
	}
	return (precioVuelo);
}

/// \fn float CalcularDebito(float)
/// \brief:Calcula el precio pagando con debito
/// \param precioVuelo
/// \return: Devuelve el resultado del calculo
float CalcularDebito(float precioVuelo) {
	float debito;
	debito = precioVuelo - ((precioVuelo * 10) / 100);
	return (debito);
}

/// \fn float CalcularCredito(float)
/// \brief: Calcula el precio pagando con credito
/// \param precioVuelo
/// \return: Devuelve el resultado del calculo
float CalcularCredito(float precioVuelo) {
	float credito;
	credito = precioVuelo + ((precioVuelo * 25) / 100);
	return (credito);
}

/// \fn float CalcularBitcoin(float)
/// \brief: Calcula el precio pagando con Bitcoins
/// \param precioVuelo
/// \return: Devuelve el resultado del calculo
float CalcularBitcoin(float precioVuelo) {
	float bitcoin;
	bitcoin = precioVuelo / 4606954.55;
	return (bitcoin);
}

/// \fn float CalcularPrecioPorKilometro(float, float)
/// \brief: Calcula el precio por cada kilometro recorrido
/// \param precioVuelo
/// \param kilometros
/// \return: Devuelve el resultado del calculo
float CalcularPrecioPorKilometro(float precioVuelo, float kilometros) {
	float precioPorKilometro;
	precioPorKilometro = precioVuelo / kilometros;
	return (precioPorKilometro);
}

/// \fn float CalcularDiferencia(float, float)
/// \brief: Calcula la diferencia de precio entre ambas Aerolineas.
/// \param precioVueloAerolineas
/// \param precioVueloLatam
/// \return: Devuelve el resultado del calculo
float CalcularDiferencia(float precioVueloAerolineas, float precioVueloLatam) {
	float diferencia;

	diferencia = precioVueloAerolineas - precioVueloLatam;

	if (diferencia < 0) {
		diferencia = (precioVueloLatam - precioVueloAerolineas);
	}
	return (diferencia);
}

/// \fn void MostrarCostos(float, float, float, float, float, float, float, float, float, float, float, float)
/// \brief: Se le pasa por parametro todos los resultados antes calculados para mostrarlos por pantalla
/// \param debitoAerolineas
/// \param debitoLatam
/// \param creditoAerolineas
/// \param creditoLatam
/// \param bitcoinAerolineas
/// \param bitcoinLatam
/// \param precioPorKilometroAerolineas
/// \param precioPorKilometroLatam
/// \param diferencia
/// \param kilometros
/// \param precioVueloAerolineas
/// \param precioVueloLatam
///No devuelve nada. Esta hecha para mostrar los resultados por pantalla.

void MostrarCostos(float debitoAerolineas, float debitoLatam,
		float creditoAerolineas, float creditoLatam, float bitcoinAerolineas,
		float bitcoinLatam, float precioPorKilometroAerolineas,
		float precioPorKilometroLatam, float diferencia, float kilometros,
		float precioVueloAerolineas, float precioVueloLatam) {

	printf("-----------------------------------------------------------\n\n");

	printf("Kilometros Ingresados: %.2f kms.\n\n\n", kilometros);

	printf("Precio volando por Aerolineas: $%.2f\n", precioVueloAerolineas);

	printf("\nEl precio pagando con debito es: $%.2f\n", debitoAerolineas);
	printf("El precio pagando con credito es: $%.2f\n", creditoAerolineas);
	printf("El precio pagando con bitcoin es: %f bitcoins.\n",
			bitcoinAerolineas);
	printf("El precio por kilometro recorrido es: $%.2f\n\n",
			precioPorKilometroAerolineas);

	printf("\nPrecio volando por Latam: $%.2f\n", precioVueloLatam);
	printf("\nEl precio pagando con debito es: $%.2f\n", debitoLatam);
	printf("El precio pagando con credito es: $%.2f\n", creditoLatam);
	printf("El precio pagando con bitcoin es: %f bitcoins.\n", bitcoinLatam);
	printf("El precio por kilometro recorrido es: $%.2f\n",
			precioPorKilometroLatam);

	printf("\n\nLa diferencia entre volar por una u otra Aerolinea es de: $%.2f\n\n",
			diferencia);
}
