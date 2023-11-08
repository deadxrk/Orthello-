#ifndef Position_h
#define Position_h

#include<iostream>

class Position
{
public:
    const char UNPLAYABLE;
    const char EMPTY;
    const char WHITE;
    const char BLACK;
    Position():UNPLAYABLE('*'),EMPTY(' '), WHITE('B'), BLACK('W'){}
  
    virtual bool canPlay()
    {
        return true;
    }
    
    
};



#endif
