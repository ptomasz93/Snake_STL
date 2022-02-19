/*
 * Snake_STL.cpp
 *
 *  Created on: Feb 18, 2022
 *      Author: tomek93
 */

#include <iostream>
#include <ncurses.h>


#include "Snake.h"
#include "board.h"

using namespace std;

int main()
{
	enum key {key_down=258, key_up=259, key_left=260, key_right=261};;

	initscr();
    keypad(stdscr, TRUE);
    printw("Hi!\n");



Snake Snake1;
board board1;

auto key=getch();



while(TRUE)
{
	key=getch();
	Snake1.SnakeMove(key);
	Snake1.SnakePrint();
	board1.AddRandomSegment();
}

    endwin();

    exit(0);
}

