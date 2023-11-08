
#include<iostream>
#include "Game.h"
#include "Position.h"
using namespace std;
int main() {
    int choice;
    bool quit = false;
    string filename;
    string name1;
    string name2;
   // Game game;
    //Board board(false);
    //Player player1("",BLACK);
   // Player player2("",WHITE);
    
    
    while (!quit) {
        cout << "Menu For the Game:" << endl;
        cout << "1. Quit" << endl;
        cout << "2. Start a New Game" << endl;
        cout << "3. Load a Game" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        
        switch (choice) {
            case 1:{
                quit = true;
                break;
            }
            case 2:
            {   cout<<"Enter Player 1 Name:"<<endl;
                cin>>name1;
                cout<<"Enter Player 2 Name:"<<endl;
                cin>>name2;
                Game game;
                game.play();
                break;
            }
            case 3:
            {   cout<<"Enter a filename to load"<<endl;
                cin>>filename;
                break;
                
            }
            default:
            cout << "Invalid choic!! Try Valid Options(1-3)" << endl;
            break;
                
        }
    }
        
        
        
        
    return 0;
}
