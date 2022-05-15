
#ifndef ENTIDADES_H_
#define ENTIDADES_H_

/// \fn void MostrarMenuPrincipal()
/// \Esta funcion muestra por pantalla el menu principal.
void MostrarMenuPrincipal();

/// \fn int PedirOpcion(int)
/// \Pide al usuario qyue ingrese una opcion por teclado y la valida dentro de un rango.
/// \param max
/// \retorna el entero de la opcion elegida
int PedirOpcion(int max);

/// \fn int MenuSwitch(int, int)
/// \Segun el numero ingresado, ejecuta la parte correspondiente del codigo.
/// \param numeroIngresado
/// \param flagCarga
/// \devuelve el valor de la bandera para saber si se cargaron pasajeros.
int MenuSwitch(int numeroIngresado, int flagCarga);

#endif /* ENTIDADES_H_ */

