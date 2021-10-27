#ifndef VIEW_H_
#define VIEW_H_

#include <SFML/Graphics.hpp>

extern sf::View view; //объявили sfml объект "вид", который и является камерой

// Функция для считывания координат игрока
void getPlayerCoordinateForView(float x, float y);


// Функция для перемещения камеры по карте. принимает время sfml
void viewmap(float time);

#endif
