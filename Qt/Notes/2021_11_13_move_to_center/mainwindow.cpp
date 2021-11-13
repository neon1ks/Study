#include "mainwindow.h"

#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("Move to Center");

    auto *window = new QWidget(this);

    m_first = new QPushButton("First");
    m_second = new QPushButton("Second way only QT 5");

    m_layout = new QHBoxLayout(window);
    auto *spacer = new QSpacerItem(
            20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

    m_layout->addItem(spacer);
    m_layout->addWidget(m_first);
    m_layout->addWidget(m_second);
    spacer = new QSpacerItem(
            20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    m_layout->addItem(spacer);

    connect(m_first, &QAbstractButton::released, this,
            &MainWindow::moveToCenter1);
    connect(m_second, &QAbstractButton::released, this,
            &MainWindow::moveToCenter2);

    window->setLayout(m_layout);
    setCentralWidget(window);
    window->show();
}

void MainWindow::moveToCenter1()
{
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();

    int x = (width - frameGeometry().width()) / 2;
    int y = (height - frameGeometry().height()) / 2;

    move(x, y);
}

void MainWindow::moveToCenter2()
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QDesktopWidget *desktop = QApplication::desktop();

    int width = desktop->width();
    int height = desktop->height();

    int x = (width - frameGeometry().width()) / 2;
    int y = (height - frameGeometry().height()) / 2;

    move(x, y);
#endif
}
