#include <string>
#include <iostream>
#include "ProductoCarrito.h"
using namespace std;

ProductoCarrito::ProductoCarrito(){
    this->id = "A";
    this->nombre = "A";
    this->precio = 1;
    this->cantidad = 1;
}

ProductoCarrito::ProductoCarrito(string id, string nombre, double precio, int cantidad){
    this->id = id;
    this->nombre = nombre;
    this->precio = precio;
    this->cantidad = cantidad;
}

double ProductoCarrito::subTotal(){
    return precio * cantidad;
}

void ProductoCarrito::verProducto(){
    cout<<this->id<<","<<this->nombre<<","<<this->precio<<","<<this->cantidad<<","<<this->subTotal()<<endl;
}

string ProductoCarrito::getID(){
    return this->id;
}

int ProductoCarrito::getCantidad(){
    return this->cantidad;
}

void ProductoCarrito::setCantidad(int cantidad){
    this->cantidad = cantidad;
}