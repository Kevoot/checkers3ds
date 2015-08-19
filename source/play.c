#include <stdio.h>
#include <stdlib.h>
#include "checkers.h"
#include <sys/stat.h>
#include <string.h>
#include <3ds.h>


int main(void){
    BoardPtr board;
	NodePtr tempNode;
	int x, y, ext;
    LinkedListPtr p1, p2;
	
	//gfxInitDefault();        // graphics
	//gfxSet3D(false);  // stereoscopy (true == on / false == off)
	u32 kDown;        // keys down
	u32 kHeld;        // keys pressed
	u32 kUp;          // keys up
	u8* fbTopLeft;    // top left screen's framebuffer
	u8* fbTopRight;   // top right screen's framebuffer
	u8* fbBottom;     // bottom screen's framebuffer
	
	gfxInitDefault();
	
	PrintConsole topScreen, bottomScreen;
	
	consoleInit(GFX_TOP, &topScreen);
	consoleInit(GFX_BOTTOM, &bottomScreen);
	
	consoleClear();
	gspWaitForVBlank();
    
    p1 = (LinkedListPtr)malloc(sizeof(LinkedList));
    p2 = (LinkedListPtr)malloc(sizeof(LinkedList));    
    
    board = initBoard(p1, p2);
	system("cls");
	updateBoard(board, p1, p2);
	displayBoard(board, &topScreen, &bottomScreen);

	//p1 and p2 temporarily switched
	while(aptMainLoop()){
		
		do{
			do{
				ext=takeTurn(board, "Player 1", p1, p2, p1, p2, &topScreen, &bottomScreen);
				refresh(board, p1, p2, &topScreen, &bottomScreen);
			}while(ext);
			if(p1->numPieces < 1 || p2->numPieces < 1)
				break;
			do{
				ext=takeTurn(board, "Player 2", p2, p1, p1, p2, &topScreen, &bottomScreen);
				refresh(board, p1, p2, &topScreen, &bottomScreen);
			}while(ext);
		}while(p1->numPieces > 0 && p2->numPieces > 0);

		if(p1->numPieces < 1 && p1->numPieces != 0)
		{
			consoleClear();
			printf("Player 2 wins!\n");
			gspWaitForVBlank();
		}
		if(p2->numPieces < 1 && p1->numPieces != 0){
			consoleClear();
			printf("Player 1 wins!\n");
			gspWaitForVBlank();
		}
		if(p1->numPieces == 0 && p2->numPieces == 0){
			consoleClear();
			gspWaitForVBlank();
			return 0;
			
		}
		
		gfxFlushBuffers();
		gfxSwapBuffers();
		//Wait for VBlank
		gspWaitForVBlank();
		
	}

	// Exit services
	gfxExit();
	return 0;
}
