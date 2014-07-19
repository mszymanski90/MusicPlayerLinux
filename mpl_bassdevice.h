#ifndef MPL_BASSDEVICE_H
#define MPL_BASSDEVICE_H

#include "bass.h"

#ifndef _WIN32
    // fix this value later
    #define MAX_PATH 260
#endif

// M:
// zmieni�bym nazw� tego pliku oraz klasy na po prostu "BASSPlayer" i wyci�gna� z tej
// klasy interfejs IPlayer. Klasa konkretna Player hermetyzowa�aby u�ycie biblioteki
// BASS tak, �eby u�ytkownik nie wiedzia� o jej logice.
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
    // zmienna _file wydaje si� niepotrzebna. M�g�by� poprostu przekazywa� stringa
    // do funkcji play a potem do openstream i trzyma� sam wynik, czyli _currentHStream
    // _file jest potrzebny tylko w momencie tworzenie _currentHStream
    char _file[MAX_PATH];

    void openStream();
};

#endif // MPL_BASSDEVICE_H
