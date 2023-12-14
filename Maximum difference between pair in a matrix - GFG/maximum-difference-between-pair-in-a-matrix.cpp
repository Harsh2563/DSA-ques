//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int findMaxValue(vector<vector<int>>&mat, int N)
    {
        int ans = INT_MIN;
        vector<vector<int>> maxVal(N,vector<int>(N,0));
        maxVal[N-1][N-1]=mat[N-1][N-1];
        
        for(int i=N-2;i>=0;i--) {
            maxVal[N-1][i] = max(maxVal[N-1][i+1],mat[N-1][i]);
            // ans = max(ans,maxVal[N-1][i]);
        }
        
        for(int i=N-2;i>=0;i--) {
            maxVal[i][N-1] = max(maxVal[i+1][N-1],mat[i][N-1]);
            // ans = max(ans,maxVal[i][N-1]);
        }
        
        for(int i=N-2;i>=0;i--) {
            for(int j=N-2;j>=0;j--) {
                maxVal[i][j]= max(mat[i][j],max(maxVal[i+1][j],maxVal[i][j+1]));
            }
        }
        

        
        for(int i=N-2;i>=0;i--) {
            for(int j=N-2;j>=0;j--) {
                if(maxVal[i+1][j+1]-mat[i][j]>ans) {
                    ans = maxVal[i+1][j+1]-mat[i][j];
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<vector<int>>mat(n,vector<int>(n, 0));
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < n; j++){
	            cin >> mat[i][j];
	        }
	    }
	    Solution ob;
	    int ans = ob.findMaxValue(mat, n);
	    cout << ans <<endl;
	}
	return 0;
}

// } Driver Code Ends