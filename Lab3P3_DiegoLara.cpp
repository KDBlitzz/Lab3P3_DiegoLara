#include <iostream>
using namespace std;
#include <locale>
void ejercicio_1() {
	int numero = 0;
	int longitud = 0;
	cout << "Ingrese el size del arreglo: " << endl;
	cin >> longitud;
	while (longitud < 5) {
		cout << "Favor ingresar un numero mayor a 5" << endl; cin >> longitud;
	}
	int* arreglo = new int[longitud];
	int* arregloVacio = new int[longitud];
	cout << "Ingrese los numeros del arreglo: " << endl;
	for (int i = 0; i < longitud; i++)
	{
		cin >> numero;
		while (numero < 1 || numero > 15) {
			cout << "Favor ingrese el numero entre 1 y 15" << endl; cin >> numero;
		}
		arreglo[i] = numero;
	}
	cout << "Arreglo antes: ";
	cout << "[";
	for (int i = 0; i < longitud; i++)
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
	for (int i = 0; i < longitud; i++)
	{
		if (arreglo[i] != 7)
		{
			arregloVacio[contador] = arreglo[i];
			contador++;
		}
		else {
			comprobar = 1;
		}
	}
	for (int i = contador; i < longitud; i++)
	{
		arregloVacio[i] = 7;
	}
	if (comprobar == 0)
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
	delete[] arregloVacio;
}
void ejercicio_2() {

}
void menu() {
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
			cout << "Opcion Invalida";
		}
	}
}
int main()
{
	setlocale(LC_ALL, "spanish");
	menu();
}
