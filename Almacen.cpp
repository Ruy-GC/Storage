#include "ProductoAlmacen.h"
#include "Almacen.h"
#include <iostream>
#include <string>
using namespace std;

Almacen::Almacen(ProductoAlmacen productos[], int size){
    for (int i = 0; i<size;i++){
        this->productos[i] = productos[i];
    }
    this->size = size;
}

void Almacen::verProductos(){
    cout<<"----------------------------------------"<<endl;
    cout<<"ID,Nombre,Precio,Existencia"<<endl;
    for (int i = 0; i<size; i++){
        this->productos[i].mostrarDatos();
    }
    cout<<"----------------------------------------"<<endl;
}

int Almacen::buscarProductos(string id){
    //busca el producto en el almacen y regresa el indice del producto en la lista
    for (int i = 0; i<size;i++){
        if (id == productos[i].getID()){
            return i;
        }
    }

    return -1;
}

int Almacen::getSize(){
    return size;
}

int Almacen::getExistencia(int index){
    return this->productos[index].getExistencia();
}
bool Almacen::revisarExistencia(int index, int cantidad){
    if (productos[index].getExistencia() < cantidad){
        cout<<"No se puede realizar la venta, solo hay "<<productos[index].getExistencia()<<" en el amacen"<<endl;
        return false;
    }else{
        return true;
    }
}

double Almacen::precioProducto(int index){
    return productos[index].getPrecio();
}
string Almacen::nombreProducto(int index){
    return productos[index].getNombre();
}

void Almacen::reducirExistencia(string id, int cantidad){
    for (int i = 0; i<size;i++){
        if (id == productos[i].getID()){
            productos[i].venderProducto(cantidad);
        }
    }
}