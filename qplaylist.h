#ifndef QPLAYLIST_H
#define QPLAYLIST_H

#include <QListWidget>
#include <QString>

class QPlaylist : public QListWidget
{
    Q_OBJECT
public:
    explicit QPlaylist(QWidget *parent = 0);
    QString getSong();
    bool songInQueue();
    void resetPlaylist();

signals:

public slots:
    void addSong();
    void setNextSong();
    void setPreviousSong();

private:
    QListWidgetItem* currentListItem;

};

#endif // QPLAYLIST_H
