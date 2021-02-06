#ifndef PRODUCTOCARRITO_H
#define PRODUCTOCARRITO_H

#include <string>
using namespace std;

class ProductoCarrito{
    private:
        string id;
        string nombre;    
        double precio;
        int cantidad;    
    public:
        ProductoCarrito();
        ProductoCarrito(string id, string nombre, double precio, int cantidad);
        double subTotal();
        void verProducto();
        string getID();
        int getCantidad();
        void setCantidad(int cantidad);
};
#endif