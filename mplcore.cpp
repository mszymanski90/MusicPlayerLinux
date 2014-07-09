#include "mplcore.h"

MPLCore::MPLCore()
{
    _currentHStream = 0;
    _logger = NULL;
}

void MPLCore::init(LoggerDevice *logger)
{
    _logger = logger;

    if (!BASS_Init(-1,44100,0,0,NULL))
        _logger->log(std::string("Cannot initialize device"));
}

void MPLCore::loadFile(std::string filePath)
{
    HSTREAM str;
    char file[MAX_PATH]="";

    _logger->log(filePath);

    filePath.copy(file, MAX_PATH);

    if(str=BASS_StreamCreateFile(FALSE,file,0,0,0))
    {
        _currentHStream = str;
        _logger->log(std::string("File loaded succesfully."));
    }
    else
    {
        _logger->log(std::string("Error loading file."));
    }
}

void MPLCore::play()
{
    BASS_ChannelPlay(_currentHStream, TRUE);
    _logger->log(std::string("Play."));
}
