//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        vector<int> h(m, 0);
        vector<int> right(m, m);
        vector<int> left(m, 0);

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (M[i][j] == 1) {
                    h[j] += 1;
                } else {
                    h[j] = 0;
                }
            }

            stack<int> s;
            for (int k = 0; k < m; k++) {
                while (!s.empty() && h[s.top()] >= h[k]) {
                    s.pop();
                }
                left[k] = (s.empty()) ? 0 : (s.top() + 1);
                s.push(k);
            }

            while (!s.empty()) s.pop();

            for (int k = m - 1; k >= 0; k--) {
                while (!s.empty() && h[s.top()] >= h[k]) {
                    s.pop();
                }
                right[k] = (s.empty()) ? m : s.top();
                s.push(k);
            }

            for (int k = 0; k < m; k++) {
                ans = max(ans, (right[k] - left[k]) * h[k]);
            }
        }
        return ans;
     }
        

};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends