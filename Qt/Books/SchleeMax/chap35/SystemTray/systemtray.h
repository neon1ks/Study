#pragma once

#ifndef SYSTEMTRAY_H
#define SYSTEMTRAY_H

#include <QLabel>

class QSystemTrayIcon;
class QMenu;

class SystemTray : public QLabel
{
    Q_OBJECT
private:
    QSystemTrayIcon *m_ptrayIcon;
    QMenu *m_ptrayIconMenu;
    bool m_bIconSwitcher;

protected:
    void closeEvent(QCloseEvent *) override;

public:
    SystemTray(QWidget *pwgt = nullptr);

public slots:
    void slotShowHide();
    void slotShowMessage();
    void slotChangeIcon();
    static void slotExit();
};

#endif // SYSTEMTRAY_H
