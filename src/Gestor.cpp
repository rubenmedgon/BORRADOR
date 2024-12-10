#include "Gestor.hpp"

Gestor::Gestor(){
    fichasJugador1.resize(1, std::vector<Ficha>(3, Ficha(0, 0, 0)));
    fichasJugador2.resize(1, std::vector<Ficha>(3, Ficha(0, 0, 0)));
}

void Gestor::cargarTexturas(const vector<string>& route){
    texturasFichas.resize(route.size());
    for (size_t i = 0; i < route.size(); i++) {
        if (!texturasFichas[i].loadFromFile(route[i])) {
            throw std::runtime_error("Error al cargar la textura " + route[i]);
        }
    }
}

void Gestor::inicializarFichas(){
    for (int j = 0; j < 3; j++) {
        fichasJugador1[0][j] = Ficha(j + 1, 150 * j + (j + 3) * 10, 740);
        fichasJugador1[0][j].AsignarTextura(texturasFichas[j]);
        fichasJugador1[0][j].DesbloquearSprite();

        fichasJugador2[0][j] = Ficha(j + 1, 1080 - (150 * (3 - j)) - (10 * (3 - j)), 740);
        fichasJugador2[0][j].AsignarTextura(texturasFichas[j]);
        fichasJugador2[0][j].DesbloquearSprite();
    }
}

const vector<vector<Ficha>>& Gestor::obtenerFichasJugador1() const{
    return fichasJugador1;
}

const vector<vector<Ficha>>& Gestor::obtenerFichasJugador2() const{
    return fichasJugador2;
}

void Gestor::dibujar(RenderWindow& ventana){
    for (const auto& fila : fichasJugador1) {
        for (const auto& ficha : fila) {
            ventana.draw(ficha);
        }
    }
    for (const auto& fila : fichasJugador2) {
        for (const auto& ficha : fila) {
            ventana.draw(ficha);
        }
    }
}

int Gestor::detectarClickJugador1(const sf::Vector2i& posicion) {
    // Implementación aquí
}

int Gestor::detectarClickJugador2(const sf::Vector2i& posicion) {
    // Implementación aquí
}