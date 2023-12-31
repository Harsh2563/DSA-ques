//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            vector<int> ans;
            for(int i=0;i<txt.size();i++) {
                if(txt[i]==pat[0] && pat.size()+i<=txt.size()) {
                    int flag = 1;
                    for(int j=i;j<pat.size()+i;j++) {
                        if(pat[j-i]!=txt[j]) {
                            flag=0;
                            break;
                        }
                    }
                    if(flag==1) {
                        ans.push_back(i+1);
                    } 
                }
            }
            if(ans.size()==0) {
                ans.push_back(-1);
            }
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends