#ifndef Header_h
#define Header_h
#include"Board.h"
#include"Player.h"
#include"Position.h"
#include <fstream>
#include<iostream>


class Game : public Board
{
public:
    string filename;
    void play();
    void save(Board& board, const Player& player1, const Player& player2, const Player& currentPlayer);
    bool load(Board& board, Player& player1,  Player& player2, Player*& currentPlayer);
    };
    

#endif 
