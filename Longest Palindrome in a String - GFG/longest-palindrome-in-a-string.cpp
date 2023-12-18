//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  
    string longestPalin (string S) {
        int n = S.length();
        int ans =1;
        int st,e;
        string ansString=S.substr(0,1);

        for(int i=0;i<n;i++) {
            st=i-1;
            e=i;
            while(st>=0 && e<n && S[st]==S[e]) {
                if(e-st+1>ans) {
                    ansString.clear();
                    ans = e-st+1;
                    ansString = S.substr(st,e-st+1);
                }
                st--;
                e++;
            }

            st=i-1;
            e=i+1;
            while(st>=0 && e<n && S[st]==S[e]) {
                if(e-st+1>ans) {
                    ansString.clear();
                    ans = e-st+1;
                    ansString = S.substr(st,e-st+1);
                }
                st--;
                e++;
            }
        }

        return ansString;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends