#ifndef TUPLE_6TILE_H
#define TUPLE_6TILE_H
#pragma once
#include "Tuple.h"
/*
Class that save the data of strategy, only deal with four tiles one time

*/


class Tuple_6tile : public Tuple
{
public:
	Tuple_6tile();
	~Tuple_6tile();
	void SetParameter(int input_index[6]);
	/*
	get the corresponding data if giving a board
	*/
	virtual float getWeight(int board[4][4]);
	virtual float getWeight(int board[4][4], int no);
	virtual void setWeight(int board[4][4], int no, float value);
	virtual void Update(int board[4][4], const float error);
private:
	int index[8][6];
};

#endif