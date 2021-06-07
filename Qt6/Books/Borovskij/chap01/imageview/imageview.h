#ifndef IMAGEVIEW_H
#define IMAGEVIEW_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class ImageView; }
QT_END_NAMESPACE

class ImageView : public QDialog
{
	Q_OBJECT

public:
	explicit ImageView(QWidget *parent = nullptr);
	~ImageView();

private:
	Ui::ImageView *ui;

private slots:
	void openFile();
};
#endif // IMAGEVIEW_H
