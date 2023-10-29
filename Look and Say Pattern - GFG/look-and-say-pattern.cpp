//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    void solve(vector<int> &s, int n) {
        if (n <= 1) {
            return;
        }

        vector<int> temp;
        int num = s.size();
        int i = 0;
        while (i < num) {
            int count = 1;
            int curr = s[i];
            while (i + 1 < num && s[i + 1] == s[i]) {
                count++;
                i++;
            }

            temp.push_back(count);
            temp.push_back(curr);
            i++;
        }

        s = temp;
        solve(s, n - 1);
    }
  
    string lookandsay(int n) {
       vector<int> s = {1};
        solve(s, n);
        string ans = "";
        for(int i = 0; i < s.size(); i++) {
            ans += to_string(s[i]);
        }

        return ans;
    }   
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution obj;
        cout<<obj.lookandsay(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends