#include "Position.h"
#include<vector>
#include<sstream>
#include<fstream>


class PlayablePosition : public Position {
public:
    bool canPlay() override {
        return false;
    }
};

