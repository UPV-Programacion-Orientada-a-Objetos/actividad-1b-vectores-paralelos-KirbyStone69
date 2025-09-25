#include <iostream>
#include <iomanip>

int codigo_producto[5]={101,102,103,104,105}
    ,stock_producto[5]={50,120,75,45,10};
float precio_producto[5]={15.50f,8.75f,20.00f,25.99f,120.00f };
std::string nombre_producto[5] ={
    "Martillo de bola",
    "Destornillador",
    "Cinta metrica",
    "Llave inglesa",
    "Taladro inalambrico"
};


int verifica_numericos(std::string mensaje);
void buscar_mayor_precio();
void reporte();
void consulta_producto();
void modificar_stock();

int main() {
    std::cout << "---- Bienvenido al sistema de Inventario de El Martillo ---"<<std::endl;
    while (true){     
        std::cout<<"--- Menú principal ---"<< std::endl<< std::endl; 
        
        std::cout << "Seleccione una opción:"<<std::endl;
        std::cout << "1. Consultar un producto"<<std::endl;
        std::cout << "2. Actualizar inventariado"<<std::endl;
        std::cout << "3. Generar reporte completo"<<std::endl;
        std::cout << "4. Encontrar el producto más caro"<<std::endl;
        std::cout << "5. Salir"<<std::endl<<std::endl;
        int opcion=0;

        opcion = verifica_numericos("Opción seleccionada");
        if(opcion == -1){continue;}
        if (!(opcion >= 1 && opcion<=5)){
            std::cout << "Esa opcion no existe"<<std::endl<<std::endl;
            continue;
        }

        switch (opcion){
        case 1:
            consulta_producto();
            break;
        case 2:
            modificar_stock();
            break;
        case 3:
            reporte();
            break;
        case 4:
            buscar_mayor_precio();
            break;
        case 5:
            return 0; // pa cerrar eto. 
            break;
        default:
            break;
        }
    }
    return 0;
}


void consulta_producto(){
    int codigo_consultado=0;
    int index_encontrado=-1; //inicializo en -1 por si hay algun error
    codigo_consultado=verifica_numericos("Ingrese el código del producto a consultar");
    for (int i = 0; i < 5; i++){
        //busca el codigo consultado si lo encuentra guarda el index
        if (codigo_producto[i] == codigo_consultado){
            index_encontrado = i;
            //se cierra el ciclo por que ya para que voy a andar buscando
            break;
        }
    }
    //lo encuentre o no lo en
    if (index_encontrado != -1){
        std::cout<<"Información del Producto :"<<std::endl;
        std::cout<<"Código: "<< codigo_producto[index_encontrado] <<std::endl;
        std::cout<<"Nombre: "<< nombre_producto[index_encontrado] <<std::endl;
        std::cout<<"Cantidad en stock: "<< stock_producto[index_encontrado] <<std::endl;
        std::cout<<"Precio unitario: $"<< precio_producto[index_encontrado] <<std::endl<<std::endl;
    }else{std::cout<<"Código de producto invalido"<<std::endl<<std::endl;}
    
}


int verifica_numericos(std::string mensaje){
        int valor = 0;
        std::cout << mensaje<<": ";
        std::cin >> valor;
        std::cout<<std::endl;
        if(!(std::cin.good())){ // aqui valida si no hubo error al ingresar un dato
            //cin.god si da tru es por que no hubo error, aqui verifico que sea diferente de tru
            std::cin.clear();//elimina el estado del cin.good ya no es de error
            /*aqui aviendo un ciclo que me este sacando los datotes
            mientras sean diferentes al salto de linea o enter como tengo entendido*/
            while(std::cin.get() != '\n'){}//no hace nada el ciclo pero saca todo del cache / buffer del cin
            
            std::cout << "caracter no valido:Se Espera un numero"<<std::endl<<std::endl;
            //como se ingreso un dato erroneo se devuelve un dato que no acepten los otros parametros
            return -1;
        }
    return valor;
}

void buscar_mayor_precio(){
    int valor=0, centinela=0;

    for (int i = 0; i < 5; i++){
        if (precio_producto[i]>valor){
            valor = precio_producto[i];
            centinela = i;
        }
    }
    std::cout<<"El producto más caro es: "<< nombre_producto[centinela]<<" con un precio de $"<<precio_producto[centinela]<<std::endl;
}

void reporte(){
    std::cout<< "--- Reporte de Inventario ---"<< std::endl;
    std::cout<< std::left <<std::setw(9)<< "Codigo"<<"|"
                            << std::setw(25)<<"Nombre"<<"|"
                            << std::setw(9)<<"Stock"<<"|"
                            << std::setw(9)<<"Precio"<< std::endl;
    std::cout<< "-------------------------------------------------------"<< std::endl;
    //aqui use setw de la libreria iomanip para que se vea mas bonito
    for (int i = 0; i < 5; i++){
        std::cout<< std::left <<std::setw(9)<< codigo_producto[i]<<"|"
                                << std::setw(25)<<nombre_producto[i]<<"|"
                                << std::setw(9)<<stock_producto[i]<<"|"
                                << std::setw(9)<<precio_producto[i]<< std::endl;
    }
        std::cout<<std::endl;
}

void modificar_stock(){
    int codigo_consultado=0;
    int in_en=-1; //inicializo en -1 por si hay algun error
    codigo_consultado=verifica_numericos("Ingrese el código del producto a actualizar");
    for (int i = 0; i < 5; i++){
        //busca el codigo consultado si lo encuentra guarda el index
        if (codigo_producto[i] == codigo_consultado){
            in_en = i;
            //se cierra el ciclo por que ya para que voy a andar buscando
            break;
        }
    }

    if (in_en != -1){
        std::cout<<"stock actual de "<< nombre_producto[in_en]<<" es de " <<stock_producto[in_en]<<std::endl;

        int suma=0;
        int nuevo_stock;
        suma = verifica_numericos("Ingrese la cantidad a sumar");
        if (suma == 0){
            std::cout<<"No puedes sumar 0 al stock"<<std::endl;
        }else if ((stock_producto[in_en]+suma)< 0){
            std::cout<<"Cantidad no valida para ingresar"<<std::endl;
        }else{
            stock_producto[in_en] += suma;
        }
        
            std::cout<<"stock actual de "<< nombre_producto[in_en]<<" es de " <<stock_producto[in_en]<<std::endl;
    }else{std::cout<<"cantidad de a sumar no valida"<<std::endl<<std::endl;}
    
}
