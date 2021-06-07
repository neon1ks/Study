#pragma once

#include <QLabel>

class QString;

class MouseObserver : public QLabel
{
public:
    MouseObserver(QWidget *pwgt = nullptr);
    ~MouseObserver() = default;

protected:
    virtual void mousePressEvent(QMouseEvent *pe);
    virtual void mouseReleaseEvent(QMouseEvent *pe);
    virtual void mouseMoveEvent(QMouseEvent *pe);

    void dumpEvent(QMouseEvent *pe, const QString &strMessage);
    QString modifiersInfo(QMouseEvent *pe);
    QString buttonsInfo(QMouseEvent *pe);
};
