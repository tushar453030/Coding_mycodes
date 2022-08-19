class Solution {
public:
    string LCS(string str1,string str2,int n,int m){
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=m;j++){
            dp[0][j]=0;
        }
        
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        
        int a=n;
        int b=m;
        string ans="";
        
        while(a>0 && b>0){
            if(str1[a-1]==str2[b-1]){
                ans+=str1[a-1];
                a--;
                b--;
            }
            else{
                if(dp[a-1][b]>dp[a][b-1]){
                    ans+=str1[a-1];
                    a--;
                    
                }
                else{
                    ans+=str2[b-1];
                    b--;
                }
            }
        }
        while(b>0 && a==0){
            ans+=str2[b-1];
            b--;
        }
        while(a>0 && b==0){
            ans+=str1[a-1];
            a--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        
        string lcs=LCS(str1,str2,n,m);
   
        return lcs;
    }
};
