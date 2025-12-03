#include <iostream>
#include <string>

using namespace std;

const int MAX = 100;

struct Producto { 
    string nombre;
    float precio;
    int cantidad;
};

Producto inventario[MAX];
int cantidadActual = 0;

void mostrarProductos() { 
    if (cantidadActual == 0) {
        cout << "No hay productos registrados." << endl;
        return;
    }

    cout << "\n===== LISTA DE PRODUCTOS =====" << endl;
    cout << "Nombre\t\tPrecio\t\tCantidad" << endl;
    cout << "----------------------------------------" << endl;

    for (int i = 0; i < cantidadActual; i++) {
        cout << inventario[i].nombre << "\t\t";
        cout << inventario[i].precio << "\t\t";
        cout << inventario[i].cantidad << endl;
    }
    cout << "----------------------------------------" << endl;
}

void ordenarProductosBurbuja() {
    if (cantidadActual == 0) return;

    Producto copia[MAX];
    for (int i = 0; i < cantidadActual; i++) {
        copia[i] = inventario[i];
    }

    Producto aux;
    for (int i = 0; i < cantidadActual - 1; i++) {
        for (int j = 0; j < cantidadActual - 1 - i; j++) {
            if (copia[j].precio > copia[j + 1].precio) {
                aux = copia[j];
                copia[j] = copia[j + 1];
                copia[j + 1] = aux;
            }
        }
    }
    
    cout << "Productos ordenados por precio (Burbuja)." << endl;
    cout << "Nombre\t\tPrecio\t\tCantidad" << endl;
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < cantidadActual; i++) {
        cout << copia[i].nombre << "\t\t";
        cout << copia[i].precio << "\t\t";
        cout << copia[i].cantidad << endl;
    }
    cout << "----------------------------------------" << endl;
}

void ordenarProductosSeleccion() {
    if (cantidadActual == 0) return;

    Producto copia[MAX];
    for (int i = 0; i < cantidadActual; i++) {
        copia[i] = inventario[i];
    }

    for (int i = 0; i < cantidadActual - 1; i++) {
        int indiceMenor = i;
        for (int j = i + 1; j < cantidadActual; j++) {
            if (copia[j].precio < copia[indiceMenor].precio) {
                indiceMenor = j;
            }
        }
        if (indiceMenor != i) {
            Producto aux = copia[i];
            copia[i] = copia[indiceMenor];
            copia[indiceMenor] = aux;
        }
    }
    
    cout << "Productos ordenados por precio (Seleccion)." << endl;
    cout << "Nombre\t\tPrecio\t\tCantidad" << endl;
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < cantidadActual; i++) {
        cout << copia[i].nombre << "\t\t";
        cout << copia[i].precio << "\t\t";
        cout << copia[i].cantidad << endl;
    }
    cout << "----------------------------------------" << endl;
}

void ordenarProductosInsercion() {
    if (cantidadActual == 0) return;

    Producto copia[MAX];
    for (int i = 0; i < cantidadActual; i++) {
        copia[i] = inventario[i];
    }

    for (int i = 1; i < cantidadActual; i++) {
        Producto aux = copia[i];
        int j = i - 1;
        while (j >= 0 && copia[j].precio > aux.precio) {
            copia[j + 1] = copia[j];
            j--;
        }
        copia[j + 1] = aux;
    }
    
    cout << "Productos ordenados por precio (Insercion)." << endl;
    cout << "Nombre\t\tPrecio\t\tCantidad" << endl;
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < cantidadActual; i++) {
        cout << copia[i].nombre << "\t\t";
        cout << copia[i].precio << "\t\t";
        cout << copia[i].cantidad << endl;
    }
    cout << "----------------------------------------" << endl;
}

void menuOrdenar() {
    if (cantidadActual == 0) {
        cout << "No hay productos para ordenar." << endl;
        return;
    }

    int sub;
    cout << "\nSeleccione metodo de ordenamiento:" << endl;
    cout << "1. Burbuja" << endl;
    cout << "2. Seleccion" << endl;
    cout << "3. Insercion" << endl;
    cout << "Opcion: ";
    cin >> sub;

    switch(sub) {
        case 1: ordenarProductosBurbuja(); break;
        case 2: ordenarProductosSeleccion(); break;
        case 3: ordenarProductosInsercion(); break;
        default: cout << "Metodo no valido." << endl;
    }
}

