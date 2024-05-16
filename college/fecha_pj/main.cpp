#include "Fecha.h"
#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{
    cout << "Nombre: " << "Olivier\n"
         << "Apellido: " << "Paspuel\n"
         << endl;
    cout << "NRC: " << "14543\n"
         << endl;
    cout << "Fecha de hoy: " << "10/05/2021\n"
         << endl;
    Fecha primera(1, 1, 2020);
    Fecha nacimiento(13, 8, 2004);
    cout << "Días entre mi nacimiento y el primero de enero de 2020: " << nacimiento.distancia(primera) << "\n";
    cout << "Se van a incrementar 50 días al primero de enero de 2020\n";
    Fecha f2 = primera.incrementar(50);
    cout << "Meses despues de añadir 50 días: " << f2.obtenerMes() << endl
         << "\n";
    return 0;
}