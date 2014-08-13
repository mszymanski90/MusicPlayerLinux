#include "tagextractor.h"
#include "playlistmodel.h"

PlaylistModel::PlaylistModel(QObject *parent) :
    QAbstractTableModel(parent)
{
}

int PlaylistModel::rowCount(const QModelIndex &parent) const
{
    return fileList.size();
}

int PlaylistModel::columnCount(const QModelIndex &parent) const
{
    return 4;
}

QVariant PlaylistModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        return TagExtractor::getTitle(fileList.at(index.row()));
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

