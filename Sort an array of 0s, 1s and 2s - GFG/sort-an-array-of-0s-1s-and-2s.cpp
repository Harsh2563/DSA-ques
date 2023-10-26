//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n) {
    int s = 0;
    int e = n - 1;
    int i = 0;
    
    while (i <= e) {
        if (a[i] == 0) {
            swap(a[i], a[s]);
            i++;
            s++;
        } else if (a[i] == 1) {
            i++;
        } else {  // a[i] == 2
            swap(a[i], a[e]);
            e--;
        }
    }
}

    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends