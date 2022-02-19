/*
 * plansza.h
 *
 *  Created on: Feb 19, 2022
 *      Author: tomek93
 */

#include <ncurses.h>
#include <map>
#include <stdlib.h>

#ifndef PLANSZA_H_
#define PLANSZA_H_


struct segment
{
	int x;
	int y;


	 segment(int xinit, int yinit) : x(xinit), y(yinit) {}
	 void print()
	 {
		printw(" %d  %d \n" ,x , y);
	 }
	 std::string KeyReturn()
	 {
		 return (std::to_string(x) + ":" +std::to_string(y));
	 }

};



class board {

std::map<std::string, int> MapBoard;



enum SegmentStatus { Free=0, Snake=1 , Point=2 };
public:


	board();
	virtual ~board();
	void addsegment(segment NewSegment, SegmentStatus Status)
	{
		MapBoard.insert(std::pair<std::string, int>(NewSegment.KeyReturn(), Status));
	}

	int SegmentStatic(segment CheckSegment)
	{
		return MapBoard[CheckSegment.KeyReturn()];
	}

	void AddRandomSegment()
	{
		int x=20;
		int y=20;
		int xpos, ypos;
		getmaxyx(stdscr,y,x);
		xpos=random() % x+1;
		ypos=random() % y+1;
		segment seg(xpos, ypos);
		addsegment(seg, Point);
		move(ypos, xpos);
		printw("P");
	}

	void RemoveSegment(segment SegToRemove)
	{
		std::map<std::string,int>::iterator it;
		it=MapBoard.find(SegToRemove.KeyReturn());
		MapBoard.erase (it);                   // erasing by iterator

	}


};

#endif /* PLANSZA_H_ */
