#pragma once

#include <SFML/Graphics.hpp>

class Barco {
public:
    Barco() ;
    Barco( int vida );
    void setPosition(float x, float y);
    void setScale(float scaleX, float scaleY);
    void move(float offsetX, float offsetY);
    void render(sf::RenderWindow& window);
    sf::Sprite getSprite();
    void dispararCanon();
    float getX();
    float getY();
    bool mIsMovingUp ;
    bool mIsMovingDown ;
    bool mIsMovingRight ;
    bool mIsMovingLeft;

    sf::Texture mTexture;
    sf::Texture mTextureIzquierda;
    sf::Texture mTextureDerecha;
    sf::Texture mTextureAbajo;
    sf::Texture mTextureArriba;
    bool getMovingU();
    bool getMovingD();
    bool getMovingR();
    bool getMovingL();
private:
    int vida;
    float x, y;
    int velocidad;
    sf::Sprite mShip;
   

};

