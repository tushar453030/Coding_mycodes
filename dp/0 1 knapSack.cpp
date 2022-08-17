    int dp[1002][1002];
    int knapSackk(int W, int wt[], int val[], int n){
       if(n==0 || W==0){
           return 0;
       }
       if(dp[n][W]!=-1){
           return dp[n][W];
       }
       if(wt[n-1]<=W){
           return dp[n][W]=max(val[n-1]+knapSackk(W-wt[n-1],wt,val,n-1),knapSackk(W,wt,val,n-1));
       }
       else if(wt[n-1]>W){
           return dp[n][W]=knapSackk(W,wt,val,n-1);
       }
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       memset(dp,-1,sizeof(dp));
       return knapSackk(W,wt,val,n);
    }
