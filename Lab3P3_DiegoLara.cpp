#include <iostream>
using namespace std;
#include<cstdlib>
#include<ctime>
#include <locale>
int generarNumRandom(int minimo, int maximo) { // metodo para generar numeros al azar de 1 a 20
	int random;
	random = 0;
	random = minimo + (rand() % maximo);
	return random; 
}
void ordenadoAscendentemente(int arreglo[], int longitud) { // metodo para ordenar ascendentemente el ejercicio 2
	int contador, bandera;
	for (int i = 1; i < longitud; i++)
	{
		contador = arreglo[i];
		for (bandera = i - 1; bandera >= 0 && arreglo[bandera] > contador; bandera--)
		{
			arreglo[bandera + 1] = arreglo[bandera];
		}
		arreglo[bandera + 1] = contador;
	}
}
void ejercicio_1() {
	int numero = 0;
	int longitud = 0;
	cout << "Ingrese el size del arreglo: " << endl;
	cin >> longitud;
	while (longitud < 6) { // Validar que sea mayor a 5
		cout << "Favor ingresar un numero mayor a 5" << endl; cin >> longitud;
	}
	int* arreglo = new int[longitud]; // los arreglos a usar
	int* arregloVacio = new int[longitud];
	cout << "Ingrese los numeros del arreglo: " << endl;
	for (int i = 0; i < longitud; i++)
	{
		cin >> numero;
		while (numero < 1 || numero > 15) { // validar que sea un numero entre 1 y 15
			cout << "Favor ingrese el numero entre 1 y 15" << endl; cin >> numero;
		}
		arreglo[i] = numero;
	}
	cout << "Arreglo antes: ";
	cout << "[";
	for (int i = 0; i < longitud; i++) // imprimir el arreglo antes
	{
		if (i != longitud - 1)
		{
			cout << arreglo[i] << ",";
		}
		else {
			cout << arreglo[i];
		}
	}
	cout << "]" << endl;
	int comprobar = 0;
	int contador = 0;
	for (int i = 0; i < longitud; i++) // un for que recibe los numeros que no son 7
	{
		if (arreglo[i] != 7)
		{
			arregloVacio[contador] = arreglo[i];
			contador++;
		}
		else { // comprobar que allan 7s
			comprobar = 1;
		}
	}
	for (int i = contador; i < longitud; i++) // for que rellena los espacios vacios con 7
	{
		arregloVacio[i] = 7;
	}
	if (comprobar == 0) // if para ver si no tiene 7s y si si tenia pues imprimirlos en el arreglo despues
	{
		cout << "Vale más que no está el 7, ¡porque no es óptimo!" << endl;
	}
	else {
		cout << "Arreglo después: ";
		cout << "[";
		for (int i = 0; i < longitud; i++)
		{
			if (i != longitud - 1)
			{
				cout << arregloVacio[i] << ",";
			}
			else {
				cout << arregloVacio[i];
			}
		}
		cout << "]" << endl;
	}
	
	delete[] arreglo; 
	delete[] arregloVacio; // Borrar la memoria
}
void ejercicio_2() {
	int longitud = 0;
	int numeroObjetivo = 0;
	cout << "Ingrese el size del arreglo: "; cin >> longitud;
	while (longitud < 5) {
		cout << "Ingrese un size mayor o igual que 5" << endl; cin >> longitud;
	}
	int* arreglo = new int[longitud]; // puntero usado
	for (int i = 0; i < longitud; i++) // for para generar el random adentro del arreglo
	{
		arreglo[i] = generarNumRandom(1, 20);
	}
	cout << "Arreglo random generado: ";
	cout << "[";
	for (int i = 0; i < longitud; i++) // imprimir el arreglo
	{
		if (i != longitud - 1)
		{
			cout << arreglo[i] << ",";
		}
		else {
			cout << arreglo[i];
		}
	}
	cout << "]" << endl;
	cout << "Ingrese el número objetivo (entre 1 y 20): " << endl; cin >> numeroObjetivo;
	while (numeroObjetivo < 1 || numeroObjetivo > 20) { // validar que sea entre 1 y 20
		cout << "Ingrese un número entre 1 y 20" << endl; cin >> numeroObjetivo; 
	}
	ordenadoAscendentemente(arreglo, longitud); // metodo de ordenamiento
	cout << "Arreglo ordenado: ";
	cout << "[";
	for (int i = 0; i < longitud; i++) // imprimir el arreglo ordenado
	{
		if (i != longitud - 1)
		{
			cout << arreglo[i] << ",";
		}
		else {
			cout << arreglo[i];
		}
	}
	cout << "]" << endl;
	int numeroEncontrado = 0; // bandera utilizada para ver si el numero esta o no
	for (int i = 0; i < longitud; i++) // verificar si esta el numero que eligio el usuario
	{
		if (arreglo[i] == numeroObjetivo)
		{
			cout << "El número " << numeroObjetivo << " se encuentra en la posición " << i << " del arreglo." << endl;
			numeroEncontrado = 1;
			break;
		}
	} 
	if (numeroEncontrado == 0)
	{
		int i;
		for (i = 0; i < longitud; i++)
		{
			if (arreglo[i] > numeroObjetivo) // validar en que posicion deberia estar el numero
			{
				cout << "El número " << numeroObjetivo << " debería ir en la posición " << i << " del arreglo." << endl;
				break;
			}
		}
		if (arreglo[i] < numeroObjetivo) { // validar si el numero no esta en el arreglo y es mayor a los demas
			cout << "El número " << numeroObjetivo << " debería ir en la posición " << i - 1 << " del arreglo." << endl;
		}
	}
	delete[] arreglo;
}
void menu() { // menu
	int option = 0;
	bool menu = true;
	while (menu) {
		cout << "Ejercicio Práctico 1 – El número menos óptimo" << endl;
		cout << "Ejercicio práctico 2 – El número perdido" << endl;
		cout << "3. Salir" << endl;
		cin >> option;
		switch (option) {
		case 1:
			ejercicio_1();
			break;
		case 2:
			ejercicio_2();
			break;
		case 3:
			menu = false;
			break;
		default:
			cout << "Opcion Invalida" << endl;
		}
	}
}
int main()
{
	setlocale(LC_ALL, "spanish");
	srand(time(NULL));
	menu();
}
