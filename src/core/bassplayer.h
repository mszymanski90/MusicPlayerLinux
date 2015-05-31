#ifndef BASSPLAYER_H
#define BASSPLAYER_H

#include "iplayer.h"
#include "loggerdevice.h"
#include "bass.h"

#ifndef _WIN32
    // fix this value later
    #define MAX_PATH 260
#endif

class BASSPlayer : public IPlayer
{
public:
    BASSPlayer(IPlayerObserver& observer, LoggerDevice &logger);
    ~BASSPlayer();
    bool init();
    // M:
    // Czemu nie std::string albo QString?
    bool play(const char *filePath);
    bool resume();
    bool pause();
    bool stop();
    bool setVolume(float volume);
    bool seek(int timeInSeconds);

    void notify();

private:
    HSTREAM currentHStream_;
    BASS_FILEPROCS fileprocs;
    // M:
    // zmienna _file wydaje sie niepotrzebna. Moglbys poprostu przekazywac stringa
    // do funkcji play a potem do openstream i trzymac sam wynik, czyli _currentHStream
    // _file jest potrzebny tylko w momencie tworzenie _currentHStream
    char file_[MAX_PATH];
    LoggerDevice &logger_;
    FILE *file;
    bool playbackStopped_;

    void openStream();
    double getPositionInSeconds();
    double getDurationInSeconds();

    static void CALLBACK closeFileProc(void *user);
    static QWORD CALLBACK fileLenProc(void *user);
    static DWORD CALLBACK fileReadProc(void *buffer, DWORD length, void *user);
    static BOOL CALLBACK fileSeekProc(QWORD offset, void *user);

    static void CALLBACK endReachedProc(HSYNC handle, DWORD channel, DWORD data, void *user);
};

#endif // BASSPLAYER_H
