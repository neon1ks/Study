#pragma once

#ifndef MULTITOUCHWIDGET_H
#define MULTITOUCHWIDGET_H

#include <QWidget>
#include <QTouchEvent>

class MultiTouchWidget : public QWidget
{
    Q_OBJECT

public:
    MultiTouchWidget(QWidget *parent = nullptr);
    ~MultiTouchWidget() = default;

private:
    QList<QColor> m_lstCols;
    QList<QTouchEvent::TouchPoint> m_lstTps;

protected:
    virtual void paintEvent(QPaintEvent *);
    virtual bool event(QEvent *);
};
#endif // MULTITOUCHWIDGET_H
