#include "Board.h"
char Board::getBoardCell(int row, int col) {
    return board[row][col];
}


void Board::drawBoard() {
    // display the current state of the board
    cout << "  ";
    for (int i = 0; i < BOARD_SIZE; i++) {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < BOARD_SIZE; i++) {
        cout << i << " ";
        for (int j = 0; j < BOARD_SIZE; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
bool Board::MoveValidation(int row, int col, char colour) {
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
        
        return false;
    }
    if (board[row][col] != EMPTY) {
        // check if space is already occupied
        return false;
    }
if (col == 0 && (row == 2 || row == 3 || row == 4 || row == 5 )) {
    return false;
    }
    // check if the move does any change to pieces
    return true;
}

void Board::takeTurn(int row, int col, char symbol) {
// updated board
    board[row][col] = symbol;
    flipPieces(row, col, symbol);
}

bool Board::isGameOver() {
// check for no move possible
    bool boardFull = true;
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == EMPTY) {
                boardFull = false;
                break;
            }
        }
        if (!boardFull) {
            break;
        }
    }
    if (boardFull) {
        return true;
    }
// confirms if a player has any moves left
    vector<pair<int, int>> positions;
    findPlayablePositions(positions,WHITE );
    if (positions.size() > 0) {
        positions.clear();
        findPlayablePositions(positions, BLACK);
        if (positions.size() > 0) {
            return false;
        }
    }

    return true;
}


void Board::flipPieces(int row, int col, char symbol) {
    flipPiecesInDirection(row, col, -1, 0, symbol);
    flipPiecesInDirection(row, col, 1, 0, symbol);
    flipPiecesInDirection(row, col, 0, -1, symbol);
    flipPiecesInDirection(row, col, 0, 1, symbol);
    flipPiecesInDirection(row, col, -1, -1, symbol);
    flipPiecesInDirection(row, col, -1, 1, symbol);
    flipPiecesInDirection(row, col, 1, -1, symbol);
    flipPiecesInDirection(row, col, 1, 1, symbol);
    }

void Board::flipPiecesInDirection(int row, int col, int deltaRow, int deltaCol, char symbol) {
    int r = row + deltaRow;
    int c = col + deltaCol;

    while (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE && board[r][c] != symbol && board[r][c] != EMPTY) {
            r += deltaRow;
            c += deltaCol;
    }

    if (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE && board[r][c] == symbol) {
        // flip the pieces in concurrent direction
        r -= deltaRow;
        c -= deltaCol;
        while (r != row || c != col) {
            board[r][c] = symbol;
            r -= deltaRow;
            c -= deltaCol;
        }
    }
}

void Board::findPlayablePositions(vector<pair<int, int>>& positions, char symbol) {
    positions.clear();
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == EMPTY) {
                if (MoveValidation(row, col, symbol)) {
                    positions.push_back(make_pair(row, col));
                }
            }
        }
    }
}

