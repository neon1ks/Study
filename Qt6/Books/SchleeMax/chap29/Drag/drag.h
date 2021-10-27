// ======================================================================
//  Drag.h
// ======================================================================
//                   This file is a part of the book
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#pragma once

#include <QtWidgets>

// ======================================================================
class Drag : public QLabel
{
    Q_OBJECT
private:
    QPoint m_ptDragPos;

    void startDrag()
    {
        auto *pMimeData = new QMimeData;
        pMimeData->setText(text());

        auto *pDrag = new QDrag(this);
        pDrag->setMimeData(pMimeData);
        pDrag->setPixmap(QPixmap(":/img1.png"));
        pDrag->exec(Qt::MoveAction);
    }

protected:
    void mousePressEvent(QMouseEvent *pe) override
    {
        if (pe->button() == Qt::LeftButton) {
            m_ptDragPos = pe->pos();
        }
        QLabel::mousePressEvent(pe);
    }

    void mouseMoveEvent(QMouseEvent *pe) override
    {
        if (pe->buttons() & Qt::LeftButton) {
            int distance = (pe->pos() - m_ptDragPos).manhattanLength();
            if (distance > QApplication::startDragDistance()) {
                startDrag();
            }
        }
        QLabel::mouseMoveEvent(pe);
    }


public:
    Drag(QWidget *pwgt = nullptr) : QLabel("This is a draggable text", pwgt) { }
};
