//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:

bool solve(unordered_set<string> w, vector<int> &dp, int i, string s) {
        if(i == s.length()) {
            return true;
        }

        if(dp[i]!=-1) {
            return dp[i];
        }
        
        for(int j = i+1;j<=s.length();j++) {
            string temp = s.substr(i,j-i);
            if(w.count(temp) && solve(w,dp,j,s)) {
                dp[i]=true;
                return true;
            }
        }
                    
            dp[i]=false;
            return false;
}
        

    int wordBreak(string s, vector<string> &B) {
        unordered_set<string> w(B.begin(),B.end());
        vector<int> dp(s.length(),-1);
        return solve(w,dp,0,s);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends