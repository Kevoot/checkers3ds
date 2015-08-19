#include "checkers.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <3ds.h>
#include <string.h>

BoardPtr initBoard(LinkedListPtr p1, LinkedListPtr p2){
    BoardPtr board;
    int x = 0;
    int y = 0;
    int i = 1;

    board = (BoardPtr)malloc(64 * sizeof(Space));

	p1->player = 'x';
    p2->player = 'o';
	p1->head = NULL;
	p2->head = NULL;
	p1->numPieces=0;
	p2->numPieces=0;

	p2 = addPiece(p2, board, 1, 0, 0);
    p2 = addPiece(p2, board, 3, 0, 0);
    p2 = addPiece(p2, board, 5, 0, 0);
    p2 = addPiece(p2, board, 7, 0, 0);
    p2 = addPiece(p2, board, 0, 1, 0);
    p2 = addPiece(p2, board, 2, 1, 0);
    p2 = addPiece(p2, board, 4, 1, 0);
    p2 = addPiece(p2, board, 6, 1, 0);
    p2 = addPiece(p2, board, 1, 2, 0);
    p2 = addPiece(p2, board, 3, 2, 0);
    p2 = addPiece(p2, board, 5, 2, 0);
    p2 = addPiece(p2, board, 7, 2, 0); 
    

    p1 = addPiece(p1, board, 0, 5, 0);
    p1 = addPiece(p1, board, 2, 5, 0);
    p1 = addPiece(p1, board, 4, 5, 0);
    p1 = addPiece(p1, board, 6, 5, 0);
    p1 = addPiece(p1, board, 1, 6, 0);
    p1 = addPiece(p1, board, 3, 6, 0);
    p1 = addPiece(p1, board, 5, 6, 0);
    p1 = addPiece(p1, board, 7, 6, 0);
    p1 = addPiece(p1, board, 0, 7, 0);
    p1 = addPiece(p1, board, 2, 7, 0);
    p1 = addPiece(p1, board, 4, 7, 0);
    p1 = addPiece(p1, board, 6, 7, 0);
    
    //While loop to set up a grid of 8 x 8 spaces
    while(y < 8){
        while(x < 8){
            board->spaces[x][y] = (SpacePtr)malloc(sizeof(Space));
            board->spaces[x][y]->Xcoord = x;
            board->spaces[x][y]->Ycoord = y;
            board->spaces[x][y]->player = ' '; //this makes it empty
            board->spaces[x][y]->isKing = 0;
            x++;
        }
        x= 0;
        y++;
    }
    return board;
}

LinkedListPtr addPiece(LinkedListPtr player, BoardPtr board, int x, int y, int isKing){
    NodePtr tempNode;
    NodePtr newNode;
    
    newNode = (NodePtr)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;
	newNode->isKing = isKing;

    if(player->head == NULL){
        player->head = newNode;
        player->numPieces++;
        return player;
    }
    
    else{
		tempNode = player->head;
    
		while(tempNode->next != NULL){
		   tempNode = tempNode->next;
		}
    
		tempNode->next = newNode;

		player->numPieces++;

		return player;
	}
}

LinkedListPtr removePiece(LinkedListPtr player, int x, int y){
    NodePtr tempNode, tempNode2;

    tempNode = player->head;
    tempNode2 = tempNode;
	//this loop checks each node until the x and y match
    while(tempNode->x != x || tempNode->y != y){
		tempNode2 = tempNode;
        tempNode = tempNode->next;
    }
	
	if(tempNode == player->head){
		player->head = tempNode->next;
		player->numPieces--;
		return player;
	}
	
    tempNode2->next = tempNode->next;
	
	player->numPieces--;
    
    return player;
    
}

