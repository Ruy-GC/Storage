#ifndef ALMACEN_H
#define ALMACEN_H

#include "ProductoAlmacen.h"
#include <string>
using namespace std;

class Almacen{
    private:
        ProductoAlmacen productos[20];
        int size;
    public:
        Almacen(ProductoAlmacen productos[], int size);
        void verProductos();
        int buscarProductos(string id);
        bool revisarExistencia(int index, int cantidad);
        int getSize();
        int getExistencia(int index);
        double precioProducto(int index);
        string nombreProducto(int index);
        void reducirExistencia(string id, int cantidad);
        

};
#endif