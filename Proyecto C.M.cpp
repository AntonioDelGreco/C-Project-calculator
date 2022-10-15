// Nombre = Diego Ezequiel Antonio Del Greco;
// Nombre proyecto = Calculadora de matrices;
// Fecha de entrega = 29/06/2022;
// Materia = Programacion 1, Coppo;

//INCLUDES 
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;

//VARIABLES GLOBALES
string nombre;
int contador = 0;
bool validador = false;
int opcion;

//PROTOTIPOS DE FUNCION
//funciones que definen un usuario
void usuario();
void usuarioRegistrado();
//funciones que definen el menu
int menu();
void cuerpoCalculadora(int );
// funciones de cuentas
void suma();
void multiplicacionPorK();
void resta();
void traspuesta();
//funciones ayuda de cuentas
int** digitandoElementos(int, int );
void matricesIngresadas(int**, int, int );
void matrizResultante(int**, int, int );
void deleteMemoria(int**, int );
//funciones manejo de archivos
void haciendoArchivos(int** , int , int );
string especificandoCuenta();
//funciones decoracion
string lineaMenu();
string lineaHecha(int );
//


//PROGRAMA
int main() {
	usuario();

	do {
		opcion = 0;
		opcion = menu();
		cuerpoCalculadora(opcion);
	} while (opcion > 0 && opcion < 5);

	return 0;
}
//
void usuario() {
	cout << endl;
	cout << lineaMenu();
	cout << "\n\n\t\t\t\t\t\t\tNombre? ";
	cin >> nombre;
	system("cls");
}
void usuarioRegistrado() {
	cout << endl;
	cout << "\t\t\t\t\t\tUsuario activo: ";
	cout << nombre << " ";
	cout << "\n\t\t\t\t\t\tCantidad de operaciones\n\t\t\t\t\t\t     realizadas: ";
	cout << contador << endl;
}
//
int menu() {
	// declaracion de menu
	int opcion;

	cout << lineaMenu();
	cout << "\n\n\t\t\t*****           **     CALCULADORA DE MATRICES           **     *****\n\n";
	usuarioRegistrado();
	cout << "\n\t\t\t\t\tElija una de las siguientes opciones: \n\n";
	cout << "\t\t\t\t\t\t1)  Suma de matrices.\n\n";
	cout << "\t\t\t\t\t\t2)  Multiplicacion por\n\t\t\t\t\t\tuna constante.\n\n";
	cout << "\t\t\t\t\t\t3)  Resta de matrices.\n\n";
	cout << "\t\t\t\t\t\t4)  Traspuesta.\n\n";
	cout << "\n\t\t\t\tEscribir cualquier otra opcion o caracter, cierra el programa.\n\n";
	cout << lineaMenu();
	cout << "\n\n\t\t\t\t\t\t\tOpcion? ";
	cin >> opcion;
	system("cls");
	return opcion;
}
void cuerpoCalculadora(int x) {
	switch (x) {
	case 1:
		suma();
		break;
	case 2:
		multiplicacionPorK();
		break;
	case 3:
		resta();
		break;
	case 4:
		traspuesta();
		break;
	}
}
//
void suma() {

	int f, c;

	cout << lineaMenu();
	usuarioRegistrado();
	cout << "\n\n\t\t\tLa suma de matrices tiene que contener matrices de igual dimension.";
	cout << "\n\n\t\t\tCuantas filas tendran las matrices? ";
	cin >> f;
	cout << "\t\t\tCuantas columnas tendran las matrices? ";
	cin >> c;

	//digitando elementos de primera matriz
	cout << "\n\t\t\tPrimera matriz\n";
	int** matrizA = digitandoElementos(f, c);

	//digitando elementos de segunda matriz
	cout << "\n\t\t\tSegunda matriz\n";

	int** matrizB = digitandoElementos(f, c);

	//mostrando las amtrices ingresadas
	cout << "\n\t\t\tMatrices ingresadas:\n";
	matricesIngresadas(matrizA, f, c);
	cout << "\n\t\t\t\tMas\n";
	matricesIngresadas(matrizB, f, c);

	// sumando la matriz
	for (int i = 0; i < f; i++) {
		for (int j = 0; j < c; j++) {
			matrizA[i][j] += matrizB[i][j];
		}
	}

	contador++;
	cout << endl;

	cout << "\n\t\t\tMatrices resultante:\n";
	//mostrando la matriz resultante
	matrizResultante(matrizA, f, c);

	system("pause");
	system("cls");

	deleteMemoria(matrizA, f);
	deleteMemoria(matrizB, f);
}
void multiplicacionPorK() {

	int k, f, c;

	//declaracion de matriz
	cout << lineaMenu();
	usuarioRegistrado();
	cout << "\n\t\t\tMultiplicacion por una constante. \n";
	cout << "\t\t\tCuantas filas tendra las matriz? ";
	cin >> f;
	cout << "\t\t\tCuantas columnas tendra las matriz? ";
	cin >> c;
	cout << "\t\t\tValor de la constante? ";
	cin >> k;

	//digitando los elementos de la matriz
	cout << "\n\t\t\tMatriz\n";
	int** matriz = digitandoElementos(f, c);

	//Mostrando la matriz ingresada
	cout << "\n\t\t\tMatriz ingresada:\n";
	matricesIngresadas(matriz, f, c);

	//multiplicando por escalar
	for (int i = 0; i < f; i++) {
		for (int j = 0; j < c; j++) {
			matriz[i][j] *= k;
		}
	}

	contador++;
	cout << endl;

	//Mostrando la matriz resultante
	cout << "\n\t\t\tMatriz resultante:\n";
	matrizResultante(matriz, f, c);

	system("pause");
	system("cls");

	deleteMemoria(matriz, f);
}
void resta() {

	int** matrizA;
	int** matrizB;
	int f, c;

	cout << lineaMenu();
	usuarioRegistrado();
	cout << "\n\t\t\tLa resta de matrices tiene que contener matrices de igual dimension.";
	cout << "\n\t\t\tCuantas filas tendran las matrices? ";
	cin >> f;
	cout << "\n\t\t\tCuantas columnas tendran las matrices? ";
	cin >> c;

	//digitando los elementos de la matriz
	cout << "\n\t\t\tPrimera matriz\n";
	matrizA = digitandoElementos(f, c);

	//digitando los elementos de la matriz
	cout << "\n\t\t\tSegunda matriz\n";
	matrizB = digitandoElementos(f, c);

	//mostrando las matrices ingresadas
	cout << "\n\t\t\tMatrices ingresadas:\n";
	matricesIngresadas(matrizA, f, c);

	cout << "\n\t\t\t\tMenos\n";
	matricesIngresadas(matrizB, f, c);

	// resta la matriz
	for (int i = 0; i < f; i++) {
		for (int j = 0; j < c; j++) {
			matrizA[i][j] -= matrizB[i][j];
		}
	}

	contador++;
	cout << endl;

	//mostrando la matriz resultante
	cout << "\n\t\t\tMatrices resultante:\n";
	matrizResultante(matrizA, f, c);

	system("pause");
	system("cls");

	deleteMemoria(matrizA, f);
	deleteMemoria(matrizB, f);
}
void traspuesta() {

	int** matriz;
	int f, c;

	//declaracion de matriz
	cout << lineaMenu();
	usuarioRegistrado();
	cout << "\n\t\t\tTraspuesta. \n";
	cout << "\t\t\tCuantas filas tendra las matriz? ";
	cin >> c;
	cout << "\t\t\tCuantas columnas tendra las matriz? ";
	cin >> f;

	//digitando los elementos de la matriz
	cout << "\n\t\t\tMatriz\n";
	matriz = digitandoElementos(c, f);

	//matriz ingresada
	cout << "\n\t\t\tMatriz ingresada:\n";
	matricesIngresadas(matriz, c, f);

	cout << endl;

	//Mostrando la matriz resultante
	cout << "\n\t\t\tMatriz resultante:\n";

	matrizResultante(matriz, f, c);

	cout << endl;
	contador++;
	system("pause");
	system("cls");

	deleteMemoria(matriz, c);
}
//
int** digitandoElementos(int f, int c) {

	int** matriz = new int* [f];
	for (int i = 0; i < f; i++) {
		matriz[i] = new int[c];
		for (int j = 0; j < c; j++) {
			cout << "\t\t\tPosicion: < " << i << " > < " << j << " >: ";
			cin >> matriz[i][j];
		}
	}
	return matriz;
}
void matricesIngresadas(int** matriz, int f, int c) {

	for (int i = 0; i < f; i++) {
		cout << "\t\t\t" << lineaHecha(c) << endl;
		cout << "\t\t\t";
		for (int j = 0; j < c; j++) {
			cout << "|" << setw(4) << fixed << matriz[i][j] << setw(4) << "|";
		}
		cout << "\n\t\t\t" << lineaHecha(c) << endl;
	}

}
void matrizResultante(int** matriz, int f, int c) {

	if (opcion == 4){
		for (int i = 0; i < f; i++) {
			cout << "\t\t\t" << lineaHecha(c) << endl;
			cout << "\t\t\t";
			for (int j = 0; j < c; j++) {
				cout << "|" << setw(4) << fixed << matriz[j][i] << setw(4) << "|";
			}
			cout << "\n\t\t\t" << lineaHecha(c) << endl;
		}
		cout << endl;

		haciendoArchivos(matriz, f, c);
	}
	else {
		for (int i = 0; i < f; i++) {
			cout << "\t\t\t" << lineaHecha(c) << endl;
			cout << "\t\t\t";
			for (int j = 0; j < c; j++) {
				cout << "|" << setw(4) << fixed << matriz[i][j] << setw(4) << "|";
			}
			cout << "\n\t\t\t" << lineaHecha(c) << endl;
		}
		cout << endl;

		haciendoArchivos(matriz, f, c);
	}
}
void deleteMemoria(int** matriz, int f) {
	for (int i = 0; i < f; i++) {
		delete[]matriz[i];
	}
	delete[]matriz;
}
//
void haciendoArchivos(int** matriz, int f, int c) {

	//abriendo archivo txt
	ofstream archivoMatrices("matrices_hechas.txt", ios::app);

	//validacion de nombre
	if(validador){
		 validador = true;
	}
	else {
		archivoMatrices << "Usuario: " << nombre << "\n\n";
		validador = true;
	}

	archivoMatrices << especificandoCuenta();

	//imprimiendo en el txt las matrices
	if (opcion == 4) {
		for (int i = 0; i < f; i++) {
			archivoMatrices << lineaHecha(c) << endl;
			for (int j = 0; j < c; j++) {
				archivoMatrices << "|" << setw(4) << fixed << matriz[j][i] << setw(4) << "|";
			}
			archivoMatrices << "\n" << lineaHecha(c) << endl;
		}
		archivoMatrices << "\n";
	}
	else {
		for (int i = 0; i < f; i++) {
			archivoMatrices << lineaHecha(c) << endl;
			for (int j = 0; j < c; j++) {
				archivoMatrices << "|" << setw(4) << fixed << matriz[i][j] << setw(4) << "|";
			}
			archivoMatrices << "\n" << lineaHecha(c) << endl;
		}
		archivoMatrices << "\n";
	}

	//cerrando el archivo
	archivoMatrices.close();
}
string especificandoCuenta() {

	if (opcion == 1){
		return "Suma:\n";
	}
	else if (opcion == 2) {
		return "Multiplicacion por la constante:\n";
	}
	else if (opcion == 3) {
		return "Resta de matrices:\n";
	}
	else if (opcion == 4) {
		return "Traspuesta:\n";
	}
}
//
string lineaMenu() {
	string lineaMenu = "\n\t\t************************************************************************************";
	return lineaMenu;
}
string lineaHecha(int c) {

	string linea = " ------- ", lineaSumada;

	for (int p = 0; p < c; p++) {
		lineaSumada.append(linea);
	}

	return lineaSumada;
}