void displayBoard(BoardPtr board, PrintConsole *top, PrintConsole *bottom)
{
	consoleSelect(top);
    consoleClear();


    printf("    0   1   2   3   4   5   6   7  \n");
    printf("  ---------------------------------");
    printf("\n");
    
    printf("0 | %c | %c | %c | %c", board->spaces[0][0]->player, board->spaces[1][0]->player,
           board->spaces[2][0]->player, board->spaces[3][0]->player);
    printf(" | %c | %c | %c | %c |", board->spaces[4][0]->player, board->spaces[5][0]->player,
           board->spaces[6][0]->player, board->spaces[7][0]->player);
    printf("\n");
    printf("  ---------------------------------");
    printf("\n");
    
    
    printf("1 | %c | %c | %c | %c", board->spaces[0][1]->player, board->spaces[1][1]->player,
           board->spaces[2][1]->player, board->spaces[3][1]->player);
    printf(" | %c | %c | %c | %c |", board->spaces[4][1]->player, board->spaces[5][1]->player,
           board->spaces[6][1]->player, board->spaces[7][1]->player);
    printf("\n");
    printf("  ---------------------------------");
    printf("\n");
    
    
    printf("2 | %c | %c | %c | %c", board->spaces[0][2]->player, board->spaces[1][2]->player,
           board->spaces[2][2]->player, board->spaces[3][2]->player);
    printf(" | %c | %c | %c | %c |", board->spaces[4][2]->player, board->spaces[5][2]->player,
           board->spaces[6][2]->player, board->spaces[7][2]->player);
    printf("\n");
    printf("  ---------------------------------");
    printf("\n");
    
    
    printf("3 | %c | %c | %c | %c", board->spaces[0][3]->player, board->spaces[1][3]->player,
           board->spaces[2][3]->player, board->spaces[3][3]->player);
    printf(" | %c | %c | %c | %c |", board->spaces[4][3]->player, board->spaces[5][3]->player,
           board->spaces[6][3]->player, board->spaces[7][3]->player);
    printf("\n");
    printf("  ---------------------------------");
    printf("\n");
    
    
    printf("4 | %c | %c | %c | %c", board->spaces[0][4]->player, board->spaces[1][4]->player,
           board->spaces[2][4]->player, board->spaces[3][4]->player);
    printf(" | %c | %c | %c | %c |", board->spaces[4][4]->player, board->spaces[5][4]->player,
           board->spaces[6][4]->player, board->spaces[7][4]->player);
    printf("\n");
    printf("  ---------------------------------");
    printf("\n");
    
    
    printf("5 | %c | %c | %c | %c", board->spaces[0][5]->player, board->spaces[1][5]->player,
           board->spaces[2][5]->player, board->spaces[3][5]->player);
    printf(" | %c | %c | %c | %c |", board->spaces[4][5]->player, board->spaces[5][5]->player,
           board->spaces[6][5]->player, board->spaces[7][5]->player);
    printf("\n");
    printf("  ---------------------------------");
    printf("\n");
    
    
    printf("6 | %c | %c | %c | %c", board->spaces[0][6]->player, board->spaces[1][6]->player,
           board->spaces[2][6]->player, board->spaces[3][6]->player);
    printf(" | %c | %c | %c | %c |", board->spaces[4][6]->player, board->spaces[5][6]->player,
           board->spaces[6][6]->player, board->spaces[7][6]->player);
    printf("\n");
    printf("  ---------------------------------");
    printf("\n");
    
    
    printf("7 | %c | %c | %c | %c", board->spaces[0][7]->player, board->spaces[1][7]->player,
           board->spaces[2][7]->player, board->spaces[3][7]->player);
    printf(" | %c | %c | %c | %c |", board->spaces[4][7]->player, board->spaces[5][7]->player,
           board->spaces[6][7]->player, board->spaces[7][7]->player);
    printf("\n");
    printf("  ---------------------------------");
    printf("\n");
	consoleSelect(bottom);
}

void updateBoard(BoardPtr board, LinkedListPtr p1, LinkedListPtr p2){
    NodePtr tempNode;
	int x, y;

	for(y = 0; y < 8; y++){
		for(x = 0; x < 8; x++){
			board->spaces[x][y]->player = ' ';
		}
	}
    
    tempNode = p1->head;

    
    while(tempNode != NULL)
    {
        board->spaces[tempNode->x][tempNode->y]->player = p1->player;
		if(tempNode->isKing == 1){
			board->spaces[tempNode->x][tempNode->y]->player = 'X';
		}
        tempNode = tempNode->next;
    }
    
    tempNode = p2->head;
    
    while(tempNode != NULL)
    {
        board->spaces[tempNode->x][tempNode->y]->player = p2->player;
		if(tempNode->isKing == 1){
			board->spaces[tempNode->x][tempNode->y]->player = 'O';
		}
		tempNode = tempNode->next;
    }
    
    return;
    
}

//to refer to a piece, use its xy coords, search through the linked list for a match

//move_() should only be responsible for the actual movement
//when checkLegal succeeds, move_() can be called
void move_(BoardPtr board, LinkedListPtr cp, LinkedListPtr op, LinkedListPtr p1, LinkedListPtr p2,  int x, int y, int i, int j, int dir, int isKing, PrintConsole *top, PrintConsole *bottom)
{
	int ui = 2;
	int a, b, c, d, isJump;
	isJump = checkLegal(board, cp, x, y, dir, isKing);
	removePiece(cp, x, y); //we should take the piece
	addPiece(cp, board, i, j, isKing); //and put it somewhere else
	
	if(isJump == 2)
		removePiece(op, (x+i)/2, (y+j)/2);



	if(j==0 || j==7 || isKing)
	{
		removePiece(cp, i, j);
		addPiece(cp, board, i, j, 1);
	}

	refresh(board, p1, p2, top, bottom);
}

