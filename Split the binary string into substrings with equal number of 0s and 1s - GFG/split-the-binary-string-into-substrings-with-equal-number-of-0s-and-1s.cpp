//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int maxSubStr(string str){
        int count0 = 0;
        int count1=0;
        int total = 0;

        for (int i = 0; i < str.length(); i++) {
            if(str[i]=='1') {
                count1++;
            } else {
                count0++;
            }
            
            if(count1==count0) {
                total++;
                count0=0;
                count1=0;
            }
        }

        if(count0==count1) {
            return total;
        } else {
            return -1;
        }
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends