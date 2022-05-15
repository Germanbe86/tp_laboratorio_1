#include "Entidades.h"
#include "ArrayPassenger.h"
#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void initPassengers(Passenger passenger[], int len) {

	int i;

		for (i = 0; i < LEN; i++) {
			passenger[i].isEmpty = 1;
		}

}

void addPassenger(Passenger passenger[], int len, int id, char name[],char lastName[], float price, int typePassenger, char flycode[]) {

	passenger[id].id = id;
	strcpy(passenger[id].name, name);
	strcpy(passenger[id].lastName, lastName);
	passenger[id].price = price;
	strcpy(passenger[id].flycode, flycode);
	passenger[id].typePassenger = typePassenger;
	passenger[id].isEmpty = 0;
}

int PedirDatosPasajero() {

	char opcionIngresada;
	char nombre[51];
	char apellido[51];
	float precio;
	int tipoDePasajero;
	char codigoDeVuelo[51];
	int i;
	int id = 0;

	for (i = 0; i < LEN; i++) {
		if (passenger[i].isEmpty == 1) {

			id = i;
			while (!(opcionIngresada == 'n')) {

				printf("\nNumero de ID: %d \n", id);

				printf(" \nIngrese los siguientes datos:\n");
				printf(" Nombre: ");
				__fpurge(stdin);
				scanf("%[^\n]", nombre);
				printf(" Apellido: ");
				__fpurge(stdin);
				scanf("%[^\n]", apellido);

				printf(" Precio: ");
				__fpurge(stdin);
				scanf("%f", &precio);

				printf(" Tipo de pasajero (1-VIP, 2-BASIC): ");
				__fpurge(stdin);
				scanf("%d", &tipoDePasajero);

				printf(" Codigo de vuelo: ");
				__fpurge(stdin);
				scanf("%[^\n]", codigoDeVuelo);

				addPassenger(passenger, LEN, id, nombre, apellido, precio,tipoDePasajero, codigoDeVuelo);
				id++;
				printf(
						"\nDesea dar de alta otro pasajero: (Presione 's' para continuar o 'n' para salir): \n");
				__fpurge(stdin);
				scanf("%c", &opcionIngresada);
			}
		}
	}
	return (1);
}

int printPassengerById(Passenger passenger[], int len, int id) {

	int i;
	printf("\n--------------------------------------------------------------\n");
	printf("ID: \t");
	printf("Nombre: \t");
	printf("Apellido: \t");
	printf("Precio: \t");
	printf("Tipo de pasajero: \t");
	printf("Codigo de Vuelo: \t\n\n");

	for (i = 0; i < id + 1; i++) {

		if (passenger[i].id == id) {

			printf("%d\t", passenger[i].id);
			printf("%s\t\t", passenger[i].name);
			printf("%s\t\t", passenger[i].lastName);
			printf("%.2f\t\t", passenger[i].price);
			printf("%d\t\t\t", passenger[i].typePassenger);
			printf("%s\t\t\n", passenger[i].flycode);

			if (passenger[i].isEmpty == -1) {
				printf("\nEste pasajero fue borrado\n");
			}
		}
	}
	return (1);
}

int printPassenger(Passenger passenger[], int len) {

	int i;
	printf("\n-----------------------------------------------------------------------------------------\n");
	printf("\n**************** Lista de pasajeros Activos ******************\n\n");
	printf("ID: \t");
	printf("Nombre: \t");
	printf("Apellido: \t");
	printf("Precio: \t");
	printf("Tipo de pasajero: \t");
	printf("Codigo de Vuelo: \t\n\n");

	for (i = 0; i < len; i++) {

		if (passenger[i].isEmpty == 0) {

			printf("%d\t", passenger[i].id);
			printf("%s\t\t", passenger[i].name);
			printf("%s\t\t", passenger[i].lastName);
			printf("%.2f\t\t", passenger[i].price);
			printf("%d\t\t\t", passenger[i].typePassenger);
			printf("%s\t\t\n", passenger[i].flycode);
		}
	}
	return (1);
}

int findPassengerById(Passenger passenger[], int len, int id) {

	int retorno = 0;
	int i;
	for (i = 0; i < len; i++) {

		if (passenger[i].id == id) {

			retorno = printPassengerById(passenger, len, id);
			break;
		}
	}
	return retorno;
}