//currently this function is 100% functional!
int checkLegal(BoardPtr board, LinkedListPtr player, int x, int y, int dir, int isKing){
	NodePtr tempNode = player->head;
	char tempChar;
	if(player->player == 'x' || player->player == 'X') //if the passed player is player 1
	{    //then check default orientation (in which 'forward' is up)
		if(tempNode->next != NULL)
			while(tempNode->x != x && tempNode->y != y)
				tempNode = tempNode->next;
		isKing = tempNode->isKing;
		//first, check that the player owns the piece
		if(tolower(board->spaces[x][y]->player) != tolower(player->player) || tolower(board->spaces[x][y]->player) != tolower(player->player)){ //this prob won't work with kings if we're still using capitals
			printf("You can't move a piece at that location, try again.\n");
			return 0;
		}
		//then, check the surroundings
		switch(dir){
		case 1: //up-left or NW
			if(isOut(x-1, y-1))
				return 0; //illegal direction; out of bounds
			if(tolower(board->spaces[x-1][y-1]->player) == tolower(player->player)) //also might fail with the current king implementation
				return 0; //illegal move; blocked by own piece
			if(tolower(board->spaces[x-1][y-1]->player) == ' ')
				return 1; //legal move
			else //if this line is reached, the space is occupied by an enemy piece
				if(isOut(x-2, y-2))
					return 0; //illegal jump; out of bounds
				if(tolower(board->spaces[x-2][y-2]->player) == ' ')
					return 2; //legal jump; the move_() function is responsible for chaining jumps
				else
					return 0; //illegal jump; blocked by another piece
			break;
		case 2: //up-right or NE
			if(isOut(x+1, y-1))
				return 0; //illegal direction; out of bounds
			if(tolower(board->spaces[x+1][y-1]->player) == tolower(player->player)) //also might fail with the current king implementation
				return 0; //illegal move; blocked by own piece
			if(tolower(board->spaces[x+1][y-1]->player) == ' ')
				return 1; //legal move
			else //if this line is reached, the space is occupied by an enemy piece
				if(isOut(x+2, y-2))
					return 0; //illegal jump; out of bounds
				if(tolower(board->spaces[x+2][y-2]->player) == ' ')
					return 2; //legal jump; the move_() function is responsible for chaining jumps
				else
					return 0; //illegal jump; blocked by another piece
			break;
		case 3: //down-left or SW
			if(isOut(x-1, y+1))
				return 0; //illegal direction; out of bounds
			if(isKing){
				if(tolower(board->spaces[x-1][y+1]->player) == tolower(player->player)) //also might fail with the current king implementation
					return 0; //illegal move; blocked by own piece
				if(tolower(board->spaces[x-1][y+1]->player) == ' ')
					return 1; //legal move
				else //if this line is reached, the space is occupied by an enemy piece
					if(isOut(x-2, y+2))
						return 0; //illegal jump; out of bounds
					if(tolower(board->spaces[x-2][y+2]->player) == ' ')
						return 2; //legal jump; the move_() function is responsible for chaining jumps
					else
						return 0; //illegal jump; blocked by another piece
			}
			else
				return 0; //kings can't move backwards
			break;
		case 4: //down-right or SE
			if(isOut(x+1, y+1))
				return 0; //illegal direction; out of bounds
			if(isKing){
				if(tolower(board->spaces[x+1][y+1]->player) == tolower(player->player)) //also might fail with the current king implementation
					return 0; //illegal move; blocked by own piece
				if(tolower(board->spaces[x+1][y+1]->player) == ' ')
					return 1; //legal move
				else //if this line is reached, the space is occupied by an enemy piece
					if(isOut(x+2, y+2))
						return 0; //illegal jump; out of bounds
					if(tolower(board->spaces[x+2][y+2]->player) == ' ')
						return 2; //legal jump; the move_() function is responsible for chaining jumps
					else
						return 0; //illegal jump; blocked by another piece
			}
			else
				return 0; //kings can't move backwards
			break;
		}
	}
	//end of p1-case
	//beginning of p2-case (now 'forward' is down)
	else if(player->player == 'o' || player->player == 'O')
	{
		if(tempNode->next != NULL)
			while(tempNode->x != x && tempNode->y != y)
				tempNode = tempNode->next;
		isKing = tempNode->isKing;
		//first, check that the player owns the piece
		if(tolower(board->spaces[x][y]->player) != tolower(player->player) || tolower(board->spaces[x][y]->player) != tolower(player->player)){ //this prob won't work with kings if we're still using capitals
			printf("That's not your piece to move!\n");
			return 0;
		}
		//then, check the surroundings
		switch(dir){
		case 1: //up-left or NW
			if(isKing)
			{
				if(isOut(x-1, y-1))
					return 0; //illegal direction; out of bounds
				if(tolower(board->spaces[x-1][y-1]->player) == tolower(player->player)) //also might fail with the current king implementation
					return 0; //illegal move; blocked by own piece
				if(tolower(board->spaces[x-1][y-1]->player) == ' ')
					return 1; //legal move
				else //if this line is reached, the space is occupied by an enemy piece
					if(isOut(x-2, y-2))
						return 0; //illegal jump; out of bounds
					if(tolower(board->spaces[x-2][y-2]->player) == ' ')
						return 2; //legal jump; the move_() function is responsible for chaining jumps
					else
						return 0; //illegal jump; blocked by another piece
			}
			break;
		case 2: //up-right or NE
			if(isKing)
			{
				if(isOut(x+1, y-1))
					return 0; //illegal direction; out of bounds
				if(tolower(board->spaces[x+1][y-1]->player) == tolower(player->player)) //also might fail with the current king implementation
					return 0; //illegal move; blocked by own piece
				if(tolower(board->spaces[x+1][y-1]->player) == ' ')
					return 1; //legal move
				else //if this line is reached, the space is occupied by an enemy piece
					if(isOut(x+2, y-2))
						return 0; //illegal jump; out of bounds
					if(tolower(board->spaces[x+2][y-2]->player) == ' ')
						return 2; //legal jump; the move_() function is responsible for chaining jumps
					else
						return 0; //illegal jump; blocked by another piece
			}
			break;
		case 3: //down-left or SW
			if(isOut(x-1, y+1))
				return 0; //illegal direction; out of bounds
			if(tolower(board->spaces[x-1][y+1]->player) == tolower(player->player)) //also might fail with the current king implementation
				return 0; //illegal move; blocked by own piece
			if(tolower(board->spaces[x-1][y+1]->player) == ' ')
				return 1; //legal move
			else //if this line is reached, the space is occupied by an enemy piece
				if(isOut(x-2, y+2))
						return 0; //illegal jump; out of bounds
				if(tolower(board->spaces[x-2][y+2]->player) == ' ')
					return 2; //legal jump; the move_() function is responsible for chaining jumps
				else
					return 0; //illegal jump; blocked by another piece
			break;
		case 4: //down-right or SE
			if(isOut(x+1, y+1))
				return 0; //illegal direction; out of bounds
			if(tolower(board->spaces[x+1][y+1]->player) == tolower(player->player)) //also might fail with the current king implementation
				return 0; //illegal move; blocked by own piece
			if(tolower(board->spaces[x+1][y+1]->player) == ' ')
				return 1; //legal move
			else //if this line is reached, the space is occupied by an enemy piece
				if(isOut(x+2, y+2))
						return 0; //illegal jump; out of bounds
				if(tolower(board->spaces[x+2][y+2]->player) == ' ')
					return 2; //legal jump; the move_() function is responsible for chaining jumps
				else
					return 0; //illegal jump; blocked by another piece
			break;
		}
	}
}

