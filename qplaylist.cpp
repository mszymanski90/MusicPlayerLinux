#include <QFileDialog>
#include "qplaylist.h"

QPlaylist::QPlaylist(QWidget *parent) :
    QListWidget(parent),
    currentListItem(nullptr)
{
}

QString QPlaylist::getSong()
{
    if(currentListItem != nullptr) return currentListItem->text();
    else return tr("");
}

bool QPlaylist::songInQueue()
{
    if(currentListItem != nullptr) return true;
    else return false;
}

void QPlaylist::resetPlaylist()
{
    currentListItem = item(0);
}

void QPlaylist::addSong()
{
    QString fileName = QFileDialog::getOpenFileName(this,
         tr("Open file"), "/home/jana", tr("Image Files (*.mp3 *.m4a *.ogg)"));

    if(QFile::exists(fileName))
    {
        // when this is deleted ?
        QListWidgetItem* newListItem = new QListWidgetItem(fileName, this);
        if(currentListItem == nullptr) currentListItem = newListItem;
    }
}

void QPlaylist::setNextSong()
{
    int i = row(currentListItem);
    currentListItem = item(i+1);
    if(currentListItem == 0) currentListItem = nullptr;
}

void QPlaylist::setPreviousSong()
{
    int i = row(currentListItem);
    if(i != 0)
    {
        currentListItem = item(i-1);
    }
    else
    {
        currentListItem = nullptr;
    }
}
