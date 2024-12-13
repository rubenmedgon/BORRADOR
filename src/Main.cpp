#include <SFML/Graphics.hpp>
#include "Ventana.hpp"
#include "Gestor.hpp"
#include "Animacion.hpp"


int main(){
    Ventana ventana("CAT-RATE", 1080, 900, "./assets/Salon.png");

    Animacion animacion("./assets/gris_parado.png", 4, 0.1f, 460, 512);
    animacion.setPosition(200, 150);

    Gestor gestor;
    gestor.cargarTexturas({"./assets/1.png", "./assets/2.png", "./assets/3.png"});
    gestor.inicializarFichas();

    while(ventana.obtenerVentana().isOpen()){
        ventana.manejarEventos();

        animacion.update();

        ventana.limpiar();
        ventana.dibujar(animacion);
        gestor.dibujar(ventana.obtenerVentana());
        

        ventana.mostrar();
    }
    return 0;
}