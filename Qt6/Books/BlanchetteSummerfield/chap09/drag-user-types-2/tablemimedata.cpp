#include "tablemimedata.h"

TableMimeData::TableMimeData(const QTableWidget *tableWidget,
        const QTableWidgetSelectionRange &range)
{
    myTableWidget = tableWidget;
    myRange = range;
    myFormats << "text/csv"
              << "text/html"
              << "text/plain";
}

QStringList TableMimeData::formats() const
{
    return myFormats;
}

QVariant TableMimeData::retrieveData(
        const QString &mimeType, QMetaType type) const
{
    if (mimeType == "text/plain") {
        return rangeAsPlainText();
    }
    if (mimeType == "text/csv") {
        return toCsv(rangeAsPlainText());
    }
    if (mimeType == "text/html") {
        return toHtml(rangeAsPlainText());
    }
    return QMimeData::retrieveData(mimeType, type);
}

QString TableMimeData::toCsv(const QString &plainText)
{
    QString result = plainText;
    result.replace("\\", "\\\\");
    result.replace("\"", "\\\"");
    result.replace("\t", "\", \"");
    result.replace("\n", "\"\n\"");
    result.prepend("\"");
    result.append("\"");
    return result;
}

QString TableMimeData::toHtml(const QString &plainText)
{
    // QString result = Qt::escape(plainText);
    QString result = plainText.toHtmlEscaped();
    result.replace("\t", "<td>");
    result.replace("\n", "\n<tr><td>");
    result.prepend("<table>\n<tr><td>");
    result.append("\n</table>");
    return result;
}
