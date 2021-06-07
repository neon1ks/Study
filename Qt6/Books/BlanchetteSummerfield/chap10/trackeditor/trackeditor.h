#ifndef TRACKEDITOR_H
#define TRACKEDITOR_H

#include <QDialog>
#include <QList>

class QDialogButtonBox;
class QTableWidget;

class Track
{
public:
    explicit Track(const QString &title = QString(), int duration = 0);
    virtual ~Track() = default;

    QString title;
    int duration;
};

class TrackEditor : public QDialog
{
    Q_OBJECT

public:
    explicit TrackEditor(QList<Track> *tracks, QWidget *parent = nullptr);
    virtual ~TrackEditor() = default;

    void done(int result) override;

private slots:
    void addTrack();

private:
    QTableWidget *tableWidget;
    QDialogButtonBox *buttonBox;
    QList<Track> *tracks;
};

#endif // TRACKEDITOR_H
