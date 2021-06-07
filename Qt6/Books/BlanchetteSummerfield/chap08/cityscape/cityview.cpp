#include <QtWidgets>
#include <cmath>

#include "cityview.h"

CityView::CityView(QWidget *parent) : QGraphicsView(parent)
{
    setDragMode(ScrollHandDrag);
}

void CityView::wheelEvent(QWheelEvent *event)
{
    QPoint numAngle = event->angleDelta() / 8;
    QPoint numPixels = event->pixelDelta();

    if (!numAngle.isNull()) {
        double numSteps = static_cast<double>(numAngle.y()) / 15.0;
        double factor = std::pow(1.125, numSteps);
        scale(factor, factor);
    } else if (!numPixels.isNull()) {
        double factor = std::pow(1.125, static_cast<double>(numPixels.y()));
        scale(factor, factor);
    }
}
