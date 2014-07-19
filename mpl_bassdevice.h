#ifndef MPL_BASSDEVICE_H
#define MPL_BASSDEVICE_H

#include "bass.h"

#ifndef _WIN32
    // fix this value later
    #define MAX_PATH 260
#endif

// M:
// zmienilbym nazwe tego pliku oraz klasy na po prostu "BASSPlayer" i wyciagnal z tej
// klasy interfejs IPlayer. Klasa konkretna Player hermetyzowalaby uzycie biblioteki
// BASS tak, zeby uzytkownik nie wiedzial o jej logice.
class MPL_BASSDevice
{
public:
    MPL_BASSDevice();
    ~MPL_BASSDevice();
    void init();
    // M:
    // Czemu nie std::string albo QString?
    bool play(const char *filePath);
    bool resume();
    bool pause();
    bool stop();
    bool setVolume(int setValue);

private:
    HSTREAM _currentHStream;
    // M:
    // zmienna _file wydaje sie niepotrzebna. Moglbys poprostu przekazywac stringa
    // do funkcji play a potem do openstream i trzymac sam wynik, czyli _currentHStream
    // _file jest potrzebny tylko w momencie tworzenie _currentHStream
    char _file[MAX_PATH];

    void openStream();
};

#endif // MPL_BASSDEVICE_H
