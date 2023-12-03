#include <bits/stdc++.h>
using namespace std;

class Grid{
private:
    int rows;
    int columns;
    vector<vector<string>> grid;

public:
    Grid(int rows,int columns){
        this->rows=rows;
        this->columns=columns;
        this->grid=vector<vector<string>>(rows,vector<string>(columns,"EMPTY"));
    }

    int placePiece(int column,string piece){
        int lowest_row=this->rows-1;
        for (int row=lowest_row;row>=0;row--){
            if (this->grid[row][column]=="EMPTY"){
                this->grid[row][column]=piece;
                return row;
            }
        }
        return -1;
    }
    
};