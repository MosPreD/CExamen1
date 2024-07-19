#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct producto {
    char nombreProducto[25];
    char marcaProducto[25];
    float precioCosto;
    float precioVenta;
    int cantidad;
    int codigoBarra;
    struct producto* siguiente;
} Producto;

void menu();
void cargarProductos(Producto** lista);
void imprimirProductos(Producto* lista);
void estadisticas(Producto* lista);

int generarCodigoBarra(Producto* lista);

int main() {
    srand(time(NULL));
    menu();
    return 0;
}

void menu() {
    int opcion;
    Producto* lista = NULL;

    while (1) {
        printf("Menu de Catalogo de Productos:\n");
        printf("Seleccione una opcion \n");
        printf("1- Generar productos\n2- Imprimir productos\n3- Ver estadisticas\n4- Salir\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);
        system("cls");

        switch (opcion) {
            case 1:
			    if(lista == NULL) 
				{
					printf("Opcion %i seleccionada: Generar productos\n");
			        cargarProductos(&lista);
			        printf("Productos cargados:\n");
			        imprimirProductos(lista);
			    } 
				else 
				{
			        printf("La lista de productos ya ha sido generada anteriormente.\n");
			    }
		    break;

            case 2:
                printf("Opcion %i seleccionada: Imprimir productos\n", opcion);
                imprimirProductos(lista);
                break;
            case 3:
                printf("Opcion %i seleccionada: Ver estadisticas\n", opcion);
                estadisticas(lista);
                break;
            case 4:
                printf("Opcion %i seleccionada: Saliendo del programa\n", opcion);
                exit(0);
                break;
            default:
                printf("Opcion invalida, vuelva a ingresar.\n");
                break;
        }
    }
}

void cargarProductos(Producto** lista) {
    int i, s;
    char nombreProducto[][25] = { "Gaseosa", "Panificados", "Cerveza", "Carne", "Embutidos", "Chocolates", "Jugos", "Verduras", "Frutas", "Lacteos" };
    char MarcaProducto[][25] = { "Lactolanda", "Frugos", "Brahma", "Pechugon", "Arcor", "Nikito", "Pilsen", "Ochi", "Caricia", "Sprim" };
    
    int cantidadFamilias=11 + rand()%59;
    printf("Cantidad de familias de productos a generar: %d\n", cantidadFamilias);

    for (i = 0; i < cantidadFamilias; i++) {
        Producto* nuevoProducto = (Producto*)malloc(sizeof(Producto));
        
        s = rand() % 10;
        strcpy(nuevoProducto->nombreProducto, nombreProducto[s]);
        s = rand() % 10;
        strcpy(nuevoProducto->marcaProducto, MarcaProducto[s]);
        
        nuevoProducto->precioCosto = 1000 + rand()%49501 + rand()%49501;
        nuevoProducto->precioVenta = nuevoProducto->precioCosto + rand() % 25001 + rand() % 25001;

        nuevoProducto->cantidad = rand() % 501;

        nuevoProducto->codigoBarra = generarCodigoBarra(*lista);
        
        nuevoProducto->siguiente = *lista;
        *lista = nuevoProducto;
    }
}

int generarCodigoBarra(Producto* lista) {
    int codigo;
    int unico;
    do {
        unico = 1;
        codigo = 100001 + rand() % 450001 + rand() % 450001;
        Producto* actual = lista;
        while (actual != NULL) {
            if (actual->codigoBarra == codigo) {
                unico = 0;
                break;
            }
            actual = actual->siguiente;
        }
    } while (!unico);
    return codigo;
}

void imprimirProductos(Producto* lista) {
    if (lista == NULL) {
        printf("No hay productos cargados.\n");
        return;
    }
    printf("Productos cargados:\n");
    Producto* actual = lista;
    while (actual != NULL) {
        printf("Producto: %s\n", actual->nombreProducto);
        printf("Marca: %s\n", actual->marcaProducto);
        printf("Precio al costo: %.2f\n", actual->precioCosto);
        printf("Precio de venta: %.2f\n", actual->precioVenta);
        printf("Cantidad: %d\n", actual->cantidad);
        printf("Código de barra: %d\n", actual->codigoBarra);
        printf("-------------------------\n");
        actual = actual->siguiente;
    }
}

void estadisticas(Producto* lista) {
	int i;
    int unidadesPorFamilia[10] = {0};
    int productosPorMarca[10] = {0};
    float inversionTotal = 0.0;
    float gananciaEsperada = 0.0;
    char nombreProducto[][25] = { "gaseosa", "panificados", "cerveza", "carne", "embutidos", "chocolates", "jugos", "verduras", "frutas", "lacteos" };
    char MarcaProducto[][25] = { "Lactolanda", "Frugos", "Brahma", "Pechugón", "Arcor", "Nikito", "Pilsen", "Ochsi", "Caricia", "Sprim" };
    Producto* actual = lista;
    while (actual != NULL) {
        for (i = 0; i < 10; i++) {
            if (strcmp(actual->nombreProducto, nombreProducto[i]) == 0) {
                unidadesPorFamilia[i] += actual->cantidad;
                break;
            }
        }
        for (i = 0; i < 10; i++) {
            if (strcmp(actual->marcaProducto, MarcaProducto[i]) == 0) {
                productosPorMarca[i]++;
                break;
            }
        }
        inversionTotal += actual->precioCosto * actual->cantidad;
        gananciaEsperada += actual->precioVenta * actual->cantidad;
        actual = actual->siguiente;
    }
    printf("Unidades totales por familia de producto:\n");
    for (i = 0; i < 10; i++) {
        if (unidadesPorFamilia[i] > 0) {
            printf("%s: %d unidades\n", nombreProducto[i], unidadesPorFamilia[i]);
        }
    }
    printf("\nCantidad de productos por marca:\n");
    for (i = 0; i < 10; i++) {
        if (productosPorMarca[i] > 0) {
            printf("%s: %d productos\n", MarcaProducto[i], productosPorMarca[i]);
        }
    }
    printf("\nInversion total en productos: %.2f\n", inversionTotal);
    printf("Ganancia esperada si se venden todos los productos: %.2f\n", gananciaEsperada);
}
