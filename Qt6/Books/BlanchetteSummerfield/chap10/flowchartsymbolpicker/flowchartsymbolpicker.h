#ifndef FLOWCHARTSYMBOLPICKER_H
#define FLOWCHARTSYMBOLPICKER_H

#include <QDialog>
#include <QMap>

QT_BEGIN_NAMESPACE
class QDialogButtonBox;
class QIcon;
class QListWidget;
QT_END_NAMESPACE

class FlowChartSymbolPicker : public QDialog
{
    Q_OBJECT

public:
    explicit FlowChartSymbolPicker(
            const QMap<int, QString> &symbolMap, QWidget *parent = nullptr);
    virtual ~FlowChartSymbolPicker() = default;

    int selectedId() const { return id; }

    // [virtual public slot] from QDialog
    void done(int result) override;

private:
    static QIcon iconForSymbol(const QString &symbolName);

    QListWidget *listWidget;
    QDialogButtonBox *buttonBox;
    int id;
};

#endif // FLOWCHARTSYMBOLPICKER_H
