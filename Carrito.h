#ifndef CARRITO_H
#define CARRITO_H

#include <string>
#include "ProductoCarrito.h"
using namespace std;

class Carrito{
    private:
        string cliente;
        ProductoCarrito productos[10];
        int size;
    public:
        Carrito(string cliente,int size);
        void add(ProductoCarrito producto,int existencia);
        double total();
        void verCarrito();
        int buscarProducto(string id);
        void cambiarCantidad(int index, int cantidad);
        void eliminarProducto(int index);
        void vaciarCarrito();
        string getIDS(int index);
        int getCantidades(int index);
        int getSize();
        void setCliente(string cliente);
    
};
#endif

