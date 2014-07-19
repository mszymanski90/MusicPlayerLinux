#ifndef MPL_ABSTRACTSTATE_H
#define MPL_ABSTRACTSTATE_H

// M:
// W sumie ten wzorzec nawet fajnie pasuje, ale proponowalbym tutaj jedna modyfikacje.
// Modyfikacja ta polega na dodaniu pola IPlayer dla kazdego stateu tak aby
// delegowal on odtwarzanie do tej klasy, zajmujac sie sama logika maszyny stanow.
// W pliku MPLCore.hpp zaproponowalem stworzenie interfejsu IPlayer, wprowadzenie
// klasy konkretnej BASSPlayer (wlasciwie adaptera) oraz wprowadzenie namespaceu
// player. Tutaj napisze jak widze interfejs takiego stateu oraz przykladowy state:
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
