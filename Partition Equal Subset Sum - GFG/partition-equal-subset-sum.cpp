//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int arr[],int N,int i,int sum1,int total, vector<vector<int>> &dp) {
        if(i>N) {
            return 0;
        }
        
        if(sum1==total-sum1) {
            return 1;
        }
        
        if(dp[i][sum1]!=-1) {
            return dp[i][sum1];
        }
        
        int include = solve(arr,N,i+1,sum1+arr[i],total,dp);
        int exclude = solve(arr,N,i+1,sum1,total,dp);
        dp[i][sum1] = include || exclude;
        return dp[i][sum1];
    }

    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        
        for(int i =0;i<N;i++) {
            sum+=arr[i];
        }
        vector<vector<int>> dp(N+1,vector<int> (sum+1,-1));
        return solve(arr,N,0,0,sum,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends