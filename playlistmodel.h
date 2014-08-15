#ifndef PLAYLISTMODEL_H
#define PLAYLISTMODEL_H

#include <QAbstractTableModel>
#include <QVector>

class PlaylistModel : public QAbstractTableModel
{
    Q_OBJECT

    enum PlaybackStatus
    {
        StatusStop = 0,
        StatusPause = 1,
        StatusPlay = 2
    };

public:
    explicit PlaylistModel(QObject *parent = 0);
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    bool insertRows(int row, int count, const QModelIndex & parent = QModelIndex());
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;



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
    void erasePlaylist();
    int getSize();

    void displayPlay();
    void displayPause();
    void displayStop();

signals:
    void songChanged();

public slots:
    void refreshData();
    void songDoubleClicked(const QModelIndex& index);
    void openPlaylist(QString filePath);
    void savePlaylist(QString filePath);

private:
    QVector<QString> columns;
    QVector<QString> fileList;
    int currentFile;
    PlaybackStatus status;
    int currentlyPlayed;

    void refreshPlaylist();
    QString determinePlaybackField(int index) const;
};

#endif // PLAYLISTMODEL_H
