#include "timerdemowidget.h"

#include <QRandomGenerator>
#include <QPalette>

TimerDemoWidget::TimerDemoWidget(QWidget *parent) : QWidget(parent)
{
    setAutoFillBackground(true);

    // Работает в Qt 5.12.8
    setAttribute(Qt::WA_StyledBackground, true);
    setStyleSheet("background-color: red;");

    connect(&m_timer, &QTimer::timeout, this,
            &TimerDemoWidget::setRandomBackgroundColor);

    // Таймер будет срабатывать каждые 1000 миллисекунд, т.е. каждую секунду
    m_timer.start(1000);
}

void TimerDemoWidget::setRandomBackgroundColor()
{
    QPalette palette1(this->palette());

    // int r = qrand() % 256;  // Obsolete function
    // int g = qrand() % 256;  // Obsolete function
    // int b = qrand() % 256;  // Obsolete function
    int r = static_cast<int>(QRandomGenerator::global()->generate() % 256);
    int g = static_cast<int>(QRandomGenerator::global()->generate() % 256);
    int b = static_cast<int>(QRandomGenerator::global()->generate() % 256);

    // QPalette::Background | This value is obsolete. Use QPalette::Window instead.
    palette1.setColor(QPalette::Window, QColor(r, g, b));
    setPalette(palette1);
    update();
}
