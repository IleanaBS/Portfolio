#include "PlataformaStreaming.hpp"
#include <iostream>
#include <string>
#include<fstream>
#include <random>
#include <array>

using namespace std;

PlataformaStreaming::PlataformaStreaming(){};

void entregaProducto()
{
    string direccion, name;
    cout << "Escribe tu direccion para entregarte el producto lo mas pronto posible." << endl;
    cin >> direccion;
    cout << "Enhorabuena. Gracias por comprar en nuestra tienda departamental. Vuelve pronto" << endl;
}

void pagoProducto()
{

    cout << "Elige el metodo de pago" << endl;
    cout << "1) Efectivo" << endl;
    cout << "2) Tarjeta" << endl;
    cout << "3) Transferencia" << endl;

    int p;
    cin >> p;

    switch (p)
    {
    case 1:
    {
        // Generador de numeros aleatorios
        random_device rd;
        mt19937 generator(rd());

        // Definiendo la distribución para el numero aleatorio
        uniform_int_distribution<int> distribution(1, 1000); // Rango: 1-1000

        // Generando el numero aleatorio
        int randomNumber = distribution(generator);
        cout << "Ve a la sucursal mas cercana para pagar en efectivo. Tu numero de orden es: " << randomNumber << endl;
        break;
    }
    case 2:
    {
        cout << "Escribe tu numero de tarjeta: ";
        int num;
        cin >> num;
        entregaProducto();
        break;
    }
    case 3:
    {
        cout << "El numero de convenio es: 70650";
        break;
    }
    default:
        cout << "Opcion no valida" << endl;
    }
}

void compraProducto()
{
    // creando el arreglo de tamaño 5 para las TVs
    array<TV *, 5> tvs;
    tvs[0] = new TVCurva("Sony", "KD-65X80K UCM", 65, 20370.50, 178.00, "Completo");
    tvs[1] = new TVInteligente("Samsung", "QN65QN800BFXZX", 65, 49999.35, true);
    tvs[2] = new TVLed("LG", "86UQ9050PSC.SK1D", 86, 29999.99, "3180 x 2160");
    tvs[3] = new TVCurva("Sony", "KD-65X80K UCM", 65, 20370.50, 178.00, "Parcial");
    tvs[4] = new TVInteligente("Samsung", "QN65QN800BFXZX", 65, 49999.35, false);

    cout << "Selecciona el numero de TV para saber sus caracteristicas" << endl;
    for (size_t i = 0; i < 5; i++)
    {
        cout << i + 1 << ") TV " << i + 1 << endl;
    }

    size_t x;
    cin >> x;

    if (x >= 1 && x <= tvs.size())
    {
        TV *selectedTV = tvs[x - 1];
        cout << "Que quieres saber de este producto?" << endl;
        cout << "1) Marca" << endl;
        cout << "2) Modelo" << endl;
        cout << "3) Tamano" << endl;
        cout << "4) Precio" << endl;
        cout << "5) Comprar" << endl;
        cout << "6) Encender / Apagar" << endl;
        cout << "7) Volumen" << endl;
        cout << "8) Entrada" << endl;

        int c;
        cin >> c;

        switch (c)
        {
        case 1:
            cout << "La marca de esta TV es " << selectedTV->getMarca() << endl;
            break;
        case 2:
            cout << "El modelo es " << selectedTV->getModelo() << endl;
            break;
        case 3:
            cout << "El tamaño de la TV es " << selectedTV->getTamano() << " pulgadas" << endl;
            break;
        case 4:
            cout << "El precio de la TV es $" << selectedTV->getPrecio() << endl;
            break;
        case 5:
            cout << "Has seleccionado comprar la TV" << endl;
            pagoProducto();
            break;
        case 6:
            cout << "El estado de la TV es " << selectedTV->isEncendido() << endl;
            break;
        case 7:
            cout << "El volumen de la TV es " << selectedTV->getVolumen() << endl;
            break;
        case 8:
            cout << "La entrada de la TV es " << selectedTV->getEntrada() << endl;
            break;
        default:
            cout << "Opción no válida" << endl;
        }
    }
    else
    {
        cout << "Número de TV no válido" << endl;
    }
}

void Liverpool()
{
    string id;
    cout << "Hola! Cual es tu nombre?" << endl;
    cin >> id;
    cout << "De acuerdo " << id << "! Bienvenido a Liverpool" << endl;
    cout << "Elige la opcion deseada: " << endl;
    cout << "1) Comprar" << endl;
    cout << "2) Pagar" << endl;
    cout << "3) Entrega de producto" << endl;

    int x;
    cin >> x;
    switch (x)
    {
    case 1:
        compraProducto();
        break;
    case 2:
        pagoProducto();
        break;
    case 3:
        entregaProducto();
        break;
    }
};

void Sears()
{
    string id;
    cout << "Hola! Cual es tu nombre?" << endl;
    cin >> id;
    cout << "De acuerdo " << id << "! Bienvenido a Sears" << endl;
    cout << "Elige la opcion deseada: " << endl;
    cout << "1) Comprar" << endl;
    cout << "2) Pagar" << endl;
    cout << "3) Entrega de producto" << endl;

    int x;
    cin >> x;
    switch (x)
    {
    case 1:
        compraProducto();
        break;
    case 2:
        pagoProducto();
        break;
    case 3:
        entregaProducto();
        break;
    }
};

void PalacioDeHierro()
{
    string id;
    cout << "Hola! Cual es tu nombre?" << endl;
    cin >> id;
    cout << "De acuerdo " << id << "! Bienvenido a Palacio De Hierro" << endl;
    cout << "Elige la opcion deseada: " << endl;
    cout << "1) Comprar" << endl;
    cout << "2) Pagar" << endl;
    cout << "3) Entrega de producto" << endl;

    int x;
    cin >> x;
    switch (x)
    {
    case 1:
        compraProducto();
        break;
    case 2:
        pagoProducto();
        break;
    case 3:
        entregaProducto();
        break;
    }
};

int main()
{

    string nombre;
    cout << "Bienvenido. Que tienda departamental deseas visitar?" << endl;
    cout << "Elige la opcion deseada: " << endl;
    cout << "1) Liverpool" << endl;
    cout << "2) Sears" << endl;
    cout << "3) Palacio de Hierro" << endl;

    int x;
    cin >> x;
    switch (x)
    {
    case 1:
        Liverpool();
        break;
    case 2:
        Sears();
        break;
    case 3:
        PalacioDeHierro();
        break;
    }
    return 0;
};