#include "Game.h"

    // implementation of the game logic
    void Game::save(Board& board, const Player& player1, const Player& player2, const Player& currentPlayer) {
        string filename;
        cout << "Enter filename to save the game: ";
        cin >> filename;

        ofstream outFile(filename);
        if (outFile.is_open()) {
        //outFile << player1.getName() << endl;
        //outFile << player2.getName() << endl;
        //outFile << currentPlayer.getName() << endl;

            for (int i = 0; i < BOARD_SIZE; i++) {
                for (int j = 0; j < BOARD_SIZE; j++) {
                    outFile << board.getBoardCell(i, j);
                }
            }
            outFile.close();
            cout << "Game saved successfully." << endl;
        }
        else {
            cout << "Unable to open file for saving." << endl;
        }
    }

void Game::play() {
    Board board;
    Player player1("Player 1", BLACK);
    Player player2("Player 2", WHITE);
    Player* currentPlayer = &player2;
    bool gameOver = false;
    bool MoveValidation = true;
    while (!gameOver) {
        board.drawBoard();
        
        int action;
        cout << currentPlayer->getName() << "\nMake your choice: " << endl;
        cout << "1. Make a move" << endl;
        cout << "2. Save game" << endl;
        cout << "3. Concede game" << endl;
        cout << "4. Forfeit turn" << endl;
        cin >> action;
        
        switch (action) {
            case 1:
                // Make a move
                cout << "Enter your move (row, col): ";
                int row, col;
                cin >> row >> col;
                
                if (board.MoveValidation(row, col, currentPlayer->getSymbol())) {
                    board.takeTurn(row, col, currentPlayer->getSymbol());
                    if (board.isGameOver()) {
                        gameOver = true;
                    }
                    else {
                        // switch to the other player
                        currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
                    }
                }
                else {
                    cout << "Invalid move. Try again." << endl;
                }
                break;
            case 2:
                // Save game
                save(board, player1, player2, *currentPlayer);
                break;
            case 3:
                // Concede game
                gameOver = true;
                cout << currentPlayer->getName() << " has conceded the game." << endl;
                break;
            case 4:
                // Forfeit turn
                currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
                cout << currentPlayer->getName() << " has forfeited their turn." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
                break;
        }
    }
    
    board.drawBoard();
    cout << "Game over." << endl;
}
bool Game::load(Board& board, Player& player1,  Player& player2, Player*& currentPlayer)
{
    string filename;
    cout<<"Enter filename to load the game:"<<endl;
    cin>>filename;
    ifstream inFile(filename);
    if(inFile.is_open()){
        string line;
        getline(inFile,line);
        player1=Player(line,BLACK);//white or black(x)
        getline(inFile,line);
        player2=Player(line,WHITE);//O
        getline(inFile,line);
        if (line == player1.getName()) {
                        currentPlayer = &player1;
                    }
                    else if (line == player2.getName()) {
                        currentPlayer = &player2;
                    }
                    else {
                        cout << "Invalid saved game file." << endl;
                        inFile.close();
                        return false;
                    }
        getline(inFile,line);
        int idx=0;
                    for (int i = 0; i < BOARD_SIZE; i++) {
                        getline(inFile, line);
                        for (int j = 0; j < BOARD_SIZE; j++) {
                            board.setBoardcell(i, j, line[idx]);
                            idx++;
                        }
                    }
                    inFile.close();
       // board.isLoaded=true;
                    cout << "Game loaded successfully." << endl;
                    return true;
                }
                else {
                    cout << "Unable to open file for loading." << endl;
                    return false;
                }
            }

