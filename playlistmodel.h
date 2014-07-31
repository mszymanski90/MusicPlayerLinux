#ifndef PLAYLISTMODEL_H
#define PLAYLISTMODEL_H

#include <QAbstractTableModel>
#include <QList>

class PlaylistModel : public QAbstractTableModel
{
    Q_OBJECT

    class FileList
    {
    public:
        FileList();
        // TODO: modify this to use iterators
        void appendFile(QString filePath);
        void insertFileAtPosition(QString filePath, const int position);
        void removeFileByPosition(const int position);
        QString getFileAtPosition(const int position);
        QString getCurrentFile();
        bool endReached();
        void resetPlaylist();
        int getSize();

    private:
        QList<QString> data;
        QList::iterator currentFile;
    };

public:
    explicit PlaylistModel(QObject *parent = 0);
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    QString getCurrentFile();
    bool endReached();

signals:

public slots:

private:
    int fieldsCount_;

    FileList fileList_;

};

#endif // PLAYLISTMODEL_H
