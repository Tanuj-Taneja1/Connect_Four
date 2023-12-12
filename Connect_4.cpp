#include <bits/stdc++.h>
using namespace std;

class Grid{
private:
    int rowCount;
    int columnCount;
    int connectN;
    vector<vector<string>> grid;

public:
    Grid(int rowCount,int columnCount,int connectN=4){
        this->rowCount=rowCount;
        this->columnCount=columnCount;
        this->connectN=connectN;
        this->grid=vector<vector<string>>(rowCount,vector<string>(columnCount,"EMPTY"));
    }

    int addPiece(int column,string piece){
        int lowestRow=this->rowCount-1;
        for (int row=lowestRow;row>=0;row--){
            if (this->grid[row][column]=="EMPTY"){
                this->grid[row][column]=piece;
                return row;
            }
        }
        return -1;
    }
    bool winCheck(int curRow,int curCol,string piece){
        int count=0;
        int leftCol=max(0, curCol-connectN+1);
        int rightCol=max(this->columnCount, curCol+connectN-1);
        int leftRow=max(0, curRow-connectN+1);
        int rightRow=(this->rowCount, curRow+connectN-1);
        int pieceCount=0;

        for (int col=leftCol;col<=rightCol;col++){
            string curPiece=this->grid[curRow][col];
            if (curPiece==piece){
                pieceCount++;
            } 
            else {
                pieceCount=0;
            }
            if (pieceCount==connectN){
                return true;
            }
        }

        for (int row=leftRow;row<=rightRow;row++){
            string curPiece=this->grid[row][curCol];
            if (curPiece==piece){
                pieceCount++;
            } 
            else {
                pieceCount=0;
            }
            if (pieceCount==connectN){
                return true;
            }
        }

        for (int row=leftRow;row<=rightRow;row++){
            int col=curCol-(curRow-row);
            string curPiece=this->grid[row][col];
            if (curPiece==piece){
                pieceCount++;
            } 
            else {
                pieceCount=0;
            }
            if (pieceCount==connectN){
                return true;
            }
        }
        for (int row=leftRow;row<=rightRow;row++){
            int col=curCol+(curRow-row);
            string curPiece=this->grid[row][col];
            if (curPiece==piece){
                pieceCount++;
            } 
            else {
                pieceCount=0;
            }
            if (pieceCount==connectN){
                return true;
            }
        }
        return false;        
    }  
};

class Player {
private:
    string name;
    string piece;

public:
    Player(string name, string piece) {
        this->name = name;
        this->piece = piece;
    }
    string getName() {
        return this->name;
    }
    string getPieceColor() {
        return this->piece;
    }
};
