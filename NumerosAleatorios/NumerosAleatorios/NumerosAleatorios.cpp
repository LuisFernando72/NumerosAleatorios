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
#define pp 1000000
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

void leer();
void menu();
void principal();
void ordenar();

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


int main() {
    system("color f6");
    menu();
}


void menu()
{
    system("cls");
    int a;
    cuadro();
    gotoxy(40, 5); cout << ("| Generar y Ordenar de Numeros Aleatorios  |");
    gotoxy(22, 24); cout << ("Luis Fernando Paxel Cojolon");
    gotoxy(54, 10); cout << ("1. Ingresar");
    gotoxy(54, 11); cout << ("2. Ordenar Datos");
    gotoxy(54, 12);  cout << ("3. Salir");
    gotoxy(54, 15); cout << ("Ingrese opcion: ");

    cin >> a;
    do
    {

        switch (a)
        {
        case 1:
            system("cls");
            principal();

            break;


        case 2:
            system("cls");
            ordenar();
            menu();
            break;
        case 3:
            system("cls");
            cout << ("\n\t\tOperaciones Finalizadas!!");
            break;

        default:
            system("cls");
            cout << ("\n\t\tNo se haga el pendejo y escriba bien >:v");
          
            menu();
        }
    } while (a != 3);
}


void principal() {
    ofstream f;
    ofstream orden;
    // APERTURA del fichero
    char p;

    orden.open("Aleatorio22.txt");
    int i;

    random_device rd;   // non-deterministic generator
    mt19937 gen(rd());  // to seed mersenne twister.
    uniform_int_distribution<> dist(-1000000, 1000000); // distribute results between 1 and 6 inclusive.
   

    
    do {
        if (!f ) {
            cout << "Error abriendo el fichero" << endl;

        }
        else {

            for (i = 1; i < 1000000; ++i) {

                //cout << dist(gen) << ", ";
            //    f << dist(gen)<<", ";
                orden<< dist(gen)<<endl ;


            }
        
     }
     
   

     cout << endl<< ("Desea Repetir [s/n]: ");
      cin >> p;

     } while (p == 's' || p == 'S');
  
      orden.flush();
      orden.close();

     if(p=='n' || p=='N' ){
    menu();
    }
    
   
}

void leer() {


}
    int pos_pivote(int arr[], int ini, int fin) {
        int pivote = arr[fin];
        int i = ini;
        for (int j = ini; j < fin; j++) {
            if (arr[j] < pivote) {
                swap(arr[i], arr[j]);
                i++;
                // swap(arr[i++], arr[j]); // for one-line lovers
            }
        }
        swap(arr[fin], arr[i]);
        return i;
    }


    void quick_sort(int arr[], int ini, int fin) {
        int i;
        if (ini < fin) {
            i = pos_pivote(arr, ini, fin);
            quick_sort(arr, ini, i - 1);
            quick_sort(arr, i + 1, fin);
        }
    }

    void ordenar() {
        ifstream f;
        int c;
        ofstream guardar;

        int dato[1000000], ss = 0;
    guardar.open("Ordenadob.txt");

    f.open("Aleatorio22.txt");

    if (!f.is_open()) {
        cerr << "Could not open the file - ";
        exit(0);
    }
  
    do {
     
        for (int cc = 1; cc < 1000000; cc++) {
            f >> dato[cc];
       //    cout <<" " << cc<<"| " << dato[cc] << endl;
        }
     
       
    } while (!f.eof());
    quick_sort(dato, 1, 1000000);

 
    if (!guardar) {
        cout << "Error abriendo el fichero" << endl;

    }
    else {
   //     guardar << "La casa amarilla" << endl;
   //     cout << "Ascendente: " << endl;
        for (c = 1; c < 1000000; c++) {
          //  cout << "[" << c << "] " << dato[c] << endl;
            guardar << dato[c]<<", ";

        }
    }     
    //  		guardar<<" "<<x<<" "<<y<<" "<<z;
   
    guardar.flush();
    guardar.close();
f.close();
exit(0);
}

