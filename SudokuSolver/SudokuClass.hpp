#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Scell
{
	public:
		int value;
		int posX;
		int posY;
		bool given;
		Scell()
		{
			value = 0;
			posX = 0;
			posY = 0;
			given = false;
		}
		Scell(int n, int i, int j)
		{
			value = n;
			posY = i;
			posX = j;
			if (n != 0)
			{
				given = true;
			}
			
		}
		~Scell(){}
		void increment()
		{
			if (!given)
			{
				value = (value + 1) % 10;
			}
			else
			{
				//@ incrementing a given cell
				throw 3;
			}
		}
};

class Srow
{
	public:
		Scell * row[9];
		int rowNumber;
		bool hasConflict;
		bool hasZeroes;
		Srow()
		{
			for (int i = 0; i < 9; i++)
			{
				row[i] = 0;
			}
			rowNumber = 0;
			hasConflict = false;
			hasZeroes = false;
		}
		void init(Scell ** puzzle, int n)
		{
			rowNumber = n;
			for (int i = 0; i < 9; i++)
			{
				row[i] = &puzzle[n][i];
			}
			hasConflict = false;
			hasZeroes = false;
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					if (((*row[i]).value == (*row[j]).value) && (i != j) && ((*row[j]).value != 0))
					{
						hasConflict = true;
					}
					if ( (!hasZeroes) && ( (*row[j]).value == 0) )
					{
						hasZeroes = true;
					}
				}
			}
		}
		~Srow(){}
		void updateStates()
		{
			bool temp = false;
			bool tempA = false;
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					if ( (!temp) && ((*row[j]).value == (*row[i]).value) && (i != j) && ((*row[j]).value != 0) )
					{
						temp = true;
					}
					if ( (!tempA) && ((*row[j]).value == 0) )
					{
						tempA = true;
					}
				}
			}
			hasConflict = temp;
			hasZeroes = tempA;
		}// end updateStates()
		bool isConflicted()
		{
			updateStates();
			return hasConflict;
		}//end isConflicted()
		bool isNotFull()
		{
			updateStates();
			return hasZeroes;
		}
		
		
};

class Scol
{
	public:
		Scell * col[9];
		int colNumber;
		bool hasConflict;
		bool hasZeroes;
		Scol()
		{
			for (int i = 0; i < 9; i++)
			{
				col[i] = 0;
			}
			colNumber = 0;
			hasConflict = false;
			hasZeroes = false;
		}
		//Constructor takes the 2D array of an assumed size 9
		//assigns the n'th column
		void init(Scell ** puzzle, int n)
		{
			colNumber = n;
			for (int i = 0; i < 9; i++)
			{
				col[i] = &puzzle[i][n];
			}
			hasConflict = false;
			hasZeroes = false;
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					if ( (!hasConflict) && ((*col[i]).value == (*col[j]).value) && (i != j) && ((*col[i]).value != 0))
					{
						hasConflict = true;
					}
					if ( (!hasZeroes) && ((*col[j]).value == 0) )
					{
						hasZeroes = true;
					}
					
				}
			}
		}//end constructor
		~Scol(){}
		void updateStates()
		{
			bool temp = false;
			bool tempA = false;
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					if ( (!temp) && ((*col[j]).value == (*col[i]).value) && (i != j) && ((*col[j]).value != 0) )
					{
						temp = true;
					}
					if ( (!tempA) && ((*col[j]).value == 0) )
					{
						tempA = true;
					}
				}
			}
			hasConflict = temp;
			hasZeroes = tempA;
		}// end updateStates()
		bool isConflicted()
		{
			updateStates();
			return hasConflict;
		}//end isConflicted()
		bool isNotFull()
		{
			updateStates();
			return hasZeroes;
		}
};

class Ssquare
{
	public:
		int cellNumber;
		Scell * square[9];
		bool hasConflict; //#figure out what to do about setting hasConflict in constructor
		bool hasZeroes;
		Ssquare()
		{
			cellNumber = 0;
			for (int i = 0; i < 9; i++)
			{
				square[i] = 0;
			}
			hasConflict = false;
			hasZeroes = false;
		}
		void init (Scell ** puzzle, int n)
		{
			cellNumber = n;
			int temp = 0;
			for (int i =  (n / 3) * 3; i < ((n/3) * 3) + 3; i++)
			{
				for (int j = (0 + 3 * (n % 3)); j < (3 + 3 * (n % 3)); j++)
				{
					square[temp] = &puzzle[i][j];
					temp++;
				}//end col loop
			}// end row loop
			hasConflict = false;
			hasZeroes = false;
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					if ((!hasConflict) && ((*square[i]).value == (*square[j]).value) && (i != j) && ((*square[i]).value != 0))
					{
						hasConflict = true;
					}
					if ( (!hasZeroes) && ((*square[j]).value == 0) )
					{
						hasZeroes = true;
					}
					
				}
			}
		}//end constructor
		~Ssquare(){}
		void updateStates()
		{
			bool temp = false;
			bool tempA = false;
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					if ( (!temp) && ((*square[j]).value == (*square[i]).value) && (i != j) && ((*square[j]).value != 0) )
					{
						temp = true;
					}
					if ( (!tempA) && ((*square[j]).value == 0) )
					{
						tempA = true;
					}
				}
			}
			hasConflict = temp;
			hasZeroes = tempA;
		}// end updateStates()
		bool isConflicted()
		{
			updateStates();
			return hasConflict;
		}//end isConflicted()
		bool isNotFull()
		{
			updateStates();
			return hasZeroes;
		}
		
};

