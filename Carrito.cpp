#include <string>
#include <iostream>
#include "Carrito.h"
#include "ProductoCarrito.h"
using namespace std;

Carrito::Carrito(string cliente,int size){
    this->cliente = cliente;
    for (int i = 0; i<size;i++){
        this->productos[i] = productos[i];
    }
    this->size = size;
}

double Carrito::total(){
    double total = 0.0;
    for (int i = 0; i<size;i++){
        total += this->productos[i].subTotal();
    }

    return total;
}

void Carrito::add(ProductoCarrito producto, int existencia){
    bool existe = false;
    int cantidadSuma = 0;
    
    //revisa si el carrito está lleno
    if(size != 10){
        //ciclo que revisa si el producto ingresado ya existe y si es el caso suma la cantidad al carrito
        //si la suma es mayor a la existencia del producto, no realiza la suma
        for (int i = 0; i<size; i++){
            if (this->productos[i].getID() == producto.getID()){
                cantidadSuma += this->productos[i].getCantidad() + producto.getCantidad();
                if (existencia >=  cantidadSuma){
                    this->productos[i].setCantidad(cantidadSuma);
                    cout<<"La cantidad se sumo al carrito\n"<<endl;

                }else{
                    cout<<"La cantidad total en el carrido de este producto es mayor a su existencia\n"<<endl;
                }
                existe = true;
            }
        }//si el producto no existe en el carrito solo lo agrega 
        if (existe == false){
            productos[size] = producto;
            this->size += 1;
            cout<<"El Producto ahora está en el carrito\n"<<endl;
        }
    }else{
        cout<<"El carrito está lleno"<<endl;
    }   
}
    
void Carrito::verCarrito(){
    cout<<"----------------------------------------"<<endl;
    cout<<"Carrito de: "<<this->cliente<<endl;
    cout<<"ID,Nombre,Precio,Cantidad,Subtotal"<<endl;
    for (int i = 0; i<size; i++){
        this->productos[i].verProducto();
    }
    cout<<"Total: "<<this->total()<<endl;
    cout<<"----------------------------------------"<<endl;
}

int Carrito::buscarProducto(string id){
    //busca el producto en el almacen y regresa el indice del producto en la lista
     for (int i = 0; i<size;i++){
        if (id == productos[i].getID()){
            return i;
        }
    }

    return -1;
}

void Carrito::cambiarCantidad(int index, int cantidad){
    //cambia la cantidad del producto en el carrito o lo elimina si esta es menor o igual a 0
    if(cantidad > 0){
        productos[index].setCantidad(cantidad);
    }else{
        this->eliminarProducto(index);
    }

    cout<<"La cantidad fue modificada\n"<<endl;
}

void Carrito::eliminarProducto(int index){
    //recorre los espacios del arreglo para eliminar el del index recibido
    for (int i = index; i <(size-1);i++){
        this->productos[i] = productos[i+1]; 
    }
    this->size -= 1;
    cout<<"El producto fue eliminado\n"<<endl;
}

void Carrito::vaciarCarrito(){
    this->size = 0;
}

string Carrito::getIDS(int index){
    return this->productos[index].getID();
}

int Carrito::getCantidades(int index){
    
    return this->productos[index].getCantidad(); 
    
}

int Carrito::getSize(){
    return this->size;
}

void Carrito::setCliente(string cliente){
    this->cliente = cliente;
}