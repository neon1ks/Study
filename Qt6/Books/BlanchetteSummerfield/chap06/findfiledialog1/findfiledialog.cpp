#include <QtWidgets>

#include "findfiledialog.h"

FindFileDialog::FindFileDialog(QWidget *parent) : QDialog(parent)
{
    namedLabel = new QLabel(tr("&Named:"), this);
    namedLineEdit = new QLineEdit(this);
    namedLabel->setBuddy(namedLineEdit);

    lookInLabel = new QLabel(tr("&Look in:"), this);
    lookInLineEdit = new QLineEdit(this);
    lookInLabel->setBuddy(lookInLineEdit);

    subfoldersCheckBox = new QCheckBox(tr("Include subfolders"), this);

    QStringList labels;
    labels << tr("Name") << tr("In Folder") << tr("Size") << tr("Modified");

    tableWidget = new QTableWidget(this);
    tableWidget->setColumnCount(4);
    tableWidget->setHorizontalHeaderLabels(labels);

    messageLabel = new QLabel(tr("0 files found"), this);
    messageLabel->setFrameShape(QLabel::Panel);
    messageLabel->setFrameShadow(QLabel::Sunken);

    findButton = new QPushButton(tr("&Find"), this);
    stopButton = new QPushButton(tr("Stop"), this);
    closeButton = new QPushButton(tr("Close"), this);
    helpButton = new QPushButton(tr("Help"), this);

    connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));

    namedLabel->setGeometry(9, 9, 50, 25);
    namedLineEdit->setGeometry(65, 9, 500, 25);
    lookInLabel->setGeometry(9, 40, 50, 25);
    lookInLineEdit->setGeometry(65, 40, 500, 25);
    subfoldersCheckBox->setGeometry(9, 71, 556, 23);
    tableWidget->setGeometry(9, 100, 556, 300);
    messageLabel->setGeometry(9, 406, 556, 25);
    findButton->setGeometry(571, 9, 85, 32);
    stopButton->setGeometry(571, 47, 85, 32);
    closeButton->setGeometry(571, 84, 85, 32);
    helpButton->setGeometry(571, 199, 85, 32);

    setWindowTitle(tr("Find Files or Folders"));
    setFixedSize(665, 440);
}
