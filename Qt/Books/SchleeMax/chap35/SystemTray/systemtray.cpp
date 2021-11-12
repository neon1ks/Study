#include <QtWidgets>
#include "systemtray.h"

SystemTray::SystemTray(QWidget *pwgt /*=nullptr*/)
    : QLabel("<H1>Application Window</H1>", pwgt), m_bIconSwitcher(false)
{
    setWindowTitle("System Tray");

    auto *pactShowHide = new QAction("&Show/Hide Application Window", this);

    connect(pactShowHide, &QAction::triggered, this, &SystemTray::slotShowHide);

    auto *pactShowMessage = new QAction("S&how Message", this);
    connect(pactShowMessage, &QAction::triggered, this,
            &SystemTray::slotShowMessage);

    auto *pactChangeIcon = new QAction("&Change Icon", this);
    connect(pactChangeIcon, &QAction::triggered, this, &SystemTray::slotChangeIcon);

    auto *pactQuit = new QAction("&Quit", this);
    //connect(pactQuit, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(pactQuit, &QAction::triggered, this, &SystemTray::slotExit);

    m_ptrayIconMenu = new QMenu(this);
    m_ptrayIconMenu->addAction(pactShowHide);
    m_ptrayIconMenu->addAction(pactShowMessage);
    m_ptrayIconMenu->addAction(pactChangeIcon);
    m_ptrayIconMenu->addAction(pactQuit);

    m_ptrayIcon = new QSystemTrayIcon(this);
    m_ptrayIcon->setContextMenu(m_ptrayIconMenu);
    m_ptrayIcon->setToolTip("System Tray");

    slotChangeIcon();

    m_ptrayIcon->show();
}

/*virtual*/ void SystemTray::closeEvent(QCloseEvent *)
{
    if (m_ptrayIcon->isVisible()) {
        hide();
    }
}

void SystemTray::slotShowHide()
{
    setVisible(!isVisible());
}

void SystemTray::slotShowMessage()
{
    m_ptrayIcon->showMessage("For your information",
            "You have selected the "
            "\"Show Message!\" option",
            QSystemTrayIcon::Information, 3000);
}

void SystemTray::slotChangeIcon()
{
    m_bIconSwitcher = !m_bIconSwitcher;
    QString strPixmapName =
            m_bIconSwitcher ? ":/images/img1.bmp" : ":/images/img2.bmp";
    m_ptrayIcon->setIcon(QPixmap(strPixmapName));
}


void SystemTray::slotExit()
{
    QApplication::quit();
}