void registrarProductos() { 
    int n;
    cout << "¿Cuantos productos desea registrar? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        if (cantidadActual >= MAX) {
            cout << "¡Error! El inventario esta lleno." << endl;
            break;
        }
        cout << "\nProducto " << cantidadActual + 1 << ":" << endl;
        cout << "Nombre: ";
        cin >> inventario[cantidadActual].nombre;
        cout << "Precio: ";
        cin >> inventario[cantidadActual].precio;
        while(inventario[cantidadActual].precio < 0) {
             cout << "Precio invalido. Ingrese precio positivo: ";
             cin >> inventario[cantidadActual].precio;
        }
        cout << "Cantidad: ";
        cin >> inventario[cantidadActual].cantidad;
        cantidadActual++;
    }
    cout << "Productos registrados exitosamente." << endl;
}

void buscarProducto() { 
    if (cantidadActual == 0) {
        cout << "No hay productos para buscar." << endl;
        return;
    }
    string nombreBuscado;
    bool encontrado = false;
    cout << "Ingrese el nombre a buscar: ";
    cin >> nombreBuscado;

    for (int i = 0; i < cantidadActual; i++) {
        if (inventario[i].nombre == nombreBuscado) {
            cout << "Producto encontrado: " << endl;
            cout << "Nombre: " << inventario[i].nombre << endl;
            cout << "Precio: " << inventario[i].precio << endl;
            cout << "Cantidad: " << inventario[i].cantidad << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) cout << "Producto no encontrado." << endl;
}

void actualizarProducto() { 
    if (cantidadActual == 0) {
        cout << "No hay productos para actualizar." << endl;
        return;
    }
    int indice;
    cout << "Ingrese el indice del producto (0 a " << cantidadActual - 1 << "): ";
    cin >> indice;

    if (indice < 0 || indice >= cantidadActual) {
        cout << "Error: Indice no valido." << endl;
        return;
    }

    int opcion;
    cout << "Actualizando: " << inventario[indice].nombre << endl;
    cout << "¿Que desea actualizar? 1. Precio  2. Cantidad: ";
    cin >> opcion;

    if (opcion == 1) {
        cout << "Nuevo precio: ";
        cin >> inventario[indice].precio;
    } else if (opcion == 2) {
        cout << "Nueva cantidad: ";
        cin >> inventario[indice].cantidad;
    } else {
        cout << "Opcion no valida." << endl;
    }
    cout << "Producto actualizado." << endl;
}

void generarReporte() {
    if (cantidadActual == 0) {
        cout << "No hay datos para reporte." << endl;
        return;
    }
    float total = 0;
    int idxMayor = 0;
    
    for (int i = 0; i < cantidadActual; i++) {
        total += (inventario[i].precio * inventario[i].cantidad);
        if (inventario[i].cantidad > inventario[idxMayor].cantidad) {
            idxMayor = i;
        }
    }
    
    cout << "\n===== REPORTE FINAL =====" << endl;
    cout << "Total de productos: " << cantidadActual << endl;
    cout << "Valor total inventario: $ " << total << endl;
    cout << "Producto con mayor stock: " << inventario[idxMayor].nombre 
         << " (" << inventario[idxMayor].cantidad << ")" << endl;
}

int main() {
    int opcion;
    do {
        cout << "\n===== SISTEMA BASICO DE GESTION DE PRODUCTOS =====" << endl;
        cout << "1. Registrar productos" << endl;
        cout << "2. Mostrar productos" << endl;
        cout << "3. Ordenar productos" << endl;
        cout << "4. Buscar producto" << endl;
        cout << "5. Actualizar producto" << endl;
        cout << "6. Generar reporte final" << endl;
        cout << "7. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: registrarProductos(); break;
            case 2: mostrarProductos(); break;
            case 3: menuOrdenar(); break; 
            case 4: buscarProducto(); break;
            case 5: actualizarProducto(); break;
            case 6: generarReporte(); break;
            case 7: cout << "Saliendo..." << endl; break;
            default: cout << "Opcion no valida." << endl;
        }
    } while (opcion != 7);

    return 0;
}