#include <algorithm>
bool canPartition(int iterationStart,vector<int>& nums,vector<bool> &used,int k,int inProgressBucketSum,int targetBucketSum){
        if(k==1){
            return true;
        }
        if (inProgressBucketSum > targetBucketSum)
            return false;
        if(inProgressBucketSum==targetBucketSum){
            return canPartition(0,nums,used,k-1,0,targetBucketSum);
        }
        for(int i=iterationStart;i<nums.size();i++){
            if(!used[i]){
                used[i]=true;
                if(canPartition(i+1,nums,used,k,inProgressBucketSum+nums[i],targetBucketSum)){
                    return true;
                }
                used[i]=false;
            }
        }
        return false;
}
bool splitArray(vector<int> &arr, int K) {

        int sum=0;
        
        for(int i=0;i<arr.size();i++){
            sum=sum+arr[i];
        }
        vector<bool> used(arr.size(),false);
        if(K==0||sum%K!=0){
            return false;
        }
        return canPartition(0,arr,used,K,0,sum/K);
}
