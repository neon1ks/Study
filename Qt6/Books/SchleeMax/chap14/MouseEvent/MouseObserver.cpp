#include "MouseObserver.h"

#include <QtWidgets>

MouseObserver::MouseObserver(QWidget *pwgt /*= 0*/) : QLabel(pwgt)
{
    setAlignment(Qt::AlignCenter);
    setText("Mouse interactions\n(Press a mouse button)");
}

/*virtual*/ void MouseObserver::mousePressEvent(QMouseEvent *pe)
{
    dumpEvent(pe, "Mouse Pressed");
}

/*virtual*/ void MouseObserver::mouseReleaseEvent(QMouseEvent *pe)
{
    dumpEvent(pe, "Mouse Released");
}

/*virtual*/ void MouseObserver::mouseMoveEvent(QMouseEvent *pe)
{
    dumpEvent(pe, "Mouse Is Moving");
}

void MouseObserver::dumpEvent(QMouseEvent *pe, const QString &strMsg)
{
    QPointF possition = pe->position();
    QPointF globalPosition = pe->globalPosition();
    setText(strMsg + "\n buttons()=" + buttonsInfo(pe)
            + "\n x()=" + QString::number(possition.rx())
            + "\n y()=" + QString::number(possition.ry())
            + "\n globalX()=" + QString::number(globalPosition.rx())
            + "\n globalY()=" + QString::number(globalPosition.ry())
            + "\n modifiers()=" + modifiersInfo(pe));
}

QString MouseObserver::modifiersInfo(QMouseEvent *pe)
{
    QString strModifiers;

    if (pe->modifiers() & Qt::ShiftModifier) {
        strModifiers += "Shift ";
    }
    if (pe->modifiers() & Qt::ControlModifier) {
        strModifiers += "Control ";
    }
    if (pe->modifiers() & Qt::AltModifier) {
        strModifiers += "Alt";
    }
    return strModifiers;
}

QString MouseObserver::buttonsInfo(QMouseEvent *pe)
{
    QString strButtons;

    if (pe->buttons() & Qt::LeftButton) {
        strButtons += "Left ";
    }
    if (pe->buttons() & Qt::RightButton) {
        strButtons += "Right ";
    }
    if (pe->buttons() & Qt::MiddleButton) {
        strButtons += "Middle";
    }
    return strButtons;
}
