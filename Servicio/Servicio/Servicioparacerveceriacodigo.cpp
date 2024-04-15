#include <iostream>
#include <map>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Ventas {
    int cantidad;
    double total;
};

string minusMayus(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int main() {
    map<string, double> precios = {
        {"Cerveza", 5000.0},
        {"Ron", 250000.0},
        {"Whisky", 100000.0},
        {"Tequila", 200000.0},
        {"Soda", 3000.0},
        {"Agua", 2000.0}
    };

    map<string, double> preciosMinusculas;
    for (const auto& par : precios) {
        preciosMinusculas[minusMayus(par.first)] = par.second;
    }

    map<string, Ventas> ventas;
    string respuesta;

    do {
        string producto;
        int cantidad;
        cout << "Ingrese el tipo de producto: ";
        cin >> producto;

        producto = minusMayus(producto);

        // Validación del producto ingresado
        if (preciosMinusculas.find(producto) == preciosMinusculas.end()) {
            cout << "Producto no válido/inexistente." << endl;
            continue;
        }

        cout << "Ingrese la cantidad vendida de " << producto << ": ";
        // Validación de entrada para la cantidad vendida
        if (!(cin >> cantidad)) {
            cout << "Cantidad no válida. Intente nuevamente." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        double totalVentas = cantidad * preciosMinusculas[producto];

        ventas[producto].cantidad += cantidad;
        ventas[producto].total += totalVentas;

        cout << "¿Desea ingresar otra venta? (Escriba Si o No): ";
        cin >> respuesta;
        respuesta = minusMayus(respuesta);

    } while (respuesta == "si" || respuesta == "Si");

    cout << "-" << endl;
    cout << "Reporte de ventas: " << endl;
    cout << "-" << endl;

    cout << "Detalles de las ventas: " << endl;
    for (const auto& venta : ventas) {
        cout << "Producto: " << venta.first << ", ";
        cout << "Cantidad: " << venta.second.cantidad << ", ";
        cout << "Total: COP" << fixed << setprecision(2) << venta.second.total << endl;
    }

    double ingresostotales = 0.0;
    for (const auto& venta : ventas) {
        ingresostotales += venta.second.total;
    }

    cout << "Ingresos Totales: COP" << fixed << setprecision(2) << ingresostotales << endl;

    cout << "¡Reporte Completado! Para iniciar otro reporte, reinicie el programa." << endl;

    return 0;
}
