#include "Game.h"

const float Game::PlayerSpeed = 100.f;
const int ancho = 1900;
const int alto = 1000;
Game::Game() : mWindow(sf::VideoMode(ancho, alto), "JUEGO"), mShip(2)
{
    
}


void Game::run()
{
    sf::Clock clock;
    while (mWindow.isOpen())
    {
        sf::Time deltaTime = clock.restart();
        processEvents();
        update(deltaTime);
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::KeyPressed:
            handlePlayerInput(event.key.code, true);
            break;

        case sf::Event::KeyReleased:
            handlePlayerInput(event.key.code, false);
            break;

        case sf::Event::Closed:
            mWindow.close();
            break;
        }
    }
}

void Game::update(sf::Time deltaTime)
{



    sf::Vector2f movement(0.f, 0.f);
    if (mIsMovingUp && mShip.getY() >0.f) {
        movement.y -= PlayerSpeed;
        mDireccion = Direccion::Arriba;
    }
    if (mIsMovingDown && mShip.getY() < mWindow.getSize().y - mShip.getSprite().getGlobalBounds().height) {
        movement.y += PlayerSpeed;
        mDireccion = Direccion::Abajo;
    }
    if (mIsMovingLeft && mShip.getX() > 0.f)
    {
        movement.x -= PlayerSpeed;
        mDireccion = Direccion::Izquierda;
    }
    if (mIsMovingRight && mShip.getX() < mWindow.getSize().x - mShip.getSprite().getGlobalBounds().width)
    {
        movement.x += PlayerSpeed;
        mDireccion = Direccion::Derecha;
    }

    mShip.getSprite().move(movement * deltaTime.asSeconds());

    // Actualizar la textura del sprite según la dirección
    if (mDireccion == Direccion::Abajo)
    {
        mShip.getSprite().setTexture(mShip.mTextureAbajo);
    }
    else if (mDireccion == Direccion::Arriba)
    {

        mShip.getSprite().setTexture(mShip.mTextureArriba);
    }
    else if (mDireccion == Direccion::Izquierda)
    {
        
        mShip.getSprite().setTexture(mShip.mTextureIzquierda);

       
    }
    else if (mDireccion == Direccion::Derecha)
    {
        mShip.getSprite().setTexture(mShip.mTextureDerecha);
    }


}


void Game::render()
{
    mWindow.clear();
    mWindow.draw(mShip.getSprite());
    mWindow.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
    if (key == sf::Keyboard::W)
        mIsMovingUp = isPressed;
    else if (key == sf::Keyboard::S)
        mIsMovingDown = isPressed;
    else if (key == sf::Keyboard::A)
        mIsMovingLeft = isPressed;
    else if (key == sf::Keyboard::D)
        mIsMovingRight = isPressed;
}
