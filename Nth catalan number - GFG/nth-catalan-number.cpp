//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    
   
    int findCatalan(int n) 
    {
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        
        for(int i=2;i<=n;i++) {
            for(int j=0;j<i;j++) {
                dp[i] = (dp[i] + (1LL * dp[i - j - 1] * dp[j]) % 1000000007) % 1000000007;

            }
        }
        return dp[n] % 1000000007;

    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends