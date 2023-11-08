#ifndef Player_h
#define Player_h

#include<iostream>
#include<string>
using namespace std;
class Player
{
public:
    Player(string,char);
    //Player();
    string getName() ;
    char getSymbol();
private:
    string name;
    char colour;
};



#endif
