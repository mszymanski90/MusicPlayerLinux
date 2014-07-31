#ifndef PLAYLISTMODEL_H
#define PLAYLISTMODEL_H

#include <QAbstractTableModel>
#include <QList>

class PlaylistModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit PlaylistModel(QObject *parent = 0);
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    bool insertRows(int row, int count, const QModelIndex & parent = QModelIndex());

    void refreshData();

    // TODO: modify this to use iterators
    void appendFile(QString filePath);
    void insertFileAtPosition(QString filePath, const int position);
    void removeFileByPosition(const int position);
    QString getFileAtPosition(const int position);

    QString getCurrentFile();
    void next();
    void previous();
    bool isFileInQueue();
    void resetPlaylist();
    int getSize();

signals:

public slots:

private:
    QList<QString> fileList;
    QList<QString>::iterator currentFile;
};

#endif // PLAYLISTMODEL_H
