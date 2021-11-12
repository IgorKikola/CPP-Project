#ifndef SUDOKU_H
#define SUDOKU_H

#include <cmath>
#include <set>
#include <vector>
#include "Searchable.h"
using namespace std;
// TODO: Your Sudoku class goes here:

class Sudoku: public Searchable{
	int size;
	vector< vector< set<int> > > board;

public:
	Sudoku(int sizeIn)
	: size (sizeIn) {
		board.resize(size);
		for (int i = 0; i < size; ++i) {
        	board[i] = vector< set<int> >(size);
    	}
    	set<int> setValues;
      for (int i = 1; i < size+1; ++i) {
    		setValues.insert(i);
    	}
    	for (int row = 0; row < size; ++row) {
        	for (int col = 0; col < size; ++col) {
            	board[row][col] = setValues;
        	}
    	}
	}

  virtual bool isSolution(){
  		int counter = 0;
  		for (int i = 0; i < size; ++i) {
  			for (int j = 0; j < size; ++j) {
  				if (board[i][j].size() == 1) {
  					++counter;
  				}
  			}
  		}
      if(counter == size*size) {
        return true;
      }
  		else {
        return false;
      }
  	}

  	void clearRow(int rowIn, int colIn, int value) {
  		for (int col = 0; col < size; ++col) {
  			if (col != colIn) {
  				board[rowIn][col].erase(value);
  			}
  		}
  	}

    void clearCol(int rowIn, int colIn, int value) {
    		for (int row = 0; row < size; ++row) {
    			if (row != rowIn) {
    				board[row][colIn].erase(value);
    			}
    		}
    	}

    void clearBox(int rowIn, int colIn, int value) {
      int y = sqrt(size) * floor(rowIn/sqrt(size));
    	int x = sqrt(size) * floor(colIn/sqrt(size));

		  for (int i = y; i < y + sqrt(size); ++i) {
			     for (int j = x; j < x + sqrt(size); ++j) {
				         if (i == rowIn && j == colIn) { continue; }
				         else { board[i][j].erase(value); }
			     }
    	}
    }

  int getSquare(int row, int col) {
		if (board[row][col].size() == 1) {
			return *board[row][col].begin();
		}
		return -1;
	}
  bool setSquare(int row, int col, int value) {
    board[row][col] = {value};
    int prev = 0;
    int current = 0;
    		while (true) {
    			for (int x = 0; x < size; ++x) {
    				for (int y = 0; y < size; ++y) {
              if (board[x][y].size() == 1) {
                ++current;
    						clearRow(x, y, *board[x][y].begin());
    						clearCol(x, y, *board[x][y].begin());
    						clearBox(x, y, *board[x][y].begin());
    					}
              			if (board[x][y].size() == 0) {
                      return false;
                    }
    				}
    			}

    			if (prev == current) { break; }
          		prev = current;
          		current = 0;
    		}

    		return true;
    	}

      virtual bool isSolution() const override {
    		int count = 0;
    		for (size_t i = 0; i < size; ++i) {
    			for (size_t j = 0; j < size; ++j) {

    				if (board[i][j].size() == 1) {
    					++count;
    				}
    			}
    		}
    		return count == (size*size);
    	}
    	virtual void write(ostream & o) const override {
    		for (int i = 0; i < size; ++i) {
    			for (int j = 0; j < size; ++j) {

    				for (const int & value : board[i][j]) {
    					o << value << " ";
    				}
    				o << endl;
    			}
    			o << endl;
    		}
    	}

    	virtual int heuristicValue() const override {
      int counter = 0;
      		for (int i = 0; i < size; ++i) {
      			for (int j = 0; j < size; ++j) {
      				if (board[i][j].size() > 1) {
      					++counter;
      				}
      			}
      		}
      		return (size*size)-counter;
      	}

      virtual vector<unique_ptr<Searchable>> successors() const override {
      		vector<unique_ptr<Searchable>> successors;
      		for (int i = 0; i < size; ++i) {
      			for (int j = 0; j < size; ++j) {
      				if (board[i][j].size() > 1) {
      					for (auto & value : board[i][j]) {
      						Sudoku * boardCopy = new Sudoku(*this);
      						bool success = boardCopy->setSquare(i, j, value);
      						if (success = true) {
      							successors.push_back(unique_ptr<Searchable>(boardCopy));
      						} else {
      							delete boardCopy;
      						}
      					}
      					return successors;
      				}
      			}
      		}
      	  return successors;
      	}
  	};



#endif