class SudokuPuzzle
{
	public:
		Scell ** puzzle;
		Srow rows[9];
		Scol cols[9];
		Ssquare squares[9];
		int posX;
		int posY;
		bool hasConflict;
		bool hasZeroes;
		bool isSolved;

		SudokuPuzzle(int rawPuzzle[9][9])
		{
			posX = posY = 0;
			puzzle = new Scell* [9];
			for (int i = 0; i < 9; i++)
			{
				puzzle[i] = new Scell[9];
			}
			
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					puzzle[i][j].value = rawPuzzle[i][j];
					if (rawPuzzle[i][j])
					{
						puzzle[i][j].given = true;
					}
					puzzle[i][j].posX = j;
					puzzle[i][j].posY = i;
				}
			}// end Scell init
			//begin board abstraction.....
			hasConflict = false;
			hasZeroes = false;
			isSolved = false;
			for (int i = 0; i < 9; i++)
			{
				rows[i].init(puzzle, i);
				cols[i].init(puzzle, i);
				squares[i].init(puzzle, i);
				hasConflict = (hasConflict || rows[i].isConflicted());
				hasConflict = (hasConflict || squares[i].isConflicted());
				hasConflict = (hasConflict || cols[i].isConflicted());
				hasZeroes = (hasZeroes || rows[i].isNotFull());
				hasZeroes = (hasZeroes || squares[i].isNotFull());
				hasZeroes = (hasZeroes || cols[i].isNotFull());
			}
			
			
		}// end constructor
		~SudokuPuzzle()
		{
			for (int i = 0; i < 9; i++)
			{
				delete[] puzzle[i];
			}
			delete[] puzzle;
		}// end deconstructor
		void updateStates()
		{
			hasConflict = false;
			hasZeroes = false;
			for(int i = 0; i < 9; i++)
			{
				hasConflict = (hasConflict || rows[i].isConflicted());
				hasConflict = (hasConflict || squares[i].isConflicted());
				hasConflict = (hasConflict || cols[i].isConflicted());
				hasZeroes = (hasZeroes || rows[i].isNotFull());
				hasZeroes = (hasZeroes || squares[i].isNotFull());
				hasZeroes = (hasZeroes || cols[i].isNotFull());
			}
		}
		bool isNotFull()
		{
			updateStates();
			return hasZeroes;
		}
		bool isConflicted()
		{
			updateStates();
			return hasConflict;
		}
		//Solving methods
		bool cellIsGiven()
		{
			return puzzle[posY][posX].given;
		}//end cellIsGiven()
		int cellValue()
		{
			return puzzle[posY][posX].value;
		}
		
		void goForward(int n)
		{
			for (int i = 0; ((i < n) || (cellIsGiven())); i++)
			{
				posX = (posX + 1) % 9;
				if (posX == 0)
				{
					posY = posY + 1;
					if (posY > 8)
					{
						//@ indexing error
						throw 2;
					}
				}
			}//end loop of n times
		}//end goFoward(int n)
		
		void goBack(int n)
		{
			//cout <<"going back " << n << " times from" << posY << " , " << posX << endl;
			for (int i = 0; ((i < n) || (cellIsGiven())); i++)
			{
				posX = (posX - 1);
				if (posX < 0)
				{
					posX = 8;
					posY = posY - 1;
					if ( (posY < 0) )
					{
						//@ indexing error
						throw 1;
					}
					if ( (posX == 0) &&
						(posY == 0) &&
						(cellIsGiven()) )
					{
						goForward(1);
					}
				}
				
			}//end loop of n times
			//cout << "pos is -> " << posY << "," << posX << endl;
		}//end goBack(int n)
		void guess()
		{
			updateStates();
			if (!(hasConflict || hasZeroes))
			{
				isSolved = true;
			}
			if ( (!(cellIsGiven())) && (!(isSolved)) )
			{
				//cout << "incrementing cell (" << posY << "," << posX << ")" << "who's value is: " << cellValue() << endl;
				puzzle[posY][posX].increment();
				
			}
			updateStates();
			if (!(hasConflict || hasZeroes))
			{
				isSolved = true;
			}
			
		}//end guess()
		void PrintPuzzle()
		{
			for (int i = 0; i < 9; i++)
			{
				cout <<
				puzzle[i][0].value <<
				puzzle[i][1].value <<
				puzzle[i][2].value << " | " <<
				puzzle[i][3].value <<
				puzzle[i][4].value <<
				puzzle[i][5].value << " | " <<
				puzzle[i][6].value <<
				puzzle[i][7].value <<
				puzzle[i][8].value << endl;
				if (((i+1) % 3) == 0)
				{
					cout << endl;
				}
			}
		}
		//@Solving method
		void solve()
		{
			bool forward = false;
			bool back = false;
			int count = 0;
			updateStates();
			while ((hasZeroes) || (hasConflict))
			{
				forward = back = false;
				guess();
				count++;
				//decision tree
				
				if (!isSolved)
				{ 
					if (hasConflict)
					{
						forward = false;
						//cout << "incorrect value, trying again" << endl;
					}
					else
					{
						forward = true;
					}
					if (cellValue() == 0)
					{
						forward = false;
						back = true;
						//cout << "found incorrect value, going back" << endl;
					}
					if (forward)
					{
						goForward(1);
					}
					if (back)
					{
						goBack(1);
					}
				}
				//PrintPuzzle();
				if ((count % 100000) == 0)
					cout << count << " guesses so far" << endl;
			}
			PrintPuzzle();
		}// end solve()
};
