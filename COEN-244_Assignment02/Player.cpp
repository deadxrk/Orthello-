#include "Player.h"


Player::Player(string name, char colour)
{
    this->name = name;
    this->colour = colour;
}
string Player::getName() {
    return name;
    }
char Player::getSymbol() {
    return colour;
    }
