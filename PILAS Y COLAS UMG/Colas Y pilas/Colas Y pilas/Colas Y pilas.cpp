#include <cstdlib>>
#include <queue>
#include <stack>
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <conio.h>
#include <time.h>
#include <random>
#include <string.h>
#include <string>
using namespace std;

void gotoxy(int x, int y)
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void cuadro() {
	int i;
	for (i = 2; i <= 25; i++) {
		gotoxy(20, i); cout << "°°";
	}

	for (i = 2; i <= 25; i++) {
		gotoxy(100, i); cout << "°°";
	}

	for (i = 20; i <= 100; i++) {
		gotoxy(i, 25); cout << "°°";
	}
	for (i = 20; i <= 100; i++) {
		gotoxy(i, 2); cout << "°°";
	}
}

void principal();
void vector1();
void pila();

int main() {
	//vector44();
//	vector1();
	principal();
	system("pause");

}



void principal() {
	stack<string> p;

	vector<int>arr22;

	int i, r = 0, dd = 0;
	int u[1000000];

	random_device rd;   // non-deterministic generator
	mt19937 gen(rd());  // to seed mersenne twister.
	uniform_int_distribution<> dist(-1000000, 1000000); // distribute results between 1 and 6 inclusive.
	int a;

	cout << ("Llenando Valores")<<endl;
	for (int i = 1; i < 100; i++) {
		u[i] = { dist(gen) };
		arr22.push_back(dist(gen));
		cout << u[i] << ", ";

	}
	int tama = arr22.size();
	
 cout << ("\n\n\t\t\t\t Generar y Ordenar de Numeros Aleatorios (Pilas Colas) ");
 cout << ("\n\t\t\t\tLuis Fernando Paxel Cojolon");
 cout << ("\n\t\t\t\t1. Pila");
 cout << ("\n\t\t\t\t2. Cola");
  cout << ("\n\t\t\t\t3. Salir");
cout << ("\n\t\t\t\tIngrese opcion: ");

	cin >> a;
	do
	{

		switch (a)
		{
		case 1:
			system("cls");
			do {
				system("cls");
				dd++;
				Sleep(2);
				for (auto d = arr22.begin(); d != arr22.end(); ++d)
					cout << *d << ",  ";
				arr22.erase(arr22.end() - 1);



				if (dd == tama) {
					system("cls");
					cout << "-------------------------------      Cola vacia  -----------------------------" << endl;
					return;
				}

			} while (dd != tama);

			break;


		case 2:
			system("cls");
			cout << "Vaciando Cola" << endl;
			do {

				system("cls");
				dd++;

				for (auto d = arr22.begin(); d != arr22.end(); ++d) 

					cout << *d << ", ";

					arr22.erase(arr22.begin());
				
				if (dd == tama) {
					system("cls");
					cout << "-------------------------------      Cola vacia  -----------------------------" << endl;
					return;
				}

			} while (dd != tama);
			_getch(); 
			break;
		case 3:
			system("cls");
			cout << ("\n\t\tOperaciones Finalizadas!!");
			break;

		default:
			system("cls");
			cout << ("\n\t\t Error Escriba bien joven");
		
	}
	} while (a != 3);

}