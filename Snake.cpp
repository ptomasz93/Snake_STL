/*
 * Snake.cpp
 *
 *  Created on: Feb 18, 2022
 *      Author: tomek93
 */

#include "Snake.h"

Snake::Snake() {

	segment NewSegment(3,5);
	SnakeBody.push_back(NewSegment);
}

Snake::~Snake() {
	// TODO Auto-generated destructor stub
}

segment Snake::SnakeMove(int actdirection){

	auto SnakeHead=SnakeBody.back();
	if(actdirection==up)
		SnakeHead.y--;
	if(actdirection==down)
		SnakeHead.y++;
	if(actdirection==left)
		SnakeHead.x--;
	if(actdirection==right)
		SnakeHead.x++;

	SnakeBody.push_back(SnakeHead);
	SnakeBody.pop_front();

	return SnakeHead;
}


