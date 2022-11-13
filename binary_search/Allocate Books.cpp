#include <bits/stdc++.h> 
bool isPossible(vector<int> arr, int n, int m,int barrier){
    int studentcount=1;
    int pages=0;
    
    for(int i=0;i<n;i++){
        if(arr[i]>barrier){
            return false;
        }
        if(pages+arr[i]<=barrier){
            pages+=arr[i];
        }
        else{
            studentcount++;
            if(studentcount>m){
                return false;
            }
            pages=0;
            pages+=arr[i];
        }
    }
    return true;
}
int allocateBooks(vector<int> arr, int n, int m) {
    // Write your code here.
    int s=0;
    int sum=0;
    for(auto it:arr){
        sum+=it;
    }
    
    int e=sum;
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        if(isPossible(arr,n,m,mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
