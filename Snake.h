/*
 * Snake.h
 *
 *  Created on: Feb 18, 2022
 *      Author: tomek93
 */

#ifndef SNAKE_H_
#define SNAKE_H_

#include <list>
#include <ncurses.h>

#include "board.h"


class Snake
		: public board
{

	enum direction {down=258, up=259, left=260, right=261};
	std::list<segment> SnakeBody;

public:
	Snake();
	virtual ~Snake();

	segment SnakeMove(int actdirection);
	void SnakePrint()
	{
		clear();
		for(const segment & ActSegment : SnakeBody)
		{
			move(ActSegment.y, ActSegment.x);
			printw("S");
		}
	}

};

#endif /* SNAKE_H_ */
