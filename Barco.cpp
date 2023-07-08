#include "Barco.h"



Barco::Barco(int v) {
    this->vida = v;

    {
        if (!mTexture.loadFromFile("Barco.png"))
        {
            // Manejar el error de carga de la imagen del barco
        }

        if (!mTextureIzquierda.loadFromFile("BarcoIzquierda.png"))
        {
            // Manejar el error de carga de la imagen del barco hacia la izquierda
        }



        if (!mTextureDerecha.loadFromFile("BarcoDerecha.png"))
        {
            // Manejar el error de carga de la imagen del barco hacia la derecha
        }

        if (!mTextureAbajo.loadFromFile("Barco.png"))
        {
            // Manejar el error de carga de la imagen del barco hacia abajo
        }

        if (!mTextureArriba.loadFromFile("Barco.png"))
        {
            // Manejar el error de carga de la imagen del barco hacia arriba
        }
        const int ancho = 1900.0;
        const int alto = 1000.0;
        mShip.setTexture(mTexture);
        mShip.setPosition(ancho / 2.f, alto / 2.f);
        mShip.setScale(0.3, 0.3);
    }
}

Barco::Barco() {

}
   


bool Barco::getMovingU() {
    return mIsMovingUp;
}

bool Barco::getMovingD() {
    return mIsMovingDown;
}
bool Barco::getMovingR() {
    return mIsMovingRight;
}
bool Barco::getMovingL() {
    return mIsMovingLeft;
}



float Barco::getX(){
    return x;
}

float Barco::getY() {
    return y;
}

sf::Sprite Barco::getSprite() {
    return mShip;
}

void Barco::setPosition(float x, float y) {
    mShip.setPosition(x, y);
}

void Barco::setScale(float scaleX, float scaleY) {
    mShip.setScale(scaleX, scaleY);
}

void Barco::move(float offsetX, float offsetY) {
    mShip.move(offsetX, offsetY);

}

void Barco::render(sf::RenderWindow& window) {
    window.draw(mShip);
}

void Barco::dispararCanon() {
    // Lógica para disparar el cañón
}

