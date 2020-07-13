#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

const int longCad = 20;

struct CostoXArticulo{
	char nombre[longCad + 1];
    int cantidad;
    float precio;
    float costo;
};

void producto(CostoXArticulo cantidad1[100],int num){

    for(int i=0; i<num; i=i+1) {
    	
    	//se vaia el buffer
        fflush(stdin);
        
        cout << "Ingrese el nombre del producto "<<i+1<<": ";
        cin.getline(cantidad1[i].nombre,20,'\n');
        
        cout<<"Ingrese la cantidad de productos:";
        cin>>cantidad1[i].cantidad;
        
        //Tiene que ser una compra minima para que se cumpla el ciclo y un maximo de 100 compras
        while(cantidad1[i].cantidad<=0||cantidad1[i].cantidad>100){
        	
        if(cantidad1[i].cantidad<=0){
        cout<<"Ingrese una cantidad de productos mayor a 0 para comprar este articulo:"<<endl;
        cin>>cantidad1[i].cantidad;
        }
        
		else{
			
        cout<<"No es permitido comprar mas de 100 productos por articulos."<<endl;
        cout<<"Por favor ingrese una cantidad de productos menor a 100:"<<endl;
        cin>>cantidad1[i].cantidad;
        
        }
        }

        cout<<"Ingrese el precio del producto:";
        cin>>cantidad1[i].precio;
        
        while(cantidad1[i].precio<=0 || cantidad1[i].precio>1000){
        	
        cout<<"Los precios establecidos no sobrepasan los $1000.00 y deben ser mayores a $0.00:"<<endl;
        cin>>cantidad1[i].precio;
        
        }
        cout<<endl;
    }
}
void fac(CostoXArticulo cantidad1[100],int num){
	
    for(int i=0; i<num; i=i+1){
    	
        cout<<"Nombre del producto: "<<cantidad1[i].nombre<<endl;
        cout<<"Cantidad de productos comprados: "<<cantidad1[i].cantidad<<endl;
        cout<<"Precio del producto por unidad: $"<<cantidad1[i].precio<<endl;
        cout<<"Compra total de articulo: $"<<cantidad1[i]. costo<<endl;
        cout<<endl;
    }
}
void calcular(CostoXArticulo cantidad1[100],int num){
	
    for(int i=0; i<num; i=i+1){
    	
        int articulos=0;
        float precioUnitario=0;
        
        articulos=cantidad1[i].cantidad;
        precioUnitario=cantidad1[i].precio;
        
        //Se calcula la cantidad de dinero total por articulo
        cantidad1[i].costo=(articulos*precioUnitario);
    }
}
float total2(CostoXArticulo cantidad1[100],int num){
	
    float total=0;
    
    for(int i=0; i<num; i=i+1){
    	
       total=total+cantidad1[i].costo;
    }
    return total;
}

int main(void){
	
    int num;
    float total;
    
    CostoXArticulo cantidad1[100];
    
    cout<<"Ingrese la cantidad de articulos:";
    cin>>num;
    
    /*En este bloque hacemos que el usuario ingrese una cantidad que sea mayor
    a 0 o que sea menor a 100 si no es asi imprimira un mensaje que ingrese un numero en el rango*/
    while(num<1||num>100){
    	
    cout<<"Debe ingresar un numero de productos mayor a 0 y menor a 100: ";
    cin>>num;
    
    }

    cout<< endl;
    
    producto(cantidad1,num);
    calcular(cantidad1,num);
    
    cout<<"Lista de productos comprados"<<endl;
    
    fac(cantidad1,num);
    
    total=total2(cantidad1, num);
    
    cout<<endl << "Total a pagar:"<<total<<" Dolares";

  return 0;
}
