#ifndef PRODUCTOALMACEN_H
#define PRODUCTOALMACEN_H
#include <string>
using namespace std;

class ProductoAlmacen{

    private:
        string id;
        string nombre;
        double precio;
        int existencia;
    
    public:
        ProductoAlmacen();
        ProductoAlmacen(string id, string nombre, double precio, int existencia);
        void mostrarDatos();
        void venderProducto(int cantidad);
        string getID();
        string getNombre();
        double getPrecio();
        int getExistencia();

};
#endif