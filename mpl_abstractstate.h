#ifndef MPL_ABSTRACTSTATE_H
#define MPL_ABSTRACTSTATE_H

// M:
// W sumie ten wzorzec nawet fajnie pasuje, ale proponowa�bym tutaj jedn� modyfikacj�.
// Modyfikacja ta polega na dodaniu pola IPlayer dla ka�dego state'u tak aby
// delegowa� on odtwarzanie do tej klasy, zajmuj�c si� sam� logik� maszyny stan�w.
// W pliku MPLCore.hpp zaproponowa�em stworzenie interfejsu IPlayer, wprowadzenie
// klasy konkretnej BASSPlayer (w�a�ciwie adaptera) oraz wprowadzenie namespace'u
// player. Tutaj napisz� jak widz� interfejs takiego state'u oraz przyk�adowy state:
/*
namespace player {

class IPlayerState
{
public:
    virtual IPlayerState* play(const std::string &filePath) = 0;
    virtual IPlayerState* pause() = 0;
    virtual IPlayerState* stop() = 0;
    virtual ~IPlayerState() {}
};

class ExampleState : public IPlayerState
{
public:
    ExampleState(std::shared_ptr<IPlayer> player) : player_(player) {}
    virtual IPlayerState* play(const std::string &filePath)
    {
        player_->play(filePath);
        return this;
    }
    virtual IPlayerState* pause() {...}
    virtual IPlayerState* stop() {...}
private:
    std::shared_ptr<IPlayer> player_;
};

}  // namespace player
*/


class MPL_AbstractState
{
public:
    virtual MPL_AbstractState* play(const char *filePath) = 0;
    virtual MPL_AbstractState* pause() = 0;
    virtual MPL_AbstractState* stop() = 0;
};

#endif // MPL_ABSTRACTSTATE_H