int removePassenger(Passenger passenger[], int len, int id) {

	int i;
	int retorno = 0;
	for (i = 0; i < len; ++i) {

		if (passenger[i].id == id) {
			passenger[i].isEmpty = -1;
			retorno = -1;
		}
	}
	return retorno;
}
void MostrarMenuModificar() {

	printf("\n--------------------------------------------\n");
	printf("\n-------MENU MODIFICAR------\n");
	printf("\n1.Modificar Nombre\n");
	printf("2.Modificar Apellido\n");
	printf("3.Modificar Precio\n");
	printf("4.Modificar Tipo de pasajero\n");
	printf("5.Modificar Codigo de vuelo\n");
	printf("6.VOLVER AL MENU PRINCIPAL\n\n");
	printf("Ingrese una opcion del 1 al 6: \n");
}

int ModifyPassenger(Passenger passenger[], int len, int id) {

	int numeroIngresado = 0;

	printPassenger(passenger, len);

	printf("\n Seleccione ID de pasajero a modificar: \n");
	scanf("%d", &id);

	findPassengerById(passenger, len, id);

	if (passenger[id].isEmpty == 1) {

		printf("\nEl id seleccionado a sido borrado o nunca fue cargado. Seleccione uno del listado.\n");
	} else {
		while (!(numeroIngresado == 6)) {

			MostrarMenuModificar();

			numeroIngresado = PedirOpcion(6);

			SwitchModify(passenger, numeroIngresado, len, id);
		}

	}
	return 0;
}

int SwitchModify(Passenger passenger[], int numeroIngresado, int len, int id) {

	switch (numeroIngresado) {
	case 1:
		printf("\nIngrese nuevo nombre: \n");
		__fpurge(stdin);
		scanf("%[^\n]", passenger[id].name);
		printPassenger(passenger, len);

		break;
	case 2:
		printf("\nIngrese nuevo apellido: \n");
		__fpurge(stdin);
		scanf("%[^\n]", passenger[id].lastName);
		printPassenger(passenger, len);
		break;
	case 3:
		printf(" Ingrese nuevo Precio: \n");

		scanf("%f", &passenger[id].price);
		printPassenger(passenger, len);
		break;
	case 4:
		printf(" Ingrese nuevo Tipo de pasajero (1 basico o 2 gold):\n");

		scanf("%d", &passenger[id].typePassenger);
		printPassenger(passenger, len);
		break;
	case 5:
		printf(" Ingrese nuevo Codigo de vuelo: \n");
		__fpurge(stdin);
		scanf("%[^\n]", passenger[id].flycode);
		printPassenger(passenger, len);
		break;
	case 6:
		break;

	}
	return 0;
}

int sortPassengers(Passenger passenger[], int len, int order,
		int numeroIngresado) { //orden 1 creciente   //orden 2 decreciente

	Passenger orderBy[LEN];
	Passenger temporal;

	int i;
	int j;

	for (i = 0; i < len; i++) {
// aca cargo un nuevo array para usarlo y no modificar el orden por ID de las primeras opciones del menu principal.
		orderBy[i].id = passenger[i].id;
		strcpy(orderBy[i].flycode, passenger[i].flycode);
		orderBy[i].isEmpty = passenger[i].isEmpty;
		strcpy(orderBy[i].lastName, passenger[i].lastName);
		strcpy(orderBy[i].name, passenger[i].name);
		orderBy[i].price = passenger[i].price;
		orderBy[i].typePassenger = passenger[i].typePassenger;
	}
	if (numeroIngresado == 1) {
//Ordeno en forma creciente por apellido
		if (order == 1) {
			for (i = 0; i < len; i++) {
				for (j = i + 1; j < len; j++) {
					if (strcmp(orderBy[i].lastName, orderBy[j].lastName) > 0) {

						temporal = orderBy[i];
						orderBy[i] = orderBy[j];
						orderBy[j] = temporal;
					}
				}
			}
			printPassenger(orderBy, len);
		}
//Ordeno en forma decreciente por apellido
		if (order == 2) {
			for (i = 0; i < len; i++) {
				for (j = i + 1; j < len; j++) {
					if (strcmp(orderBy[i].lastName, orderBy[j].lastName) < 0) {

						temporal = orderBy[i];
						orderBy[i] = orderBy[j];
						orderBy[j] = temporal;
					}
				}
			}
			printPassenger(orderBy, len);
		}
	}
	if (numeroIngresado == 3) {
		//Ordeno en forma creciente por Codigo de vuelo
		if (order == 1) {
			for (i = 0; i < len; i++) {
				for (j = i + 1; j < len; j++) {
					if (strcmp(orderBy[i].flycode, orderBy[j].flycode) > 0) {

						temporal = orderBy[i];
						orderBy[i] = orderBy[j];
						orderBy[j] = temporal;
					}
				}
			}
			printPassenger(orderBy, len);
		}
		//Ordeno en forma decreciente por Codigo de vuelo
		if (order == 2) {
			for (i = 0; i < len; i++) {
				for (j = i + 1; j < len; j++) {
					if (strcmp(orderBy[i].flycode, orderBy[j].flycode) < 0) {

						temporal = orderBy[i];
						orderBy[i] = orderBy[j];
						orderBy[j] = temporal;
					}
				}
			}
			printPassenger(orderBy, len);
		}
	}
	if (numeroIngresado == 4) {
		//Ordeno en forma creciente por Tipo de pasajero
		if (order == 1) {
			for (i = 0; i < len; i++) {
				for (j = i + 1; j < len; j++) {
					if (orderBy[i].typePassenger > orderBy[j].typePassenger) {

						temporal = orderBy[i];
						orderBy[i] = orderBy[j];
						orderBy[j] = temporal;
					}
				}
			}
			printPassenger(orderBy, len);
		}
		//Ordeno en forma decreciente por Tipo de pasajero
		if (order == 2) {
			for (i = 0; i < len; i++) {
				for (j = i + 1; j < len; j++) {
					if (orderBy[i].typePassenger < orderBy[j].typePassenger) {

						temporal = orderBy[i];
						orderBy[i] = orderBy[j];
						orderBy[j] = temporal;
					}
				}
			}
			printPassenger(orderBy, len);
		}
	}

	return (0);
}

