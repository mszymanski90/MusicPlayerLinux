#include "tagextractor.h"
#include "playlistmodel.h"

PlaylistModel::PlaylistModel(QObject *parent) :
    QAbstractTableModel(parent)
{
    columns.push_back(QString("Artist"));
    columns.push_back(QString("Album"));
    columns.push_back(QString("Track no"));
    columns.push_back(QString("Title"));
    columns.push_back(QString("Duration"));
}

int PlaylistModel::rowCount(const QModelIndex &parent) const
{
    return fileList.size();
}

int PlaylistModel::columnCount(const QModelIndex &parent) const
{
    return columns.size();
}

QVariant PlaylistModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        int c = index.column();
        if(columns.at(c) == QString("Album")) return TagExtractor::getAlbum(fileList.at(index.row()));
        if(columns.at(c) == QString("Artist")) return TagExtractor::getArtist(fileList.at(index.row()));
        if(columns.at(c) == QString("Track no")) return TagExtractor::getTrackNo(fileList.at(index.row()));
        if(columns.at(c) == QString("Title")) return TagExtractor::getTitle(fileList.at(index.row()));
        if(columns.at(c) == QString("Duration")) return TagExtractor::getDuration(fileList.at(index.row()));
    }
    return QVariant();
}

bool PlaylistModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row+count-1);

    endInsertRows();
}

void PlaylistModel::refreshData()
{
    QModelIndex topLeft = createIndex(0, 0);
    QModelIndex bottomRight = createIndex(fileList.size(), 0);
    emit dataChanged(topLeft, bottomRight);
}

void PlaylistModel::appendFile(QString filePath)
{
    insertRows(1, 1);
    fileList.append(filePath);
    if(fileList.size() == 1) currentFile = fileList.begin();
}

void PlaylistModel::insertFileAtPosition(QString filePath, const int position)
{
    fileList.insert(position, filePath);
    if(fileList.size() == 1) currentFile = fileList.begin();
}

void PlaylistModel::removeFileByPosition(const int position)
{
    fileList.removeAt(position);
}

QString PlaylistModel::getFileAtPosition(const int position)
{
    fileList.at(position);
}

QString PlaylistModel::getCurrentFile()
{
    if(!fileList.empty()) return *currentFile;
    else return tr("");
}

void PlaylistModel::next()
{
    if(currentFile != fileList.end()) currentFile++;
}

void PlaylistModel::previous()
{
    if(currentFile != fileList.begin()) currentFile--;
}

bool PlaylistModel::isFileInQueue()
{
    if(currentFile != fileList.end()) return true;
    else return false;
}

void PlaylistModel::resetPlaylist()
{
    currentFile = fileList.begin();
}

int PlaylistModel::getSize()
{
    return fileList.size();
}

