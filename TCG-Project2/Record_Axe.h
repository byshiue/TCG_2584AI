#ifndef RECORD_AXE_H
#define RECORD_AXE_H
#pragma once
#include "assert.h"
#include "stdio.h"
/*
Class that save the data of strategy, only deal with four tiles one time

*/


class Record_Axe
{
public:
	/*
	The constructor need the index of tiles
	Since this record use four tile, it needs 4 integers to input
	*/
	Record_Axe();
	~Record_Axe();
	void setScore(int tablenumber, int inputindex[6], float score);
	/*
	get the data at one position
	*/
	float getScore(int tablenumber, int inputindex[6]);
	/*
	get the corresponding data if giving a board
	*/
	float getScore(int board[4][4]);
	float get_OneFeature_Score(int tablenumber, int board[4][4], int no);
	void set_OneFeature_Score(int tablenumber, int board[4][4], int no, float value);
private:
	float *Data1;
	float *Data2;
	float *Data3;
	int index[3][8][6];
	int iUpperBound;
};

#endif