//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	    void solve(string s,unordered_map<string,int> &map,int i,int n) {
	        
	        if(i==n-1) {
	            map[s]++;
	            return;
	        }
	        
	        map[s]++;
	        
	        
	        for(int j = i;j<n;j++) {
	            string s1 = s;
	            swap(s[i],s[j]);
	            solve(s,map,i+1,n);
	        }
	    }
	
		vector<string>find_permutation(string S)
		{
		    int n = S.length();
		    unordered_map<string,int> map;
		    vector<string> ans;
		    solve(S,map,0,n);
		    for(auto i: map) {
		        ans.push_back(i.first);
		    }
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends