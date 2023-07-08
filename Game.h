#pragma once

#include"Barco.h"
#include <SFML/Graphics.hpp>

class Game {
public:
    Game();
    void run();


private:
    // Métodos privados
    void processEvents();
    void update(sf::Time elapsedTime);
    void render();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:
    // Variables miembro
    static const float PlayerSpeed;
    sf::RenderWindow mWindow;
    

    // Otras variables miembro necesarias
   

    enum class Direccion {
        Ninguna,
        Izquierda,
        Derecha,
        Abajo,
        Arriba
    };
    Direccion mDireccion;
    Barco mShip;
    bool mIsMovingUp = false;
    bool mIsMovingDown = false;
    bool mIsMovingRight = false;
    bool mIsMovingLeft = false;
    // Constantes
   
};



