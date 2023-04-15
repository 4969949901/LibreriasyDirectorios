#include <iostream>
#include <filesystem>
#include <stdlib.h>
#include "archivo.h"


using namespace std;
int main() {
    int cantidad;
    cout<<"\t--------------------------------------------------------\n";
    cout<<"\t--archivos con informacion compartida--\n";
    cout << "\tCuantos archivos quiere crear: \n";
    cin >> cantidad;
    crearArchivos(cantidad);
    cout <<"\tConteo de archivos en directorio: "<< contarArchivosDeDirectorio();
    cout<<"\n\t--------------------------------------------------------\n";
    cout << endl;
    cout<<"Listado de archivos creados:"<<endl;
    listarArchivosDeDirectorio();
    cout<<"--------------------------------------------------------\n";
    cout<<"--------------------------------------------------------\n";
    cout<<"Se muestran detalles de los archivos y el tamano en bytes "<<endl;
    mostrarDetalles();
    cout<<"\t--------------------------------------------------------\n";


    return 0;
}
