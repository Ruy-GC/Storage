#include <string>
#include <iostream>
#include "ProductoAlmacen.h"
using namespace std;

ProductoAlmacen::ProductoAlmacen(){
    this->id = "A";
    this->nombre = "A";
    this->precio = 1;
    this->existencia = 1;
}
ProductoAlmacen::ProductoAlmacen(string id, string nombre, double precio, int existencia){
    this->id = id;
    this->nombre = nombre;
    this->precio = precio;
    this->existencia = existencia;
}

void ProductoAlmacen::mostrarDatos(){
    cout<<this->id<<","<<this->nombre<<","<<this->precio<<","<<this->existencia<<endl;
}

void ProductoAlmacen::venderProducto(int cantidad){
    this->existencia -= cantidad;
}

double ProductoAlmacen::getPrecio(){
    return this->precio;
}

int ProductoAlmacen::getExistencia(){
    return this->existencia;
}

string ProductoAlmacen::getID(){
    return this->id;
}

string ProductoAlmacen::getNombre(){
    return this->nombre;
}