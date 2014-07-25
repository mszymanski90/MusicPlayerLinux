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
    BASSPlayer(LoggerDevice &logger, std::function<void(double)> coreUpdatePositionProc);
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
    double getDuration();

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
    std::function<void(double)> coreUpdatePositionProc_;

    void openStream();
    void updatePosition();

    static void CALLBACK closeFileProc(void *user);
    static QWORD CALLBACK fileLenProc(void *user);
    static DWORD CALLBACK fileReadProc(void *buffer, DWORD length, void *user);
    static BOOL CALLBACK fileSeekProc(QWORD offset, void *user);
};

#endif // BASSPLAYER_H
