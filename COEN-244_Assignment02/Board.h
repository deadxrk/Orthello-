#ifndef Board_h
#define Board_h
#include<iostream>
#include"Player.h"
#include"Position.h"

using namespace std;
const int BOARD_SIZE = 8;
class Board: public Position
{
private:
    char board[BOARD_SIZE][BOARD_SIZE];
public:
    int yo;
    int yo01;
    
    Board(bool Setting_up_board=true){
        if(Setting_up_board){
            // initization of our board
            cout << "Which position do you want to start with!!!" << endl;
            cin >> yo;
            
            switch(yo)
            {
                case 1:
                    for (int i = 0; i < BOARD_SIZE; i++) {
                        for (int j = 0; j < BOARD_SIZE; j++) {
                            board[i][j] =EMPTY;
                        }
                    }
                    
                    board[2][0] = UNPLAYABLE;
                    board[3][0] = UNPLAYABLE;
                    board[4][0] = UNPLAYABLE;
                    board[5][0] = UNPLAYABLE;
                    board[2][2] = 'W';
                    board[2][3] = 'W';
                    board[3][2] = 'W';
                    board[3][3] = 'W';
                    board[4][4] = 'W';
                    board[4][5] = 'W';
                    board[5][4] = 'W';
                    board[5][5] = 'W';
                    board[2][4] = 'B';
                    board[2][5] = 'B';
                    board[3][4] = 'B';
                    board[3][5] = 'B';
                    board[4][2] = 'B';
                    board[4][3] = 'B';
                    board[5][2] = 'B';
                    board[5][3] = 'B';
                    break;
                    
                    
                case 2:
                    for (int i = 0; i < BOARD_SIZE; i++) {
                        for (int j = 0; j < BOARD_SIZE; j++) {
                            board[i][j] = EMPTY;
                        }
                    }
                    board[2][0] = UNPLAYABLE;
                    board[3][0] = UNPLAYABLE;
                    board[4][0] = UNPLAYABLE;
                    board[5][0] = UNPLAYABLE;
                    cout<<"Enter sub preffered position!!";
                    cin>>yo01;
                    
                    switch(yo01)
                    {
                        case 1:
                            board[2][2] = 'W';
                            board[3][3] = 'W';
                            board[2][3] = 'B';
                            board[3][2] = 'B';
                            break;
                        case 2:
                            board[2][4] = 'W';
                            board[3][5] = 'W';
                            board[2][5] = 'B';
                            board[3][4] = 'B';
                            break;
                        case 3:
                            board[4][2] = 'W';
                            board[5][3] = 'W';
                            board[5][2] = 'B';
                            board[4][3] = 'B';
                            break;
                        case 4:
                            board[4][4] = 'W';
                            board[5][5] = 'W';
                            board[4][5] = 'B';
                            board[5][4] = 'B';
                            break;
                    }
                    break;
            }
        }
    }
    char getBoardCell(int, int);
    void drawBoard();
    bool MoveValidation(int,int,char);
    void takeTurn(int,int,char);
    bool isGameOver();
    void flipPieces(int,int,char);
    void flipPiecesInDirection(int,int,int,int,char);
    void findPlayablePositions(vector<pair<int, int>>&, char);
    void setBoardcell(int row,int col,char value)
    {board[row][col]=value;}
};

#endif
