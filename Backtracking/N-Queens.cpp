class Solution{
public:
    void fillit(vector<vector<int>> &board,vector<vector<int>> &ans,int n){
        vector<int> temp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[j][i]==1){
                    temp.push_back(j+1);                   //according to question output we are doing this.
                }
            }
        }
        ans.push_back(temp);
    }
    bool isSafe(int row,int col,vector<vector<int>> board,int n){
        int x=row;
        int y=col;
        //checking for the same row
        while(y>=0){
            if(board[x][y]==1){
                return false;
            }
            y--;
        }
        
        x=row;
        y=col;
        //checking for left upper diagonal
        while(x>=0 && y>=0){
             if(board[x][y]==1){
                return false;
            }
            y--;
            x--;
        }
        x=row;
        y=col;
      
        //checking for the lower diagonal;
        while(x<n && y>=0){
             if(board[x][y]==1){
                return false;
            }
            y--;
            x++;
        }
        //We do not need to check for the lower right diagonal, upper righ diagonal ,right side row as we haven't visited them we are going col by col.
        return true;
    }

    void solve(int col,vector<vector<int>>& ans,vector<vector<int>>& board,int n){
        if(col==n){
            fillit(board,ans,n);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]=1;
                solve(col+1,ans,board,n);
                board[row][col]=0;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> board(n,vector<int>(n,0));
        vector<vector<int>> ans;
        solve(0,ans,board,n);
        return ans;
    }
};
