#include "Entidades.h"
#include "ArrayPassenger.h"
#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void MostrarMenuPrincipal() {
	printf("\n\n******************* MENU PRINCIPAL **************************\n");
	printf("1. ALTAS:\n");
	printf("2. MODIFICAR: \n");
	printf("3. BAJA:\n");
	printf("4. INFORMAR:\n");
	printf("5. CARGA FORZADA DE DATOS: \n");
	printf("6. SALIR:\n\n");
	printf("Ingrese una opcion del 1 al 6: \n");
}

int PedirOpcion(int max) {

	int numeroIngresado;

	scanf("%d", &numeroIngresado);
	while ((numeroIngresado < 1) || (numeroIngresado > max)) {

		printf("\nLa opcion ingresada no existe.\n");
		printf("Ingrese una opcion del 1 al %d: ", max);
		scanf("%d", &numeroIngresado);
	}
	return (numeroIngresado);
}

int MenuSwitch( numeroIngresado, flagCarga) {

	int id = 0;
	int retornoBusqueda;
	int retornoBorrado;

	switch (numeroIngresado) {

	case 1:
		flagCarga = PedirDatosPasajero();
		break;

	case 2: // Cuando buscas por ID para modificar, podes buscar un pasajero que no este en el listado te lo muestra
		//y te dice si fue borrado.
		if (flagCarga == 1) {

			ModifyPassenger(passenger, LEN, id);
		} else {
			printf(
					"\n Primero se deberan ingresar pasajeros en la opcion 1 del menu.\n ");
		}
		break;

	case 3:
		if (flagCarga == 1) {
			printPassenger(passenger, LEN);

			printf("\nIngrese el ID del pasajero a dar de baja:  \n");
			scanf("%d", &id);
			retornoBorrado = removePassenger(passenger, LEN, id);

			if (retornoBorrado == -1) {
				printf("\nSe dio de baja correctamente\n");
			} else {
				printf("\nNo se pudo dar de baja o ID inexistente\n");
			}
		} else {
			printf(
					"\n Primero se deberan ingresar pasajeros en la opcion 1 del menu.\n ");
		}
		printPassenger(passenger, LEN);
		break;

	case 4:
		if (flagCarga == 1) {
			InformarPasajeros();
		} else {
			printf(
					"\n Primero se deberan ingresar pasajeros en la opcion 1 del menu.\n ");
		}
		break;

	case 5:
		//Hardcodear pasajeros
		flagCarga = 1;

		addPassenger(passenger, LEN, 0, "Carlos", "Lopez", 1450.20, 1,
				"45ar56");
		addPassenger(passenger, LEN, 1, "Jorge", "Yazam", 2890.40, 2, "45ar57");
		addPassenger(passenger, LEN, 2, "Roberto", "Perez", 1678.60, 1,
				"45ar58");
		addPassenger(passenger, LEN, 3, "Marcela", "Antares", 5890.20, 2,
				"58mx22");
		addPassenger(passenger, LEN, 4, "Laura", "Zukini", 3658.60, 2,
				"45ar60");
		addPassenger(passenger, LEN, 5, "Yamila", "Torres", 3450.90, 2,
				"58mx23");
		addPassenger(passenger, LEN, 6, "Marcelo", "Lopez", 800.20, 1,
				"45ar78");
		addPassenger(passenger, LEN, 7, "Juan", "Sanchez", 1800.00, 2,
				"45ar80");
		addPassenger(passenger, LEN, 8, "Enrique", "Arias", 3408.60, 1,
				"45ar67");
		addPassenger(passenger, LEN, 9, "Juana", "Alonso", 5890.20, 2,
				"58mx100");
		addPassenger(passenger, LEN, 10, "Marta", "Campos", 3658.60, 2,
				"45ar88");
		addPassenger(passenger, LEN, 11, "Mirta", "Soria", 3450.90, 2,
				"58mx102");
		addPassenger(passenger, LEN, 12, "Candela", "Quispe", 1450.20, 1,
				"45ar88");
		addPassenger(passenger, LEN, 13, "Yanina", "Ramos", 2890.40, 2,
				"45ar120");
		addPassenger(passenger, LEN, 14, "Hector", "Acosta", 1678.60, 1,
				"45ar122");
		addPassenger(passenger, LEN, 15, "Rolando", "Arias", 1045.20, 2,
				"58mx108");
		addPassenger(passenger, LEN, 16, "Erika", "Casas", 3658.60, 2,
				"45ar99");
		addPassenger(passenger, LEN, 17, "Pedro", "Curso", 2450.90, 2,
				"58mx34");
		addPassenger(passenger, LEN, 18, "Marcos", "Salas", 2450.90, 2,
				"48mx32");

		printf("\nSe cargaron 18 pasajeros.\n");
		break;

	case 6:
		printf("\n**** Se ha terminado el programa ****\n");
		break;
	}
	return flagCarga;
}

