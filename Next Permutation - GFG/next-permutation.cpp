//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int permutation(vector<int> arr,int i) {
        int n = arr.size();
        int mini = i+1;
        for(int j = i+2;j<n;j++) {
           if(arr[j]>arr[i]) {
                if(arr[j]<arr[mini]) {
                    mini= j;
                }
           }
        }
        return mini;
    }
    vector<int> nextPermutation(int N, vector<int> arr){
        int flag = 1;
        int index,next;

        for (int i = N - 1; i >= 1; i--) {
            if(arr[i]>arr[i-1]) {
                flag = 0;
                index = permutation(arr,i-1);
                next = i-1;
                break;
            }
        }

       

        if (flag == 1) {
            reverse(arr.begin(), arr.end());
        } else {
             swap(arr[next], arr[index]);
            sort(arr.begin() +next+1 , arr.end());
        }
        
        return arr;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends