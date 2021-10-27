#include "map.h"
#include "mission.h"
#include "player.h"
#include "view.h"

int main(void)
{

    sf::RenderWindow window(sf::VideoMode(640, 480), "Game");

    // размер "вида" камеры при создании объекта вида камеры.
    // (потом можем менять как хотим) Что то типа инициализации.
    view.reset(sf::FloatRect(0, 0, 640, 480));

    sf::Image map_image;                       //объект изображения для карты
    map_image.loadFromFile("images/map2.png"); //загружаем файл для карты
    sf::Texture map;                           //текстура карты
    map.loadFromImage(map_image);              //заряжаем текстуру картинкой
    sf::Sprite s_map;                          //создаём спрайт для карты
    s_map.setTexture(map);                     //заливаем текстуру спрайтом

    sf::Font font;                                        //шрифт
    font.loadFromFile("CyrilicOld.ttf");                  //передаем нашему шрифту файл шрифта
    sf::Text text("", font, 28);                          //создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
    text.setColor(sf::Color::Black);                      //покрасили текст в красный. если убрать эту строку, то по умолчанию он белый
    text.setStyle(sf::Text::Bold | sf::Text::Underlined); //жирный и подчеркнутый текст. по умолчанию он "худой":)) и не подчеркнутый

    sf::Image quest_image;
    quest_image.loadFromFile("images/missionbg.jpg");
    quest_image.createMaskFromColor(sf::Color(0, 0, 0));
    sf::Texture quest_texture;
    quest_texture.loadFromImage(quest_image);
    sf::Sprite s_quest;
    s_quest.setTexture(quest_texture);
    s_quest.setTextureRect(sf::IntRect(0, 0, 340, 510)); //приведение типов, размеры картинки исходные
    s_quest.setScale(0.6f, 0.6f);                    //чуть уменьшили картинку, => размер стал меньше

    // создаем объект p класса player,задаем "hero.png" как имя файла+расширение,
    // далее координата Х,У, ширина, высота.
    Player p("monster.png", 250, 250, 96, 96);
    getPlayerCoordinateForView(p.getPlayerCoordinateX(), p.getPlayerCoordinateY());

    // создаем переменную времени, т.о. привязка ко времени
    // (а не загруженности/мощности процессора).
    sf::Clock clock;
    sf::Clock gameTimeClock; //переменная игрового времени, будем здесь хранить время игры
    float gameTime = 0;      //объявили игровое время, инициализировали.

    float CurrentFrame = 0; // хранит текущий кадр

    bool showMissionText = true; //логическая переменная, отвечающая за появление текста миссии на экране
    std::string missionText;

    while (window.isOpen()) {
        static float time = 0;
        static bool isDown;
        static bool isLeft;
        static bool isRight;
        static bool isUp;

        isDown = false;
        isLeft = false;
        isRight = false;
        isUp = false;

        //дать прошедшее время в микросекундах
        time = float(clock.getElapsedTime().asMicroseconds() / 800.);
        clock.restart(); //перезагружает время

        // игровое время в секундах идёт вперед, пока жив игрок,
        // перезагружать как time его не надо. оно не обновляет логику игры
        if (p.life)
            gameTime = gameTimeClock.getElapsedTime().asSeconds();

        sf::Event event;

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {       //событие нажатия клавиши
                if ((event.key.code == sf::Keyboard::Tab)) { //если клавиша ТАБ
                    if (showMissionText) {           //переключатель, реагирующий на логическую переменную showMissionText
                        std::wostringstream playerHealthString;                                      // Строка здоровья игрока
                        playerHealthString << p.health;                                              // Заносим в строку здоровье
                        missionText = getTextMission(getCurrentMission(p.getPlayerCoordinateX()));         // Получаем текст миссии
                        //text.setString("Здоровье: " + playerHealthString.str() + "\n" + missionText); // Формируем текст сообщения
                        text.setString(missionText); // Формируем текст сообщения
                        text.setPosition(view.getCenter().x + 125, view.getCenter().y - 130);        // Позиция всего этого текстового блока
                        s_quest.setPosition(view.getCenter().x + 115, view.getCenter().y - 130);     // Позиция фона для блока
                        showMissionText = false;                                                     // Эта строка позволяет убрать все что мы вывели на экране
                    }
                    else {
                        text.setString("");     //если не нажата клавиша таб, то весь этот текст пустой
                        showMissionText = true; // а эта строка позволяет снова нажать клавишу таб и получить вывод на экран
                    }
                }
            }
        }

        if (p.life) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                isDown = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                isLeft = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                isRight = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                isUp = true;
            }
        }

        if (isUp || isRight || isDown || isLeft) {
            CurrentFrame += 0.005f * time;
            if (CurrentFrame > 4)
                CurrentFrame -= 4;
        }

        if (isUp && isRight) {
            p.dir = 1;
            p.speed = 0.1f;
            p.sprite.setTextureRect(sf::IntRect(96 * int(CurrentFrame), 288, 96, 96));
        }
        else if (isRight && isDown) {
            p.dir = 3;
            p.speed = 0.1f;
            p.sprite.setTextureRect(sf::IntRect(96 * int(CurrentFrame), 192, 96, 96));
        }
        else if (isDown && isLeft) {
            p.dir = 5;
            p.speed = 0.1f;
            p.sprite.setTextureRect(sf::IntRect(96 * int(CurrentFrame), 96, 96, 96));
        }
        else if (isLeft && isUp) {
            p.dir = 7;
            p.speed = 0.1f;
            p.sprite.setTextureRect(sf::IntRect(96 * int(CurrentFrame), 288, 96, 96));
        }
        else if (isUp) {
            p.dir = 0;
            p.speed = 0.1f;
            p.sprite.setTextureRect(sf::IntRect(96 * int(CurrentFrame), 288, 96, 96));
        }
        else if (isRight) {
            p.dir = 2;
            p.speed = 0.1f;
            p.sprite.setTextureRect(sf::IntRect(96 * int(CurrentFrame), 192, 96, 96));
        }
        else if (isDown) {
            p.dir = 4;
            p.speed = 0.1f;
            p.sprite.setTextureRect(sf::IntRect(96 * int(CurrentFrame), 0, 96, 96));
        }
        else if (isLeft) {
            p.dir = 6;
            p.speed = 0.1f;
            p.sprite.setTextureRect(sf::IntRect(96 * int(CurrentFrame), 96, 96, 96));
        }
        if (isUp || isRight || isDown || isLeft) {
            //передаем координаты игрока в функцию управления камерой
            getPlayerCoordinateForView(p.getPlayerCoordinateX(), p.getPlayerCoordinateY());
        }

        //оживляем объект p класса Player с помощью времени sfml,
        //передавая время в качестве параметра функции update.
        //благодаря этому персонаж может двигаться
        p.update(time);

        //viewmap(time);//функция скроллинга карты, передаем ей время sfml
        //changeview();//прикалываемся с камерой

        window.setView(view); //"оживляем" камеру в окне sfml
        window.clear(sf::Color(128, 106, 89));

        for (int i = 0; i < HEIGHT_MAP; i++) {
            for (int j = 0; j < WIDTH_MAP; j++) {

                if (TileMap[i][j] == ' ')
                    s_map.setTextureRect(sf::IntRect(0, 0, 32, 32)); //если встретили символ пробел, то рисуем 1й квадратик
                if (TileMap[i][j] == 's')
                    s_map.setTextureRect(sf::IntRect(32, 0, 32, 32)); //если встретили символ s, то рисуем 2й квадратик
                if ((TileMap[i][j] == '0'))
                    s_map.setTextureRect(sf::IntRect(64, 0, 32, 32)); //если встретили символ 0, то рисуем 3й квадратик
                if ((TileMap[i][j] == 'f'))
                    s_map.setTextureRect(sf::IntRect(96, 0, 32, 32)); //добавили цветок
                if ((TileMap[i][j] == 'h'))
                    s_map.setTextureRect(sf::IntRect(128, 0, 32, 32)); //и сердечко

                s_map.setPosition(float(j * 32), float(i * 32)); //по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один квадрат

                window.draw(s_map); //рисуем квадратики на экран
            }
        }

		// Рисуем спрайт свитка (фон для текста миссии). а затем и текст.
		// Все это завязано на логическую переменную, которая меняет свое состояние от нажатия клавиши ТАБ
        if (!showMissionText) {
			window.draw(s_quest);
			window.draw(text);
		}

        window.draw(p.sprite); //рисуем спрайт объекта p класса player
        window.display();
    }

    return 0;
}
