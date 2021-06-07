#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>

class QAction;
class QLabel;
class FindDialog;
class Spreadsheet;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	virtual ~MainWindow() = default;

protected:
	void closeEvent(QCloseEvent *event);

private slots:
	void newFile();
	void open();
	bool save();
	bool saveAs();
	void find();
	void goToCell();
	void sort();
	void about();
	void openRecentFile();
	void updateStatusBar();
	void spreadsheetModified();

private:
	void createActions();
	void createMenus();
	void createContextMenu();
	void createToolBars();
	void createStatusBar();
	void readSettings();
	void writeSettings();
	bool okToContinue();
	bool loadFile(const QString &fileName);
	bool saveFile(const QString &fileName);
	void setCurrentFile(const QString &fileName);
	void updateRecentFileActions();

	static QString strippedName(const QString &fullFileName);

	Spreadsheet *spreadsheet;
	FindDialog *findDialog;
	QLabel *locationLabel;
	QLabel *formulaLabel;
	QString curFile;

	static QStringList recentFiles;

	enum
	{
		MaxRecentFiles = 5
	};
	const int TIMEOUT = 2000;

	QAction *recentFileActions[MaxRecentFiles];
	QAction *separatorAction;

	QMenu *fileMenu;
	QMenu *editMenu;
	QMenu *selectSubMenu;
	QMenu *toolsMenu;
	QMenu *optionsMenu;
	QMenu *helpMenu;
	QToolBar *fileToolBar;
	QToolBar *editToolBar;
	QAction *newAction;
	QAction *openAction;
	QAction *saveAction;
	QAction *saveAsAction;
	//QAction *closeAction;
	QAction *exitAction;
	QAction *cutAction;
	QAction *copyAction;
	QAction *pasteAction;
	QAction *deleteAction;
	QAction *selectRowAction;
	QAction *selectColumnAction;
	QAction *selectAllAction;
	QAction *findAction;
	QAction *goToCellAction;
	QAction *recalculateAction;
	QAction *sortAction;
	QAction *showGridAction;
	QAction *autoRecalcAction;
	QAction *aboutAction;
	QAction *aboutQtAction;
};
#endif  // MAINWINDOW_H
