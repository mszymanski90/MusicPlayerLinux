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
    BASSPlayer(LoggerDevice &logger);
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

private:
    HSTREAM currentHStream_;
    // M:
    // zmienna _file wydaje sie niepotrzebna. Moglbys poprostu przekazywac stringa
    // do funkcji play a potem do openstream i trzymac sam wynik, czyli _currentHStream
    // _file jest potrzebny tylko w momencie tworzenie _currentHStream
    char file_[MAX_PATH];
    LoggerDevice &logger_;

    void openStream();
};

#endif // BASSPLAYER_H
