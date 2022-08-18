    int findsubset(vector<int>&nums,int &sum){
        int n=nums.size();
        int dp[n+1][sum+1];
        for(int j=0;j<=sum;j++){
            dp[0][j]=0;
        }
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j-nums[i-1]] +dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum<abs(target) || (sum+target)%2!=0){
            return 0;
        }
        
        int finaltarget=(sum+target)/2;
        return findsubset(nums,finaltarget);
    }
