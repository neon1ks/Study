#include "imageview.h"
#include "./ui_imageview.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>

ImageView::ImageView(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ImageView)
{
	ui->setupUi(this);

	connect(ui->actionOpen_File, SIGNAL(triggered()), this, SLOT(openFile()));
}

ImageView::~ImageView()
{
	delete ui;
}

void ImageView::openFile()
{
	QPixmap pm;
	QString fn = QFileDialog::getOpenFileName(this, tr("Открыть изображение"));
	if (fn != "")
	{
		if (!pm.load(fn))
			QMessageBox::critical(this, tr("Ошибка"), tr("Невозможно загрузить изображение из выбранного файла."));
		else
		{
			ui->label->setPixmap(pm);
			setWindowTitle(tr("Просмотр изображений — ") + fn);
		}
	}
}
