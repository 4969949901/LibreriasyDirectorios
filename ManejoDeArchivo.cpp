#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "windows.h"
#include <filesystem>

using namespace std;

void crearArchivos(int cantidad) {
    int i=cantidad;
    for(int i=0;i<cantidad;i++) {
        ofstream file;
        string nombreF;

        cout<<"\t\tIngrese el nombre del archivo: "<<endl;
        cin>>nombreF;

        file.open("C:/Users/helac/CLionProjects/DirectoriosyArchivos/ejercicio4/"+ nombreF +" "+ to_string(i) +" ."+"txt");
        file<<"Librerias y Directorio en c++\n";
        file<<"Programacion uno jeje\n";
        file<<"Parciales proximos\n";
        if (file.fail()) {
            cout << "Error al intentar abrir el archivo." << endl;
            exit(1);
        }

        file.close();
    }
    cout<<"\t--------------------------------------------------------\n";
    cout<<"\tLos archivos creados fueron un total de:"<<cantidad<<endl;
    cout<<"\t--------------------------------------------------------\n";



}


void listarArchivosDeDirectorio(){
    WIN32_FIND_DATA findFileData;
    HANDLE          hFind;
    hFind = FindFirstFile("C:/Users/helac/CLionProjects/DirectoriosyArchivos/ejercicio4/*", &findFileData);

    if (hFind == INVALID_HANDLE_VALUE)
        cout << "ruta no valida intente de nuevo";
    else
    {
        cout << findFileData.cFileName << '\n';

        while (FindNextFile(hFind, &findFileData) != 0)
            cout << findFileData.cFileName << '\n';
    }
}

int contarArchivosDeDirectorio(){
    WIN32_FIND_DATA findFileData;
    HANDLE          hFind;
    int cantidadDeArchi=0;
    hFind = FindFirstFile("C:/Users/helac/CLionProjects/DirectoriosyArchivos/ejercicio4/*", &findFileData);

    if (hFind == INVALID_HANDLE_VALUE)
        cout << "Ruta no encontrada  intente de nuevo";
    else
        while (FindNextFile(hFind, &findFileData)!=0){
            cantidadDeArchi=cantidadDeArchi+1;
        }
    return cantidadDeArchi-1;
}

void mostrarDetalles(){
    std::filesystem::directory_iterator directoryIterator("C:/Users/helac/CLionProjects/DirectoriosyArchivos/ejercicio4/");
    for (const auto& entry : directoryIterator) {
        if (!std::filesystem::is_directory(entry.status())) {
            std::cout << entry.path().filename() << " "
                      << file_size(entry.path())  <<std::endl;cout<<"  bytes\n";
        }
    }
}
