//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int solve(int coins[], int N, int sum, int i, vector<vector<long long int>>& dp) {
        if (sum == 0) {
            return 1;
        }
        
        if (sum < 0 || i >= N) {
            return 0;
        }
        
        if (dp[sum][i] != -1) {
            return dp[sum][i];
        }
        
        long long int include = solve(coins, N, sum - coins[i], i, dp);
        long long int exclude = solve(coins, N, sum, i + 1, dp);
        
        dp[sum][i] = include + exclude;
        return dp[sum][i];
    }
  
    long long int count(int coins[], int N, int sum) {
        vector<vector<long long int>> dp(sum + 1, vector<long long int>(N, -1));
        return solve(coins, N, sum, 0, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends