#include "player.h"
#include "map.h"

//Конструктор с параметрами для класса Player.
Player::Player(sf::String F, float X, float Y, int W, int H)
{
    dx = 0;
    dy = 0;
    speed = 0.;
    dir = 0;
    playerScore = 0;

    health = 80; // новая переменная, хранящая жизни игрока
    life = true;

    fname = F; // имя файла+расширение
    w = W;     // ширина
    h = H;     // высота

    image.loadFromFile("images/" + fname); //запихиваем в image наше изображение вместо File мы передадим то, что пропишем при создании объекта. В нашем случае "hero.png" и получится запись идентичная image.loadFromFile("images/hero/png");
    //image.createMaskFromColor(Color(41, 33, 59));//убираем ненужный темно-синий цвет, эта тень мне показалась не красивой.
    texture.loadFromImage(image); //закидываем наше изображение в текстуру
    sprite.setTexture(texture);   //заливаем спрайт текстурой
    x = X;
    y = Y;                                          //координата появления спрайта
    sprite.setTextureRect(sf::IntRect(0, 0, w, h)); //Задаем спрайту один прямоугольник для вывода одного льва, а не кучи львов сразу. IntRect - приведение типов
}

void Player::update(float time)
{

    switch (dir) {
    case 0: // наверх
        dx = 0;
        dy = -speed;
        break;
    case 1: // наверх вправо
        dx = speed * 0.7071f;
        dy = -speed * 0.7071f;
        break;
    case 2: // вправо
        dx = speed;
        dy = 0;
        break;
    case 3: // вниз вправо
        dx = speed * 0.7071f;
        dy = speed * 0.7071f;
        break;
    case 4: // вниз
        dx = 0;
        dy = speed;
        break;
    case 5: // вниз влево
        dx = -speed * 0.7071f;
        dy = speed * 0.7071f;
        break;
    case 6: // влево
        dx = -speed;
        dy = 0;
        break;
    case 7: // вверх влево
        dx = -speed * 0.7071f;
        dy = -speed * 0.7071f;
        break;
    }

    dx *= time;
    dy *= time;

    double temp = sqrt(double(dx) * double(dx) + double(dy) * double(dy));
    if (temp > 32.f) {
        dx *= float(32. / temp);
        dy *= float(32. / temp);
    }

    interactionWithMap(); //вызываем функцию, отвечающую за взаимодействие с картой

    x += dx; //то движение из прошлого урока. наше ускорение на время получаем смещение координат и как следствие движение
    y += dy; //аналогично по игреку

    speed = 0; //зануляем скорость, чтобы персонаж остановился.

    sprite.setPosition(x, y); //выводим спрайт в позицию x y ,
                              //посередине. бесконечно выводим в этой функции, иначе бы наш спрайт стоял на месте.

    if (health <= 0) {
		life = false;
	} //если жизней меньше либо равно 0, то умираем и исключаем движение игрока после смерти
}

float Player::getPlayerCoordinateX()
{ //этим методом будем забирать координату Х
    return x;
}

float Player::getPlayerCoordinateY()
{ //этим методом будем забирать координату Y
    return y;
}

void Player::interactionWithMap() //ф-ция взаимодействия с картой
{
    if (dy < 0) {
        int i = int((y + dy) / 32.f);
        for (int j = int(x / 32.f); j < int((x + w - 0.1f) / 32.f) + 1; j++) {
            if (TileMap[i][j] == '0') {
                dy = (i + 1) * 32.f - y;
                break;
            }
            interactionWithObject(i, j);
        }
    }
    if (dx < 0) {
        int j = int((x + dx) / 32.f);
        for (int i = int(y / 32.f); i < int((y + h - 0.1f) / 32.f) + 1; i++) {
            if (TileMap[i][j] == '0') {
                dx = (j + 1) * 32.f - x;
                break;
            }
            interactionWithObject(i, j);
        }
    }
    if (dx > 0) {
        int j = int((x + float(w) + dx) / 32.f);
        for (int i = int(y / 32.f); i < int((y + h - 0.1f) / 32.f) + 1; i++) {
            if (TileMap[i][j] == '0') {
                dx = j * 32.f - x - float(w);
                break;
            }
            interactionWithObject(i, j);
        }
    }
    if (dy > 0) {
        int i = int((y + float(h) + dy) / 32.f);
        for (int j = int(x / 32.f); j < int((x + w - 0.1f) / 32.f) + 1; j++) {
            if (TileMap[i][j] == '0') {
                dy = i * 32.f - y - float(h);
                break;
            }
            interactionWithObject(i, j);
        }
    }
}


void Player::interactionWithObject(int i, int j) //ф-ция взаимодействия с объектами на карте
{
	if (TileMap[i][j] == 's') {
		playerScore++;
		TileMap[i][j] = ' ';
	}
	if (TileMap[i][j] == 'f') {
		health-=40;          // если взяли ядовитейший в мире цветок
		TileMap[i][j] = ' '; // убрали цветок
	}
	if (TileMap[i][j] == 'h') {
		health += 20;        // если взяли сердечко
		TileMap[i][j] = ' '; // убрали сердечко
	}
}
