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

#include "core.h"

Core::Core(IPlayerObserver &observer, LoggerDevice &logger) :
    IPlayerSubject(observer),
    logger_(logger),
    player_(*this, logger),
    playbackStopped_(true),
    position_(0.0),
    duration_(0.0)
{
    playerState_.reset(new StateIdle(player_));
}

Core::~Core()
{
}

void Core::init()
{
    player_.init();
}

void Core::loadFile(const char *filePath)
{
    strcpy(filePath_, filePath);
}

void Core::play()
{
    playerState_.reset(playerState_->play(filePath_));
}

void Core::pause()
{
    playerState_.reset(playerState_->pause());
}

void Core::stop()
{
    playerState_.reset(playerState_->stop());
}

void Core::setVolume(float volume)
{
    player_.setVolume(volume);
}

void Core::seek(int timeInSeconds)
{
    playerState_.reset(playerState_->seek(timeInSeconds));
}

void Core::update(bool playbackStopped, double position, double duration)
{
    playbackStopped_ = playbackStopped;
    position_ = position;
    duration_ = duration;
    if(playbackStopped_) playerState_.reset(new StateIdle(player_));
    notify();
}

void Core::notify()
{
    observer_.update(playbackStopped_, position_, duration_);
}


