class Solution {
private:
    int count=0;
public:
    bool issafe(int n,int row,int col,vector<vector<int>> &arr){
        for(int i=row-1;i>=0;i--){

            if(arr[i][col]==1){
                return false;
            }            

        }

        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){

            if(arr[i][j]==1){
                return false;
            }       

        }

        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){

            if(arr[i][j]==1){
                return false;
            }

        }

        return true;        
    }
    void nquee(vector<vector<int>> &arr,int row,int n){
        if(row==n){
            count++;
            return ;
        }
        for(int i=0;i<n;i++){
            if(issafe(n,row,i,arr)){
                arr[row][i]=1;
                nquee(arr,row+1,n);
                arr[row][i]=0;
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<int>> arr(n , vector<int> (n, 0));
        nquee(arr,0,n);
        return count;
    }
};