void MostrarMenuInformar() {

	printf("\n-------------------------------------------------------------------------------\n");
	printf("\n-------MENU INFORMAR------\n");
	printf("\n1.ORDENAR POR APELLIDO\n");
	printf("2.PRECIO TOTAL,PROMEDIO Y PASAJEROS QUE SUPERAN EL PROMEDIO\n");
	printf("3.LISTAR POR CODIGO DE VUELO DE PASAJEROS ACTIVOS.\n");
	printf("4.ORDENAR POR TIPO DE PASAJERO\n");
	printf("5.**VOLVER AL MENU PRINCIPAL**\n");
}
void InformarPasajeros() {

	int numeroIngresado = 0;

	while (!(numeroIngresado == 5)) {

		MostrarMenuInformar();

		numeroIngresado = PedirOpcion(5);

		SwitchInformar(numeroIngresado);
	}
}

void TotalYPromedio(Passenger passenger[], int len) {
	float precioPromedio = 0;
	int pasajerosSuperanPromedio = 0;
	float sumatoriaPrecioPasajeros = 0;
	int cantidadDePasajerosActivos = 0;
	int i;

	for (i = 0; i < len; i++) {
		sumatoriaPrecioPasajeros += passenger[i].price;

		if (passenger[i].isEmpty == 0) {
			cantidadDePasajerosActivos++;
		}
	}

	precioPromedio = sumatoriaPrecioPasajeros / cantidadDePasajerosActivos;

	for (i = 0; i < len; i++) {

		if (passenger[i].price > precioPromedio) {
			pasajerosSuperanPromedio++;
		}
	}
	printf("-----------------------------------------\n");
	printf("El total de los pasajes activos vendidos es: $%.2f ",
			sumatoriaPrecioPasajeros);
	printf("\nEl precio promedio de los pasajes es: $%.2f\n ", precioPromedio);
	printf("%d pasajeros superan este precio promedio.\n",
			pasajerosSuperanPromedio);
}

void SwitchInformar(int numeroIngresado) {

	int order;

	switch (numeroIngresado) {

	case 1:
		printf("1.ORDEN CRECIENTE\n");
		printf("2.ORDEN DECRECIENTE\n\n");
		order = PedirOpcion(2);
		sortPassengers(passenger, LEN, order, numeroIngresado);
		break;
	case 2:
		TotalYPromedio(passenger, LEN);
		break;
	case 3:
		printf("1.ORDEN CRECIENTE\n");
		printf("2.ORDEN DECRECIENTE\n\n");
		order = PedirOpcion(2);
		sortPassengers(passenger, LEN, order, numeroIngresado);
		break;
	case 4:
		printf("1.ORDEN CRECIENTE\n");
		printf("2.ORDEN DECRECIENTE\n\n");
		order = PedirOpcion(2);
		sortPassengers(passenger, LEN, order, numeroIngresado);
		break;
	case 5:
		break;
	}

}
