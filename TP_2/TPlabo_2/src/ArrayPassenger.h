#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#define LEN 50

struct {
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int isEmpty;
}typedef Passenger;

Passenger passenger[LEN];

/// \fn void initPassengers(Passenger[], int)
/// \Inicializa el array de pasajeros para que esten disponibles para cargarlos
/// \param passenger
/// \param len
void initPassengers(Passenger passenger[], int len);

/// \fn int addPassenger(Passenger[], int, int, char[], char[], float, int, char[])
/// \Agrega un pasajero con todos sus datos al array de pasajeros
/// \param passenger
/// \param len
/// \param id
/// \param name
/// \param lastName
/// \param price
/// \param typePassenger
/// \param flycode
void addPassenger(Passenger passenger[], int len, int id, char name[],char lastName[], float price, int typePassenger, char flycode[]);

/// \fn int findPassengerById(Passenger[], int, int)
/// \Busca un pasajero filtrando por ID.
/// \param passenger
/// \param len
/// \param id
/// \devuelve el estado de la busqueda.
int findPassengerById(Passenger passenger[], int len, int id);

/// \fn int removePassenger(Passenger[], int, int)
/// \Realiza un borrado logico de un pasajero del array de pasajeros
/// \param passenger
/// \param len
/// \param id
/// \Retorna el estado de la operacion
int removePassenger(Passenger passenger[], int len, int id);

/// \fn int sortPassengers(Passenger[], int, int, int)
/// \Ordena pasajeros por distintos campos de mayor a menor o biceversa.
/// \param passenger
/// \param len
/// \param order
/// \param numeroIngresado
/// \Devuelve el estado de la operacion.
int sortPassengers(Passenger passenger[], int len, int order,int numeroIngresado);

/// \fn int printPassengerById(Passenger[], int, int)
/// \Imprime un pasajero filtrado por ID. Si esta borrado tambien lo muestra.
/// \param passenger
/// \param length
/// \param id
/// \Devuelve el estado de la operacion.
int printPassengerById(Passenger passenger[], int length, int id);

/// \fn int printPassenger(Passenger[], int)
/// \Imprime listado de pasajeros activos por pantalla. No muestra los borrados.
/// \param passenger
/// \param length
/// Devuelve el estado de la operacion.
int printPassenger(Passenger passenger[], int length);

/// \fn int PedirDatosPasajero()
/// \Pide los datos de un nuevo pasajero para cargarlos en el array.
/// Devuelve el estado de la operacion.
int PedirDatosPasajero();

/// \fn int ModifyPassenger(Passenger[], int, int)
/// \Modifica un pasajero ya cargado.
/// \param passenger
/// \param length
/// \param id
/// Devuelve el estado de la operacion.
int ModifyPassenger(Passenger passenger[], int length, int id);


/// \fn void MostrarMenuModificar()
/// \Muestra por pantalla las opciones del menu para Modificar un pasajero.
void MostrarMenuModificar();

/// \fn int SwitchModify(Passenger[], int, int, int)
/// \Ejecuta el bloque de codigo correspondiente a la opcion elegida por el usuario.
/// \param passenger
/// \param numeroIngresado
/// \param len
/// \param id
/// Devuelve el estado de la operacion.
int SwitchModify(Passenger passenger[], int numeroIngresado, int len, int id);

/// \fn void MostrarMenuInformar()
/// \Muestra por pantalla la opciones del menu Informar.
void MostrarMenuInformar();

/// \fn void InformarPasajeros()
/// \Ejecuta funciones necesarias para Informar por pantalla lo que el usuario desea
void InformarPasajeros();

/// \fn void SwitchInformar(int)
/// \ejecuta el bloque de codigo correspondiente segun la opcion elegida.
/// \param numeroIngresado
void SwitchInformar(int numeroIngresado);

/// \fn void TotalYPromedio(Passenger[], int)
/// \Calcula y muestra por pantalla  el total de precios de pasajes, el promedio y la cantidad de pasajeros que lo superan.
/// \param passenger
/// \param len
void TotalYPromedio(Passenger passenger[], int len);



#endif /* ARRAYPASSENGER_H_ */
