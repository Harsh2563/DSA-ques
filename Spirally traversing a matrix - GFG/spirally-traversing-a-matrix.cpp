//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c) 
    {
        int count = 0;
        vector<int> ans;
        int sr = 0;
        int sc=0;

        int er=matrix.size()-1;
        int ec=matrix[0].size()-1;
        int total = (ec+1)*(er+1);
        
        while(sc<=ec && sr<=er && total) {
            for(int i =sc;i<=ec && count<total;i++) {
                ans.push_back(matrix[sr][i]);
                count++;
            }
            sr++;
            
            for(int i = sr;i<=er && count<total;i++) {
                ans.push_back(matrix[i][ec]);
                count++;
            }
            ec--;
            
            for(int i = ec;i>=sc && count<total;i--) {
                ans.push_back(matrix[er][i]);
                count++;
            }
            er--;
            
            for(int i = er;i>=sr && count<total;i--) {
                ans.push_back(matrix[i][sc]);
                count++;
            }
            sc++;
            
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
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends