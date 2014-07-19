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
// M�g�by� zamiast dawa� przedrostek MPL do wszystkiego przenie�� pliki od mpl
// do folderu mpl/ albo core/. Poza tym zamiast nazywa� klasy z przedrostkiem MPL
// (kt�ry jest na dobr� spraw� nazw� aplikiacji i nie informuje o niczym, m�g�by�
// u�ywa� namespace'�w. Proponuj� namespace core/ albo player/ bo nazwa mpl/ o
// o niczym nie informuje i mo�e si� komu� pomyli� z meta-programming-language
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
// Z punktu widzenia u�ytkownika, klasa ta jest bardzo podobna do klasy MPL_BASSDevice
// Jak dla mnie to ta klasa powinna trzyma� state, oraz tworzy� MPL_BASSDevice i
// przekazywa� go do state'�w. Ona by�aby ju� pod��czona przez sloty do
// odpowiednich przycisk�w i kontrolek steruj�cych odtwarzaniem.
// Mog�aby si� nazywa� PlayerControl czy jako� tak.
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
    // czemu raw pointer? A poza tym, chyba tego na razie nie u�ywasz wi�c, lepiej
    // nie pisz kodu "na przysz�o��" :)
    LoggerDevice* _logger;
    // M:
    // czemu nie std::string albo QString?
    char* _filePath;
};

#endif // MPLCORE_H
