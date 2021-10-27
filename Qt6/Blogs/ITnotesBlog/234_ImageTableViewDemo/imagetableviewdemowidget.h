#ifndef IMAGETABLEVIEWDEMOWIDGET_H
#define IMAGETABLEVIEWDEMOWIDGET_H

#include <QWidget>

class QTableWidget;

class ImageTableViewDemoWidget : public QWidget {
    Q_OBJECT

public:
    ImageTableViewDemoWidget( QWidget* parent = 0 );
    ~ImageTableViewDemoWidget();

private slots:
    void onLinkActivated( const QString& lnk );

private:
    QTableWidget* m_table;
};

#endif // IMAGETABLEVIEWDEMOWIDGET_H
