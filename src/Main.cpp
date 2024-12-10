#include <SFML/Graphics.hpp>
#include "Ventana.hpp"
#include "Gestor.hpp"

int main(){
    Ventana ventana("CAT-RATE", 1080, 900, "./assets/Salon.png");

    Gestor gestor;
    gestor.cargarTexturas({"./assets/1.png", "./assets/2.png", "./assets/3.png"});
    gestor.inicializarFichas();

    while(ventana.obtenerVentana().isOpen()){
        ventana.manejarEventos();
        ventana.limpiar();
        gestor.dibujar(ventana.obtenerVentana());
        ventana.mostrar();
    }
    return 0;
}