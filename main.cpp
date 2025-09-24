#include <iostream>

int codigo[5]={101,102,103,104,105}
    ,stock[5]={50,120,75,45,10};
float precio[5]={15.50f,8.75f,20.00f,25.99f,120.00f };
std::string Nombre[5] ={
    "Martillo de bola",
    "Destornillador",
    "Cinta métrica",
    "Llave inglesa",
    "Taladro inalámbrico"
};



int verifica_numericos();
void report_jungla();

int main() {
    std::cout << "---- Bienvenido al sistema de Inventario de El Martillo ---"<<std::endl<<std::endl;
    while (true){        
        std::cout << "Seleccione una opción:"<<std::endl;
        std::cout << "1. Consultar un producto"<<std::endl;
        std::cout << "2. Actualizar inventariado"<<std::endl;
        std::cout << "3. Generar reporte completo"<<std::endl;
        std::cout << "4. Encontrar el producto más caro"<<std::endl;
        std::cout << "5. Salir"<<std::endl<<std::endl;
        int opcion=0;

        opcion = verifica_numericos();
        if(opcion == -1){continue;}
        if (!(opcion >= 1 && opcion<=5)){
            std::cout << "Esa opcion ni existe :/"<<std::endl<<std::endl;
            continue;
        }
        std::cout<<std::endl;

        switch (opcion){
        case 1:

            break;
        case 2:

            break;
        case 3:
            report_jungla();
            break;
        case 4:

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

void report_jungla(){
    for (int i = 0; i < 5; i++){
        std::cout<<codigo[i] <<Nombre[i]<<stock[i]<<precio[i]<<std::endl;
    }
        std::cout<<std::endl;
}

int verifica_numericos(){
        int valor = 0;
        std::cout << "Opción seleccionada: ";
        std::cin >> valor;
        if(!(std::cin.good())){ // aqui valida si no hubo error al ingresar un dato
            //cin.god si da tru es por que no hubo error, aqui verifico que sea diferente de tru
            std::cin.clear();//elimina el estado del cin.good ya no es de error
            /*aqui aviendo un ciclo que me este sacando los datotes
            mientras sean diferentes al salto de linea o enter como tengo entendido*/
            while(std::cin.get() != '\n'){}//no hace nada el ciclo pero saca todo del cache
            
            std::cout << "caracter no valido:Se Espera un numero"<<std::endl<<std::endl;
            //como se ingreso un dato erroneo se devuelve un dato que no acepten los otros parametros
            return -1;
        }
    return valor;
}