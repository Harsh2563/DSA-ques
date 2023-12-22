//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
  
  
	int distinctSubsequences(string s)
	{
	   
	     int mod = 1e9 + 7;
	     int n = s.length();
	     unordered_map<char,int> map;
	     vector<int> dp(n+1);
	     dp[0] = 1;
	     
	    for(int i = 1;i<n+1;i++) {
	        dp[i] = 2*dp[i-1] % mod;
	        
	        if(map.find(s[i-1]) != map.end()) {
	             dp[i] = (dp[i] - dp[map[s[i - 1]] - 1] + mod) % mod;
	        }
	        
	        map[s[i-1]] = i;
	    }
	    return (dp[n]+mod)%mod;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends