#include "mainwindow.h"

#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    textEdit = new QTextEdit;
    setCentralWidget(textEdit);

    textEdit->setAcceptDrops(false);
    setAcceptDrops(true);

    setWindowTitle(tr("Text Editor"));
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("text/uri-list")) {
        event->acceptProposedAction();
    }
}

void MainWindow::dropEvent(QDropEvent *event)
{
    QList<QUrl> urls = event->mimeData()->urls();
    if (urls.isEmpty())
        return;

    QString fileName = urls.first().toLocalFile();

    if (fileName.isEmpty())
        return;

    if (readFile(fileName)) {
        setWindowTitle(tr("%1 - %2").arg(fileName, tr("Drag File")));
    }
}

bool MainWindow::readFile(const QString &fileName)
{

    QFile file(fileName);
    if (!file.exists()) {
        qDebug() << "NO existe el archivo " << fileName;
        return false;
    }
    // QString line;
    textEdit->clear();
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        textEdit->setText(file.readAll());
    }
    /*{
        QTextStream stream(&file);
        while (!stream.atEnd()) {
            line = stream.readLine();
            textEdit->setText(textEdit->toPlainText() + line + "\n");
            qDebug() << "linea: " << line;
        }
    }*/
    file.close();
    return true;
}
