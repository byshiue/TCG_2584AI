#include "Tuple_MergeCount.h"

Tuple_MergeCount::Tuple_MergeCount()
{
	iTableSize = 3;
	normalization_factor = std::sqrt(8.);
	Constructor();
}

void Tuple_MergeCount::SetParameter(const int input_index[4])
{
	for (int i = 0 ; i<4 ; i++){
		for(int j = 0; j<4; j++){
			if(i == 0){
				index[i][j] = input_index[j];
				index[i+4][j] = UpsideDown(index[i][j]);
			}
			else{
				index[i][j] = Rotate(index[i-1][j]);
				index[i+4][j] = Rotate(index[i+4-1][j]);
			}
		}
	}
}

Tuple_MergeCount::~Tuple_MergeCount()
{
	Desturctor();
}

float Tuple_MergeCount::getWeight(int board[4][4])
{
	float value = 0;
	for (int i = 0; i < 8; i++)
		value += getWeight(board, i);
	return  value;
}

float Tuple_MergeCount::getWeight(int board[4][4], int no)
{
	int position = MergeableNumber(board, no);
	return getWeightFromTable(position, board);
}

void Tuple_MergeCount::setWeight(int board[4][4], int no, float weight)
{
	int position = MergeableNumber(board, no);
	setWeightToTable(position, weight, board);
}

void Tuple_MergeCount::Update(int board[4][4], float error)
{
	for (int i = 0 ; i < 8 ; i++){
		int position = MergeableNumber(board, i);
		UpdateTable(position, error, board);
	}
}

int Tuple_MergeCount::MergeableNumber(const int board[4][4], const int no)
{
	if(isMergeable(board[index[no][1] / 4][ index[no][1] % 4], board[index[no][2] / 4][index[no][2] % 4]) == false ){
		if(isMergeable(board[index[no][0] / 4][ index[no][0] % 4], board[index[no][1] / 4][index[no][1] % 4]) == true ){
			if(isMergeable(board[index[no][2] / 4][ index[no][2] % 4], board[index[no][3] / 4][index[no][3] % 4]) == true )
				return 2;
			else
				return 1;
		}
		else return 0;
	}
	return 1;
}
bool Tuple_MergeCount::isMergeable(const int x, const int y)
{
	if(x - y == 1 || y - x == 1)
		return true;
	if( x == y && x == 1)
		return true;
	return false;
}

