#ifndef PLAYER_H_
#define PLAYER_H_

#include <cmath>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>

#include <SFML/Graphics.hpp>


// класс Игрока
class Player {
  private:
    float x, y; //объявили переменные, в конструкторе Player ниже дадим им значения

    void interactionWithObject(int i, int j);

  public:
    float dx, dy, speed; //координаты игрока х и у, ускорение (по х и по у), сама скорость

    int health; // новая переменная, хранящая жизни игрока
    bool life;  // переменная жизнь, логическая

    int playerScore;
    int w, h;         // высота ширина
    int dir;          //направление (direction) движения игрока
    sf::String fname; //файл с расширением
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;

    Player(sf::String F, float X, float Y, int W, int H);

    //функция "оживления" объекта класса. update - обновление. принимает в себя время SFML ,
    //вследствие чего работает бесконечно, давая персонажу движение.
    void update(float time);

    float getPlayerCoordinateX(); // этим методом будем забирать координату Х
    float getPlayerCoordinateY(); // этим методом будем забирать координату Y
    void interactionWithMap();    // ф-ция взаимодействия с картой

};

#endif
