#include "playlistmodel.h"

PlaylistModel::PlaylistModel(QObject *parent) :
    QAbstractTableModel(parent),
    fieldsCount_(0)
{
    fieldsCount_ = 1;
}

int PlaylistModel::rowCount(const QModelIndex &parent) const
{
    return fileList_.getSize();
}

int PlaylistModel::columnCount(const QModelIndex &parent) const
{
    return fieldsCount_;
}

QVariant PlaylistModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        return fileList_.getFileAtPosition(index.row());
    }
    return QVariant();
}

QString PlaylistModel::getCurrentFile()
{
    return fileList_.getCurrentFile();
}

bool PlaylistModel::endReached()
{
    return fileList_.endReached();
}

PlaylistModel::FileList::FileList()
{
}

void PlaylistModel::FileList::appendFile(QString filePath)
{
    data.append(filePath);
    if(data.size() == 1) currentFile = data.begin();
}

void PlaylistModel::FileList::insertFileAtPosition(QString filePath, const int position)
{
    data.insert(position, filePath);
    if(data.size() == 1) currentFile = data.begin();
}

void PlaylistModel::FileList::removeFileByPosition(const int position)
{
    data.removeAt(position);
}

QString PlaylistModel::FileList::getFileAtPosition(const int position)
{
    data.at(position);
}

QString PlaylistModel::FileList::getCurrentFile()
{
    if(!data.empty()) return *currentFile;
    else return tr("");
}

bool PlaylistModel::FileList::endReached()
{
    if(currentFile == data.end()) return true;
    else return false;
}

void PlaylistModel::FileList::resetPlaylist()
{
    currentFile = data.begin();
}

int PlaylistModel::FileList::getSize()
{
    return data.size();
}
