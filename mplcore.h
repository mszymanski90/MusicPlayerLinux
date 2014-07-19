/*
    Copyright (c) 2014 Maciej Szymański, Volodymyr Tsiesielski

    This file is part of Music Player Linux.

    Music Player Linux is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    Music Player Linux is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Music Player Linux; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
// M:
// zrobic folder core
// uzywac namespace'ow
// nie uzywac przedrostka mpl
#ifndef MPLCORE_H
#define MPLCORE_H

#include <string>
#include <sstream>
#include <memory>
#include "mpl_abstractstate.h"
#include "mpl_bassdevice.h"
#include "mpl_stateidle.h"
#include "mpl_statepaused.h"
#include "mpl_stateplayback.h"
#include "loggerdevice.h"

// M:
// Z punktu widzenia uzytkownika, klasa ta jest bardzo podobna do klasy MPL_BASSDevice
// Jak dla mnie to ta klasa powinna trzymac state, oraz tworzyc MPL_BASSDevice i
// przekazywac go do state'ow. Ona bylaby juz podlaczona przez sloty do
// odpowiednich przyciskow i kontrolek sterujacych odtwarzaniem.
// Moglaby sie nazywac PlayerControl czy jakos tak.
class MPLCore
{
public:
    MPLCore();
    ~MPLCore();
    void init(LoggerDevice* logger);
    void loadFile(const char* filePath, int size);
    void play();
    void pause();
    void stop();
    void setVolume();

private:
    MPL_BASSDevice playbackDevice;
    std::unique_ptr<MPL_AbstractState> playerState;
    // M:
    // czemu raw pointer? A poza tym, chyba tego na razie nie uzywasz wiec, lepiej
    // nie pisz kodu "na przyszlosc" :)
    LoggerDevice* _logger;
    // M:
    // czemu nie std::string albo QString?
    char* _filePath;
};

#endif // MPLCORE_H
