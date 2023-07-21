#include<iostream>
#include<cstdlib>

class Board{
    public:
        bool status[4][4];
        char player[4][4];
        Board(){
            for (int row = 1; row <= 3; ++row)
                for (int col = 1; col <= 3; ++col)
                    status[row][col] = false,
                    player[row][col] = '_';
            player[3][1] = player[3][2] = player[3][3] = ' ';
        }
};

Board board;
bool draw;
char winner;

void startGame();
void printBoard();
bool checkFinished();
void generateCoordinates();
bool checkWin();
bool checkDraw();
bool checkRow();
bool checkCol();
bool checkDiags();

void generateCoordinates(int & x, int & y){
    x = 1 + (rand() % 3);
    y = 1 + (rand() % 3);
}

bool checkRow(int row){
    if (board.player[row][1] == board.player[row][2] && board.player[row][1] == board.player[row][3])
        if (board.player[row][1] != '_' && board.player[row][1] != ' ')
            return true;
    return false;
}

bool checkCol(int col){
    if (board.player[1][col] == board.player[2][col] && board.player[1][col] == board.player[3][col])
        if (board.player[1][col] != '_' && board.player[1][col] != ' ')
            return true;
    return false;
}

bool checkDiags(){
    if (board.player[1][1] == board.player[2][2] && board.player[1][1] == board.player[3][3])
        if (board.player[1][1] != '_' && board.player[1][1] != ' ')
            return true;
    if (board.player[1][3] == board.player[2][2] && board.player[1][3] == board.player[3][1])
        if (board.player[2][2] != '_' && board.player[2][2] != ' ')
            return true;
    return false;
}

bool checkWin(){
    if (checkRow(1) == true || checkCol(1) == true){
        winner = board.player[1][1];
        return true;
    }
    if (checkRow(2) == true || checkCol(2) == true){
        winner = board.player[2][2];
        return true;
    }
    if (checkRow(3) == true || checkCol(3) == true){
        winner = board.player[3][3];
        return true;
    }
    if (checkDiags() == true){
        winner = board.player[2][2];
        return true;
    }

    return false;
}

bool checkDraw(){
    for (int row = 1; row <= 3; ++row)
        for (int col = 1; col <= 3; ++col)
            if (board.status[row][col] == false)
                return false;
    return (draw = true);
}

int main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    startGame();
    printBoard();

    while (true){
        std::cout << "Choose a cell(1-1 ---> 3-3):\n";
        int x, y;
        std::cin >> x >> y;
        board.status[x][y] = true;
        board.player[x][y] = 'X';

        if (checkDraw() == true || checkWin() == true){
            printBoard();
            break;
        }

        x = y = 0;
        generateCoordinates(x, y);

        while (board.status[x][y] == true)
            generateCoordinates(x, y);

        board.status[x][y] = true;
        board.player[x][y] = '0';

        printBoard();

        if (checkDraw() == true || checkWin() == true)
            break;
    }
    if (draw == true){
        std::cout << "The game is a draw!";
    }
    else {
        if (winner == 'X')
            std::cout << "You win!";
        else std::cout<< "0 wins! Noob!";
    }
}

void startGame(){
    std::cout << "Hello! Let's play some Tic Tac Toe!\nPress any key to continue...\n";
    system("read");
}

void printBoard(){
    std::cout << "  |  |  \n";
    std::cout << "_" << board.player[1][1] << "|_" << board.player[1][2] << "|_" << board.player[1][3] <<"\n";
    std::cout << "  |  |  \n";
    std::cout << "_" << board.player[2][1] << "|_" << board.player[2][2] << "|_" << board.player[2][3] <<"\n";
    std::cout << "  |  |  \n";
    std::cout << " " << board.player[3][1] << "| " << board.player[3][2] << "| " << board.player[3][3] <<"\n";
}