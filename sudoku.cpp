class Solution {
    void helper(int r,int c,vector<vector<char>> &board, vector <map<int,int>> row,vector <map<int,int>> col,map<pair<int,int>,map<int,int>> &grid){
        if(r==9){
             for(auto element:board){
                for(auto i:element){
                    cout <<i<<" ";
                }
                cout <<"\n";
            }
            cout << "\n";
            return;
        }
        
        if(c==9){
            helper(r+1,0,board,row,col,grid);
            return;
        }
        
        if(board[r][c]!='.'){
            helper(r,c+1,board,row,col,grid);
            return;
        }
        for(int i=1;i<=9;i++){
            if(!row[r][i] && !col[c][i] && !grid[{r/3,c/3}][i])             {
                row[r][i]=1;
                col[c][i]=1;
                grid[{r/3,c/3}][i]=1;
                board[r][c]=(i+'0');
                helper(r,c+1,board,row,col,grid);
                row[r][i]=0;
                col[c][i]=0;
                grid[{r/3,c/3}][i]=0;
                board[r][c]='.';
            }
        }
    }
public:
    
    void solveSudoku(vector<vector<char>>& board) {
        
        vector <map<int,int>> row(9);
        vector <map<int,int>> col(9);
        map<pair <int,int>,map <int,int>>grid;
        
    
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
};