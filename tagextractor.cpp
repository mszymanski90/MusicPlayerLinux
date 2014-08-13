#include <tag.h>
#include <fileref.h>
#include <tpropertymap.h>
#include <QTime>
#include "tagextractor.h"

QString TagExtractor::getTitle(QString filePath)
{
    TagLib::FileRef f(filePath.toStdString().c_str());
    TagLib::String title = f.tag()->title();
    return QString(title.toCString());
}

QString TagExtractor::getArtist(QString filePath)
{
    TagLib::FileRef f(filePath.toStdString().c_str());
    TagLib::String artist = f.tag()->artist();
    return QString(artist.toCString());
}

QString TagExtractor::getAlbum(QString filePath)
{
    TagLib::FileRef f(filePath.toStdString().c_str());
    TagLib::String album = f.tag()->album();
    return QString(album.toCString());
}

QString TagExtractor::getTrackNo(QString filePath)
{
    TagLib::FileRef f(filePath.toStdString().c_str());
    unsigned int trackNo = f.tag()->track();
    return QString::number(trackNo);
}

QString TagExtractor::getDuration(QString filePath)
{
    TagLib::FileRef f(filePath.toStdString().c_str());
    return secondsToTime(f.audioProperties()->length());
}

QString TagExtractor::secondsToTime(int seconds)
{
    QString hours;

    if(seconds/60/60 == 0) hours = "";
    else hours = QString::number(seconds/60/60) + QString(":");

    return  hours +
            QString::number(seconds/60) + QString(":") +
            QString::number(seconds % 60);
}


