#ifndef FONTVIEWER_H
#define FONTVIEWER_H

#include <QDialog>

class QLayout;
class QHBoxLayout;
class QSpinBox;
class QComboBox;
class QVBoxLayout;
class QCheckBox;
class QLabel;

class FontViewer : public QDialog
{
	Q_OBJECT

public:
	FontViewer(QWidget *parent = nullptr);
	virtual ~FontViewer() = default;

private:
	QVBoxLayout *MainFormLayout;
	QHBoxLayout *ChooseFontLayout;
	QHBoxLayout *ViewTextLayout;
	QComboBox *SelectFontBox;
	QSpinBox *SetSize;
	QVBoxLayout *SetFontGroup;
	QCheckBox *SetBold;
	QCheckBox *SetItalic;
	QLabel *TextLabel;

	static const int W = 300;
	static const int H = 200;
	static const int MIN_SIZE_FONT = 1;
	static const int MAX_SIZE_FONT = 72;
	static const int DEFAULT_SIZE_FONT = 12;

private slots:
	void setLabelFont();
};
#endif  // FONTVIEWER_H
