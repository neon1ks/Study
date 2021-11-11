#ifndef TIMERDEMOWIDGET_H
#define TIMERDEMOWIDGET_H

#include <QTimer>
#include <QWidget>

#include <QPalette>

class TimerDemoWidget : public QWidget
{
    Q_OBJECT

public:
    TimerDemoWidget(QWidget *parent = nullptr);
    ~TimerDemoWidget() override = default;

private slots:
    void setRandomBackgroundColor();

private:
    QTimer m_timer;
};

#endif // TIMERDEMOWIDGET_H
