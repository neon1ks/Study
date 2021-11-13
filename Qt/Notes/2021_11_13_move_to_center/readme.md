# Перемещение окна в центр

Получаем размер экрана и размер приложения. И вычисляем координату для правого верхнего угла окна.

## Первый способ

Получаем размер экрана через класс `QScreen` добавленного в Qt 5.

```cpp
QScreen *screen = QGuiApplication::primaryScreen();
QRect screenGeometry = screen->geometry();
int height = screenGeometry.height();
int width = screenGeometry.width();

int x = (width - frameGeometry().width()) / 2;
int y = (height - frameGeometry().height()) / 2;

move(x, y);
```

## Второй способ

Получаем размер экрана через класс `QDesktopWidget`. **This class is obsolete.** It is provided to keep old source code working. We strongly advise against using it in new code.
 
В Qt 6 данного класса уже нет.

```cpp
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QDesktopWidget *desktop = QApplication::desktop();
    int width = desktop->width();
    int height = desktop->height();

    int x = (width - frameGeometry().width()) / 2;
    int y = (height - frameGeometry().height()) / 2;

    move(x, y);
#endif
```
