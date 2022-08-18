    int fin(int prices[],int n,vector<int> &pis){
        int dp[n+1][n+1];
        for(int j=0;j<=n;j++){
            dp[0][j]=0;
        }
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(pis[i-1]<=j){
                    dp[i][j]=max(prices[i-1]+dp[i][j-pis[i-1]],dp[i-1][j]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][n];
    }
    int cutRod(int price[], int n) {
        //code here
        vector<int> pis;
        for(int i=1;i<=n;i++){
            pis.push_back(i);
        }
        
        return fin(price,n,pis);
    }
