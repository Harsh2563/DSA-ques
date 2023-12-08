//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    
    bool solve(vector<vector<int>>& matrix, int x, int j, int i) {
        int n = matrix.size();

        if (i ==n || j <0) {
            return false;
        }

        if (matrix[i][j] == x) {
            return true;
        }
        bool a1,a2;
        if (matrix[i][j] < x) {
            a1= solve(matrix, x, n-1, i + 1);
        } else if (matrix[i][j] > x) {
            a2= solve(matrix, x, j - 1, i);
        }
        return a1||a2;
    }
    //Function to search a given number in row-column sorted matrix.
    bool search(vector<vector<int> > matrix, int n, int m, int x) 
    {
        return solve(matrix,x,n-1,0); 
    }
};

//{ Driver Code Starts.
int main() 
{ 
	int t;
    cin>>t;
    while(t--)
    {

 		int n, m;
    	cin>> n>> m;
        vector<vector<int> > matrix(n);
            
        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        int x;
        cin>>x;
        Solution obj;
        if (obj.search(matrix,n,m,x)) 
            cout << "1\n"; 
        else
            cout << "0\n"; 
    }
	return 0; 
} 


// } Driver Code Ends