//1 means out of bounds
int isOut(int x, int y){
	if(x < 0 || x > 7 || y < 0 || y > 7)
		return 1;
	return 0;
}

void refresh(BoardPtr board, LinkedListPtr p1, LinkedListPtr p2, PrintConsole *top, PrintConsole *bottom){
	system("cls");
	updateBoard(board, p1, p2);
	displayBoard(board, top, bottom);
}

int takeTurn(BoardPtr board, char* player, LinkedListPtr currentPlayer, LinkedListPtr waitingPlayer, LinkedListPtr p1, LinkedListPtr p2, PrintConsole *top, PrintConsole *bottom){
	int x=0, y=0, j = 0, k = 0, isJump, a=0, b=0, c=0, d=0, temp1, temp2, dir, is_king;
	
	
	u32 kDown/* = hidKeysDown()*/;
	
	printf("\n%s, it is your turn! Please select a piece to move: \nX coordinate?: %d\n", player, x);
	
	while(kDown != KEY_A){
		hidScanInput();
		gspWaitForVBlank();
		
		kDown = hidKeysDown();
		
		if(kDown & KEY_DOWN){
			x--;
			consoleClear();
			displayBoard(board, top, bottom);
			printf("\n%s, Choose a piece to move X: %d\n", player, x);
		}
		if(kDown & KEY_UP){
			x++;
			consoleClear();
			displayBoard(board, top, bottom);
			printf("\n%s, Choose a piece to move X: %d\n", player, x);
		}
		if(kDown & KEY_START){
			p1->numPieces = 0;
			p2->numPieces = 0;
			return 0;
		}
		
	}
	gspWaitForVBlank();
	kDown = NULL;
	
	printf("\nY coordinate?: %d\n", y);
	
	while(kDown != KEY_A){
		hidScanInput();
		gspWaitForVBlank();
		
		kDown = hidKeysDown();
		
		if(kDown & KEY_DOWN){
			y--;
			consoleClear();
			displayBoard(board, top, bottom);
			printf("\n%s, Choose a piece to move Y: %d\n", player, y);

		}
		if(kDown & KEY_UP){
			y++;
			consoleClear();
			displayBoard(board, top, bottom);
			printf("\n%s, Choose a piece to move Y: %d\n", player, y);
		}
		if(kDown & KEY_START){
			p1->numPieces = 0;
			p2->numPieces = 0;
			return 0;
		}
	}
	gspWaitForVBlank();
	kDown = NULL;
	
	if(currentPlayer == p2)
	{
		c = checkLegal(board, currentPlayer, x, y, 3, board->spaces[x][y]->isKing);
		d = checkLegal(board, currentPlayer, x, y, 4, board->spaces[x][y]->isKing);
		if(board->spaces[x][y]->isKing)
		{
			a = checkLegal(board, currentPlayer, x, y, 1, board->spaces[x][y]->isKing);
			b = checkLegal(board, currentPlayer, x, y, 2, board->spaces[x][y]->isKing);
		}
	}
	else
	{
		a = checkLegal(board, currentPlayer, x, y, 1, board->spaces[x][y]->isKing);
		b = checkLegal(board, currentPlayer, x, y, 2, board->spaces[x][y]->isKing);
		c = checkLegal(board, currentPlayer, x, y, 3, board->spaces[x][y]->isKing);
		d = checkLegal(board, currentPlayer, x, y, 4, board->spaces[x][y]->isKing);
	}

	while(a == 0 && b == 0 && c == 0 && d == 0){
		printf("\n You can't move a piece on that location, try again:\nx: %d\n", x);
		while(kDown != KEY_A){
			hidScanInput();
			gspWaitForVBlank();
		
			kDown = hidKeysDown();
		
			if(kDown & KEY_DOWN){
				x--;
				consoleClear();
				displayBoard(board, top, bottom);
				printf("\n%s, Choose a piece to move X: %d\n", player, x);
			}
			if(kDown & KEY_UP){
				x++;
				consoleClear();
				displayBoard(board, top, bottom);
				printf("\n%s, Choose a piece to move X: %d\n", player, x);
			}
			if(kDown & KEY_START){
			p1->numPieces = 0;
			p2->numPieces = 0;
			return 0;
		}
		}
		gspWaitForVBlank();
		
		kDown = NULL;
		
		printf("\nY coordinate?: %d\n", y);
		while(kDown != KEY_A){
			hidScanInput();
			gspWaitForVBlank();
		
			kDown = hidKeysDown();
			
			if(kDown & KEY_DOWN){
				y--;
				consoleClear();
				displayBoard(board, top, bottom);
				printf("\n%s, Choose a piece to move Y: %d\n", player, y);

			}
			if(kDown & KEY_UP){
				y++;
				consoleClear();
				displayBoard(board, top, bottom);
				printf("\n%s, Choose a piece to move Y: %d\n", player, y);
			}
			if(kDown & KEY_START){
			p1->numPieces = 0;
			p2->numPieces = 0;
			return 0;
		}
		}
		gspWaitForVBlank();
		
		kDown = NULL;
		
		if(currentPlayer == p2)
		{
			c = checkLegal(board, currentPlayer, x, y, 3, board->spaces[x][y]->isKing);
			d = checkLegal(board, currentPlayer, x, y, 4, board->spaces[x][y]->isKing);
			if(board->spaces[x][y]->isKing)
			{
				a = checkLegal(board, currentPlayer, x, y, 1, board->spaces[x][y]->isKing);
				b = checkLegal(board, currentPlayer, x, y, 2, board->spaces[x][y]->isKing);
			}
		}
		else if(currentPlayer == p1)
		{
			a = checkLegal(board, currentPlayer, x, y, 1, board->spaces[x][y]->isKing);
			b = checkLegal(board, currentPlayer, x, y, 2, board->spaces[x][y]->isKing);
			c = checkLegal(board, currentPlayer, x, y, 3, board->spaces[x][y]->isKing);
			d = checkLegal(board, currentPlayer, x, y, 4, board->spaces[x][y]->isKing);
		}
	}
	printf("Movable locations: (x : y)\n");

	if(a == 2)
		printf("%d : %d\n", x - 2, y - 2);
	if(a == 1)
		printf("%d : %d\n", x - 1, y - 1);
	if(b == 2)
		printf("%d : %d\n", x + 2, y - 2);
	if(b == 1)
		printf("%d : %d\n", x + 1, y - 1);
	if(c == 2)
		printf("%d : %d\n", x - 2, y + 2);
	if(c == 1)
		printf("%d : %d\n", x - 1, y + 1);
	if(d == 2)
		printf("%d : %d\n", x + 2, y + 2);
	if(d == 1)
		printf("%d : %d\n", x + 1, y + 1);

	printf("Where would you like to move?\nx: %d\n", j);
		while(kDown != KEY_A){
			hidScanInput();
			gspWaitForVBlank();
		
			kDown = hidKeysDown();
			if(kDown & KEY_DOWN){
				j--;
				consoleClear();
				displayBoard(board, top, bottom);
				printf("\nMove to where? X: %d\n", j);
			}
			if(kDown & KEY_UP){
				j++;
				consoleClear();
				displayBoard(board, top, bottom);
				printf("\nMove to where? X: %d\n", j);
			}
			if(kDown & KEY_A){
				break;
			}
			if(kDown & KEY_START){
			p1->numPieces = 0;
			p2->numPieces = 0;
			return 0;
			}
		}
		gspWaitForVBlank();
		
		kDown = NULL;
		
		printf("\nY coordinate?: %d\n", k);
		while(kDown != KEY_A){
			hidScanInput();
			gspWaitForVBlank();
		
			kDown = hidKeysDown();
			if(kDown & KEY_DOWN){
				k--;
				consoleClear();
				displayBoard(board, top, bottom);
				printf("\nMove to Where? Y: %d\n", k);
			}
			if(kDown & KEY_UP){
				k++;
				consoleClear();
				displayBoard(board, top, bottom);
				printf("\nMove to Where? Y: %d\n", k);
			}
			if(kDown & KEY_START){
			p1->numPieces = 0;
			p2->numPieces = 0;
			return 0;
			}
		}
		gspWaitForVBlank();
		kDown = NULL;

	temp1 = x - j;
	temp2 = y - k;

	if((temp1 = x - j) > 0 && (temp2 = y - k) > 0)
		dir = 1;
	else if(temp1 < 0 && temp2 > 0)
		dir = 2;
	else if(temp1 > 0 && temp2 < 0)
		dir = 3;
	else if(temp1 < 0 && temp2 < 0)
		dir = 4;

	isJump = checkLegal(board, currentPlayer, x, y, dir, board->spaces[x][y]->isKing);
	if(checkLegal(board, currentPlayer, x, y, dir, board->spaces[x][y]->isKing))
	{
		is_king=board->spaces[x][y]->isKing;
		/*if(currentPlayer->player == p1->player && dir > 2)
		{
			is_king=1;
		}
		if(currentPlayer->player == p2->player && dir < 3)
		{
			is_king=1;
		}*/

		move_(board, currentPlayer, waitingPlayer, p1, p2, x, y, j, k, dir, is_king, top, bottom);
	}

	refresh(board, currentPlayer, waitingPlayer, top, bottom);
	gspWaitForVBlank();
	if(isJump==2)
	{
		//a capture was made; check if more are available
		if(currentPlayer == p2)
		{
			c = checkLegal(board, currentPlayer, j, k, 3, board->spaces[j][k]->isKing);
			d = checkLegal(board, currentPlayer, j, k, 4, board->spaces[j][k]->isKing);
			if(board->spaces[x][y]->isKing)
			{
				a = checkLegal(board, currentPlayer, j, k, 1, board->spaces[j][k]->isKing);
				b = checkLegal(board, currentPlayer, j, k, 2, board->spaces[j][k]->isKing);
			}
		}
		else
		{
			a = checkLegal(board, currentPlayer, j, k, 1, board->spaces[j][k]->isKing);
			b = checkLegal(board, currentPlayer, j, k, 2, board->spaces[j][k]->isKing);
			c = checkLegal(board, currentPlayer, j, k, 3, board->spaces[j][k]->isKing);
			d = checkLegal(board, currentPlayer, j, k, 4, board->spaces[j][k]->isKing);
		}
		if(a==2||b==2||c==2||d==2)
		{
			refresh(board, currentPlayer, waitingPlayer, top, bottom);
			return 1; //more captures are available
		}
		else
		{
			refresh(board, currentPlayer, waitingPlayer, top, bottom);
			return 0; //no captures available; end turn
		}
	}
	else
	{
		refresh(board, currentPlayer, waitingPlayer, top, bottom);
		return 0; //no captures were made; end turn
	}
}
