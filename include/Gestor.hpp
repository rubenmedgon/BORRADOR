#include <iostream>
#include <vector>
#include "Ficha.hpp"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Gestor{
    private:
        vector<sf::Texture> texturasFichas;
        vector<std::vector<Ficha>> fichasJugador1;
        vector<std::vector<Ficha>> fichasJugador2;
    public:
    Gestor();
    void cargarTexturas(const vector<string>& route);
    void inicializarFichas();
    const vector<vector<Ficha>>& obtenerFichasJugador1() const;
    const vector<vector<Ficha>>& obtenerFichasJugador2() const;
    void dibujar(RenderWindow& ventana);
    int detectarClickJugador1(const sf::Vector2i& posicion);
    int detectarClickJugador2(const sf::Vector2i& posicion);
};