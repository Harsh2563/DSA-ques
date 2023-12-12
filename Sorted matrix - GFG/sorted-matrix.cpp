//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        
        vector<pair<int, pair<int, int>>> flattened;
        vector<int> ans;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                flattened.push_back({Mat[i][j], {i, j}});
            }
        }

        sort(flattened.begin(), flattened.end());

 
        for (const auto& element : flattened) {
            ans.push_back(element.first);
        }
        
        
        vector<vector<int>> final(N, vector<int>(N, 0));

        int k = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                final[i][j] = ans[k];
                k++;
            }
        }
        return final;

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> v(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) cin >> v[i][j];
        Solution ob;
        v = ob.sortedMatrix(N, v);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cout << v[i][j] << " ";
            cout << "\n";
        }
    }
}
// } Driver Code Ends