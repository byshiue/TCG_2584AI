#include "Tuple_LargeTileCount.h"


Tuple_LargeTileCount::Tuple_LargeTileCount(void)
{
	normalization_factor = 1;
	iTableSize = pow(4, iRange);
	Constructor();
}


Tuple_LargeTileCount::~Tuple_LargeTileCount(void)
{
	Desturctor();
}

float Tuple_LargeTileCount::getWeight(int board[4][4])
{
	int position = getPosition(board);
	return getWeightFromTable(position, board);
}

void Tuple_LargeTileCount::setWeight(int board[4][4], const float weight)
{
	int position = getPosition(board);
	setWeightToTable(position, weight, board);
}

int Tuple_LargeTileCount::getPosition(int board[4][4])
{
	return 0;
	int tile_count[iRange] = {};
	for (int i = 0 ; i < 4; i++){
		for (int j = 0 ; j< 4 ;j ++){
			if(board[i][j] >= iLowerBound){
				tile_count[board[i][j] - iLowerBound]++;
			}
		}
	}
	int position = 0;
	for(int i = 0 ; i< iRange; i++){
		position += pow(12, i) * std::min(tile_count[i],4) ;
	}
	return position;
}

void Tuple_LargeTileCount::Update(int board[4][4], const float error)
{
	int position = getPosition(board);
	UpdateTable(position, error, board);
}

int Tuple_LargeTileCount::pow(int x, int y)
{
	int value = 1;
	for (int i = 0; i< y ; i++)
		value *= x;
	return value;
}

