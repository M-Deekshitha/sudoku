/* This code solves any Sudoku problem using backtracking algorithm and Hashing. If the numbers in the given board doesn't form a valid sudoku then the program doesn't return anything. If there are more than 1 possible sudoku solutions for a given configuration, it returns all of them. */


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void helper(int r,int c,vector<vector<char>> &board, vector <map<int,int>> row,vector <map<int,int>> col,map<pair<int,int>,map<int,int>> &grid){

 /*when r becomes 9 , it implies that I have filled all of my boxes with valid numbers. So I will just print my values in the board */
    if(r==9){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout <<board[i][j]<<" ";
            }
            cout <<"\n";
            }
        cout << "\n";
        return;
    }
  /* if c becomes 9 it implies that I have traversed my entire row. So call the function for new row*/
        
    if(c==9){
        helper(r+1,0,board,row,col,grid);
        return;
    }

/*If my box is already filled, I will just go to the next box*/
        
    if(board[r][c]!='.'){
         helper(r,c+1,board,row,col,grid);
         return;
    }

  /*For an empty box, I'll check what numbers from 1 to 9 can be placed. If I get a number which can be placed, then I will call for the next box. If it gives a valid solution, the answer will be printed. Otherwise with the help of bracktracking , I will search for another valid number which can be placed. */
  
    for(int i=1;i<=9;i++){
        if(!row[r][i] && !col[c][i] && !grid[{r/3,c/3}][i]){
            row[r][i]=1;
            col[c][i]=1;
            grid[{r/3,c/3}][i]=1;
            board[r][c]=(i+'0');
            helper(r,c+1,board,row,col,grid);
            //Backtracking
            row[r][i]=0;
            col[c][i]=0;
            grid[{r/3,c/3}][i]=0;
            board[r][c]='.';
            }
    }
}
    
void solveSudoku(vector<vector<char>>& board) {
  
  /*row,col and grid are used to store numbers which are already present in a particular row, column and grid */
        
    vector <map<int,int>> row(9);
    vector <map<int,int>> col(9);
    map<pair <int,int>,map <int,int>>grid;
        
/*Marking the numbers which are given initially as PRESENT in their particular row, column and grid. */
  
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    row[i][board[i][j]-'0']=1;
                    col[j][board[i][j]-'0']=1;
                    grid[{i/3,j/3}][board[i][j]-'0']=1;
                }
            }
            
        }
        
        helper(0,0,board,row,col,grid);
    }

int main(){

    vector<vector<char>> board(9,vector<char>(9));
    cout << "Enter the elements one by one by moving forward first in the same row and then in the column : " << endl;
  
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin >>board[i][j];
        }
    }

    solveSudoku(board);
    
  
   return 0;
}