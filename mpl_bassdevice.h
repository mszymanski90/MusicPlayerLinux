#ifndef MPL_BASSDEVICE_H
#define MPL_BASSDEVICE_H

#include "bass.h"

#ifndef _WIN32
    // fix this value later
    #define MAX_PATH 260
#endif

// M:
// zmieni³bym nazwê tego pliku oraz klasy na po prostu "BASSPlayer" i wyci¹gna³ z tej
// klasy interfejs IPlayer. Klasa konkretna Player hermetyzowa³aby u¿ycie biblioteki
// BASS tak, ¿eby u¿ytkownik nie wiedzia³ o jej logice.
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
    // zmienna _file wydaje siê niepotrzebna. Móg³byœ poprostu przekazywaæ stringa
    // do funkcji play a potem do openstream i trzymaæ sam wynik, czyli _currentHStream
    // _file jest potrzebny tylko w momencie tworzenie _currentHStream
    char _file[MAX_PATH];

    void openStream();
};

#endif // MPL_BASSDEVICE_H
