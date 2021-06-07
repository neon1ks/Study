#ifndef CITYVIEW_H
#define CITYVIEW_H

#include <QGraphicsView>

class CityView : public QGraphicsView
{
    Q_OBJECT

public:
    CityView(QWidget *parent = nullptr);

protected:
    void wheelEvent(QWheelEvent *event);
};

#endif
