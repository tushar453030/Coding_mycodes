    bool issafe(vector<vector<char>>& board,int row,int col,int num,char temp){
        for(int d=0;d<board.size();d++){
            if(board[row][d]==temp){
                return false;
            }
        }
        
        for(int r=0;r<board.size();r++){
            if(board[r][col]==temp){
                return false;
            }
        }
        
        int sqr=sqrt(board.size());
        int boxrow=row-row%sqr;
        int boxcol=col-col%sqr;
        
        for(int r=boxrow;r<boxrow+sqr;r++){
            for(int d=boxcol;d<boxcol+sqr;d++){
                if(board[r][d]==temp){
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board,int n){
        int row=-1;
        int col=-1;
        bool isEmpty=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='.'){
                    row=i;
                    col=j;
                    isEmpty=false;
                    break;
                }
            }
            if(!isEmpty){
                break;
            }
        }
        if(isEmpty){
            return true;
        }
        for(int num=1;num<=n;num++){
            char temp='0'+num;
            if(issafe(board,row,col,num,temp)){
                // cout<<row<<" "<<col;
                
                board[row][col]=temp;
                if(solve(board,n)){
                    return true;
                }
                else{
                    board[row][col]='.';
                }
            }
        }
        return false;
    }
    void print(vector<vector<char>>& board,int N){
        for (int i = 0; i < N; i++, cout << '\n')
                for (int j = 0; j < N; j++)
                    cout << board[i][j] << ' ';
    }
        
    
    void solveSudoku(vector<vector<char>>& board) {
        int n=board.size();
        if(solve(board,n)){
            print(board,n);
        }
    }
