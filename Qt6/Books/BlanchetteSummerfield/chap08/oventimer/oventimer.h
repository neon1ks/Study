#ifndef OVENTIMER_H
#define OVENTIMER_H

#include <QDateTime>
#include <QWidget>

class OvenTimer : public QWidget
{
    Q_OBJECT

public:
    OvenTimer(QWidget *parent = nullptr);
    ~OvenTimer() = default;

    void setDuration(int secs);
    int duration() const;
    void draw(QPainter *painter);

signals:
    void timeout();

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    QDateTime finishTime;
    QTimer *updateTimer;
    QTimer *finishTimer;
};

#endif // OVENTIMER_H
