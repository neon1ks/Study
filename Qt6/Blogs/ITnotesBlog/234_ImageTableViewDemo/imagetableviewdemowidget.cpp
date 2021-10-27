#include "imagetableviewdemowidget.h"

#include <QTableWidget>
#include <QBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QFileDialog>

static const QStringList COLUMN_LABELS = QStringList() << "Image Name" << "Image";
static const int IMAGE_VMARGIN = 10;

ImageTableViewDemoWidget::ImageTableViewDemoWidget( QWidget* parent )
    : QWidget( parent ) {
    QBoxLayout* layout = new QVBoxLayout;
    layout->addWidget( m_table = new QTableWidget );
    m_table->setColumnCount( COLUMN_LABELS.size() );
    m_table->setHorizontalHeaderLabels( COLUMN_LABELS );
    m_table->setFocusPolicy( Qt::NoFocus );
    m_table->setSelectionBehavior( QAbstractItemView::SelectRows );
    m_table->horizontalHeader()->setStretchLastSection( true );

    QLabel* lbl = new QLabel( "<a href='#load'>Load Image...</a>" );
    connect( lbl, SIGNAL( linkActivated( QString ) ), SLOT( onLinkActivated( QString ) ) );
    lbl->setAlignment( Qt::AlignRight );
    layout->addWidget( lbl );

    setLayout( layout );
}

ImageTableViewDemoWidget::~ImageTableViewDemoWidget() {
}

void ImageTableViewDemoWidget::onLinkActivated( const QString& lnk ) {
    if( lnk == "#load" ) {
        QString fileName = QFileDialog::getOpenFileName( this, "Load Image", QString(), "Images (*.jpg *.png *.bmp)" );

        QPixmap pix;
        if( pix.load( fileName ) ) {
            int row = m_table->rowCount();
            m_table->insertRow( row );
            QTableWidgetItem* item = new QTableWidgetItem( QFileInfo( fileName ).baseName() );
            item->setFlags( item->flags() ^ Qt::ItemIsEditable );
            m_table->setItem( row, 0, item );

            item = new QTableWidgetItem;
            item->setData( Qt::DecorationRole, pix );
            item->setFlags( item->flags() ^ Qt::ItemIsEditable );
            m_table->setItem( row, 1, item );
            m_table->setRowHeight( row, pix.height() + IMAGE_VMARGIN );
        }
    } else {
        // Unexpected
    }
}
