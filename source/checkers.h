#include <sys/stat.h>
#include <string.h>
#include <3ds.h>

typedef struct space{
    //x for player 1, or X for P1 /w King, o for Player 2, O for P2 with King
	//idea: just use x and o for p1 and p2, and use the isKing field for kings
    char player;
    int isKing;
    int Xcoord, Ycoord;
}Space, *SpacePtr;

typedef struct board{
    SpacePtr spaces[8][8];
}Board, *BoardPtr;

typedef struct node{
    struct node* next;
    int x, y;
    int isKing;
}Node, *NodePtr;

typedef struct linkedlist{
    NodePtr head;
    char player;
    int numPieces;
}LinkedList, *LinkedListPtr;

BoardPtr initBoard(LinkedListPtr p1, LinkedListPtr p2);

void displayBoard(BoardPtr board, PrintConsole *top, PrintConsole *bottom);

void move_(BoardPtr board, LinkedListPtr cp, LinkedListPtr op, LinkedListPtr p1, LinkedListPtr p2,  int x, int y, int i, int j, int dir, int isKing, PrintConsole *top, PrintConsole *bottom);
//x and y are starting coords; i and j are destination coords;
//isJump tells it to remove the piece between the coord pairs;
//cp is current player; op is opposing player

void refresh(BoardPtr board, LinkedListPtr p1, LinkedListPtr p2, PrintConsole *top, PrintConsole *bottom);

//checkMovable checks that a specific move_() call is legal
int checkLegal(BoardPtr board, LinkedListPtr player, int x, int y, int dir, int isKing);
//1 means legal, 0 means illegal, 2 means legal jump

int isOut(int x, int y);
//1 means out of bounds

//void addMoveablepiece(int* X, int* Y, int i, int j);

//BoardPtr finishMove(BoardPtr board, int x, int y);

LinkedListPtr addPiece(LinkedListPtr player, BoardPtr board, int x, int y, int isKing);

LinkedListPtr removePiece(LinkedListPtr player, int x, int y);

void updateBoard(BoardPtr board, LinkedListPtr p1, LinkedListPtr p2);

int takeTurn(BoardPtr board, char* player, LinkedListPtr currentPlayer, LinkedListPtr waitingPlayer, LinkedListPtr p1, LinkedListPtr p2, PrintConsole *top, PrintConsole *bottom);
