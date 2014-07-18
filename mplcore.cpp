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

#include "mplcore.h"

void MPLCore::openStream()
{
    HSTREAM str;

    if(str=BASS_StreamCreateFile(FALSE, _file, 0, 0, 0))
    {
        _currentHStream = str;
        _streamLoaded = true;
        _logger->log(std::string("File loaded succesfully."));
    }
    else
    {
        std::stringstream err_msg;
        err_msg << "BASS error code: " << BASS_ErrorGetCode();
        _logger->log(err_msg.str());
    }
}

MPLCore::MPLCore()
{
    _currentHStream = 0;
    _logger = NULL;
    _fileNameLoaded = false;
    _streamLoaded = false;
}

MPLCore::~MPLCore()
{
    BASS_Free();
}

void MPLCore::init(LoggerDevice *logger)
{
    _logger = logger;

    if(!BASS_Init(-1,44100,0,0,NULL))
        _logger->log(std::string("Cannot initialize device"));
}

void MPLCore::loadFile(const char *filePath, int size)
{
    //_logger->log(std::string("Loading: ") + filePath);
    strcpy(_file, filePath);
    _fileNameLoaded = true;
}

void MPLCore::play()
{
    if(_fileNameLoaded)
    {
        if(!_streamLoaded)
        {
            _logger->log(std::string("Opening stream."));
            openStream();
            BASS_ChannelPlay(_currentHStream, TRUE);
        }
        else
        {
            if(!BASS_ChannelPlay(_currentHStream, FALSE))
            {
                _logger->log(std::string("Error resuming playback."));
            }
        }

        _logger->log(std::string("Play."));
    }
    else
    {
        _logger->log(std::string("Called play() with no file name loaded."));
    }
}

void MPLCore::pause()
{
    if(_currentHStream != LB_ERR) BASS_ChannelStop(_currentHStream);
    _logger->log(std::string("Pause."));
}

void MPLCore::stop()
{
    if(_streamLoaded)
    {
        _streamLoaded = false;
        BASS_ChannelStop(_currentHStream);
        BASS_StreamFree(_currentHStream);
    }

    _logger->log(std::string("Stop."));
}


