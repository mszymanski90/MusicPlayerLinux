#ifndef TAGEXTRACTOR_H
#define TAGEXTRACTOR_H

#include <QString>

class TagExtractor
{
public:
    static QString getTitle(QString filePath);
    static QString getArtist(QString filePath);
    static QString getAlbum(QString filePath);
    static QString getTrackNo(QString filePath);
    static QString getDuration(QString filePath);

private:
    // move this to some utility class
    static QString secondsToTime(int seconds);
};

#endif // TAGEXTRACTOR_H
