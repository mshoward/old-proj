#include <iostream>
#include <string>
#include "SudokuClass.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stoi;


int main()
{
	string row, number;
	int board[9][9];
	size_t intSize = sizeof(int);
	cout << "Input each row with 0's as placeholders:" << endl;
	for (int i = 0; i < 9; i++)
	{
		cout << "row: " << i+1 << endl;
		cin >> row;
		for (int j = 0; j < 9; j++)
		{
			number = row.substr(j,1);
			//cout << "row: " << i+1 << endl;
			board[i][j] = stoi(number, &intSize, 10);
		}
	}
	
	//make the board
	SudokuPuzzle puzzle (board);
	puzzle.PrintPuzzle();
	try
	{
		puzzle.solve();
	}
	catch (int e)
	{
		cout << "error: " << e << endl;
		return 1;
	}
	
	return 0;
}
