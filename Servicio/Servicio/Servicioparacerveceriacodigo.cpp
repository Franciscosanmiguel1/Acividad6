//Buenas profesor. Acá encontrará el programa descrito en la actividad 5
//Acá se incluyen las bibliotecas mencionadas en el documento descriptivo
﻿#include <iostream>
#include <map>
#include <iomanip>
#include <algorithm>

using namespace std;
//Acá se creó la estructura de la interfaz
struct Ventas {
    int cantidad;
    double total;
};
//Esta función permite al programa distinguir entre mayusculas y minusculas.
string minusMayus(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}
//Mapa donde se almacenan los precios de cada producto.
int main() {
    map<string, double> precios = {
        {"Cerveza", 5000.0},
        {"Ron", 250000.0},
        {"Whisky", 100000.0},
        {"Tequila", 200000.0},
        {"Soda", 3000.0},
        {"Agua", 2000.0}
    };
    //Mapa que contiene los precios convertidos en minusculas y los almacena en el mapa.
    map<string, double> preciosMinusculas;
    //El bucle for convierte los nombres de los productos a minusculas y
    for (const auto& par : precios) {
        preciosMinusculas[minusMayus(par.first)] = par.second;
    }
    //Mapa que contiene las ventas de los productos
    map<string, Ventas> ventas;
    //Variable para la respuesta del usuario
    string respuesta;
    //Este bucle do es para ingresar las ventas.
    do {
        string producto;
        //Solicita al usuario ingresar el tipo de producto.
        int cantidad;
        cout << "Ingrese el tipo de producto: ";
        cin >> producto;
        //Esta función permite al programa detectar si el producto ingresado está en minusculas.
        producto = minusMayus(producto);

        //Esta estructura condicional If permite la validación del producto ingresado.
        if (preciosMinusculas.find(producto) == preciosMinusculas.end()) {
            cout << "Producto no válido/inexistente." << endl;
            continue;
        }

        cout << "Ingrese la cantidad vendida de " << producto << ": ";
        //Esta otra verifica si la cantidad ingresada no es un número igual a 0 o negativo.
        if (!(cin >> cantidad)) {
            cout << "Cantidad no válida. Intente nuevamente." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        //Esta declaración calcula las ganancias totales.
        double totalVentas = cantidad * preciosMinusculas[producto];
        //Esta asignación actualiza el mapa de ventas con las nuevas ventas ingresadas.
        ventas[producto].cantidad += cantidad;
        ventas[producto].total += totalVentas;
        //Este dialogo le pregunta al usuario si quiere ingresar otra venta.
        cout << "¿Desea ingresar otra venta? (Escriba Si o No): ";
        cin >> respuesta;
        //Con esta función el programa permite al usuario escribir su respuesta en minusculas.
        respuesta = minusMayus(respuesta);
    //Este bucle while lee la respuesta.
    } while (respuesta == "si" || respuesta == "Si");
    //Acá se imprime el reporte de ventas. Los "-" (guiones) separan visualmente las secciones del reporte de ventas.
    cout << "-" << endl;
    cout << "Reporte de ventas: " << endl;
    cout << "-" << endl;
    //Acá se imprimen todos los detalles de la venta.
    cout << "Detalles de las ventas: " << endl;
    for (const auto& venta : ventas) {
        cout << "Producto: " << venta.first << ", ";
        cout << "Cantidad: " << venta.second.cantidad << ", ";
        cout << "Total: COP" << fixed << setprecision(2) << venta.second.total << endl;
    }
    //Esta declaración calcula e imprime los ingresos totales.
    double ingresostotales = 0.0;
    for (const auto& venta : ventas) {
        ingresostotales += venta.second.total;
    }
    //Por último estas 2 lineas se encargan de dar el ingreso total y de un mensaje de despedida.
    cout << "Ingresos Totales: COP" << fixed << setprecision(2) << ingresostotales << endl;
    
    cout << "¡Reporte Completado! Para iniciar otro reporte, reinicie el programa." << endl;

    return 0;
}
