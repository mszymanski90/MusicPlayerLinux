#ifndef MPL_ABSTRACTSTATE_H
#define MPL_ABSTRACTSTATE_H

// M:
// W sumie ten wzorzec nawet fajnie pasuje, ale proponowa³bym tutaj jedn¹ modyfikacjê.
// Modyfikacja ta polega na dodaniu pola IPlayer dla ka¿dego state'u tak aby
// delegowa³ on odtwarzanie do tej klasy, zajmuj¹c siê sam¹ logik¹ maszyny stanów.
// W pliku MPLCore.hpp zaproponowa³em stworzenie interfejsu IPlayer, wprowadzenie
// klasy konkretnej BASSPlayer (w³aœciwie adaptera) oraz wprowadzenie namespace'u
// player. Tutaj napiszê jak widzê interfejs takiego state'u oraz przyk³adowy state:
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
