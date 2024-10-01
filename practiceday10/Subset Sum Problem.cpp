#include<bits/stdc++.h>
using namespace std;

class Solution{   
public:
    
    bool subset_sum(int n,vector<int> &a,int s,vector<vector<int>>&dp)
    {
        if(n==0)
        {
            if(s==0)
            {
                return true;
            }
            else 
            {
                return false;
            }
        }
        if(dp[n][s]!= -1)
        {
            return dp[n][s];
        }
        if(a[n-1]<=s)
        {
            bool op1=subset_sum(n-1,a,s-a[n-1],dp);
            bool op2=subset_sum(n-1,a,s,dp);
            return dp[n][s]=op1||op2;
        }
        else 
        {
            return dp[n][s]=subset_sum(n-1,a,s,dp);
        }
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
    
       
        return subset_sum(n,arr,sum,dp);
    }
};