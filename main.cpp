#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Almacen.h"
#include "Almacen.cpp"
#include "ProductoAlmacen.h"
#include "ProductoAlmacen.cpp"
#include "Carrito.h"
#include "Carrito.cpp"
#include "ProductoCarrito.h"
#include "ProductoCarrito.cpp"

using namespace std;

int main(){
    char menu = '0';
    string compra = "no";
    char editar = ' ';
    string op = "no";
    int indexProducto = 0;

    string id = "";
    string nombre = "";
    string nombrec = "";
    double precio = 0.0;
    int cantidad = 0;
    int existencia = 0;
    ProductoAlmacen lista[20];

    //cargar archivo
    cout<<"Nombre del cliente: ";
    getline(cin,nombrec);
    int productos = 0;
    ifstream archivo("productos.txt");
    string precio2,cantidad2;
    string linea;
    while(getline(archivo,linea)){
        stringstream ss(linea);
        getline(ss,id, ',');
        getline(ss,nombre, ',');
        getline(ss,precio2, ',');
        precio = stod(precio2);
        getline(ss,cantidad2, ',');
        cantidad = stoi(cantidad2);
        ProductoAlmacen producto(id,nombre,precio,cantidad);
        lista[productos] = producto;
        productos+=1;
    }
    
    Almacen almacen(lista,productos);
    Carrito carrito(nombrec,0);
   
    //Menu princial
    while (menu != '6'){
        cout<<"1) Ver almacen"<<endl;
        cout<<"2) Comprar"<<endl;
        cout<<"3) Ver carrito"<<endl;
        cout<<"4) Editar"<<endl;
        cout<<"5) Pagar"<<endl;
        cout<<"6) Salir\nOpcion: ";
        cin>>menu;

        switch (menu){
        case '1':
            almacen.verProductos();
            break;
        case '2':
            compra = "no";
            while (compra == "no"  ){
                cout<<"\nProducto a comprar:\nID: ";
                cin>>id;
                indexProducto = almacen.buscarProductos(id);
                //si te devuelve un index valido, el producto existe y continua el proceso
                if (indexProducto != -1){
                    do {
                        cout<<"Cantidad (mayor a 0): ";
                        cin>>cantidad;
                    }while(cantidad <= 0);
                    //revisa si es posible realizar la venta
                    if (almacen.revisarExistencia(indexProducto,cantidad)){
                        cout<<"Los datos ingresados son correctos? (si,no):";
                        cin>>compra;
                        ///añade el producto al carrito
                        if(compra == "si"){
                            existencia = almacen.getExistencia(indexProducto);
                            ProductoCarrito producto (id,almacen.nombreProducto(indexProducto),almacen.precioProducto(indexProducto),cantidad);
                            carrito.add(producto,existencia);
                        }else{
                            compra = "no";
                        }
                    }
                }else{
                    cout<<"Este producto no existe"<<endl;
                    cout<<"Desea cancelar (si,no)"<<endl;
                    cin>>compra;
                }          
            }
            break;
        case '3':
            carrito.verCarrito();
            break;
        case '4':
            cout<<"1) Editar cantidad de un producto"<<endl;
            cout<<"2) Eliminar un producto"<<endl;
            cin>>editar;
            switch (editar){
                case '1':
                    op ="no";
                    while (op == "no"){
                        cout<<"\nId del producto: ";
                        cin>>id;
                        indexProducto = carrito.buscarProducto(id);
                        //si te devuelve un index valido, el producto existe en el carrito y continua el proceso
                        if (indexProducto != -1){
                            cout<<"Nueva Cantidad: ";
                            cin>>cantidad;
                            //revisa si es posible realizar la venta
                            if (almacen.revisarExistencia(indexProducto,cantidad)){
                                cout<<"Los datos que ingresaste son correctos? (si,no)";
                                cin>>op;
                                if (op == "si"){
                                    carrito.cambiarCantidad(indexProducto,cantidad);
                                }else{
                                    op = "no";
                                }
                            }
                        }else{
                            cout<<"Este producto no está en el carrito"<<endl;
                            cout<<"Desea cancelar (si,no)"<<endl;
                            cin>>op;
                        }
                    }
                    break;
                case '2':
                    op = "no";
                    while(op == "no"){
                        cout<<"\nId del producto: ";
                        cin>>id;
                        //si te devuelve un index valido, el producto existe en el carrito y continua el proceso
                        indexProducto = carrito.buscarProducto(id);
                        if (indexProducto != -1){
                            cout<<"Esta seguro de eliminar el articulo del carrito? (si,no)";
                            cin>>op;
                            if (op == "si"){
                                carrito.eliminarProducto(indexProducto);
                            }else{
                                op = "si";
                            }
                        }else{
                            cout<<"Este producto no esta en el carrito"<<endl;
                            cout<<"Desea cancelar (si,no)"<<endl;
                            cin>>op;
                        }
                    }
                    break;
            }
            break;
        case '5':
            for (int i = 0; i<carrito.getSize();i++){
                //obtiene los ID y cantidad de los productos del carro y los reduce en el almacen
                almacen.reducirExistencia(carrito.getIDS(i),carrito.getCantidades(i));
            }
            cout<<"EL total de su compra es: "<<carrito.total()<<"\nGracias por su compra"<<endl;
            carrito.vaciarCarrito();
            //ingresa nuevo cliente
            cout<<"\nNombre del cliente: ";
            cin.ignore();
            getline(cin,nombrec);
            carrito.setCliente(nombrec);
            break;
        }
    } 
}