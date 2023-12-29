//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string s)
    {
        stack<char> st;
        st.push('a');

        for(int i=0;i<s.length();i++) {
            if(s[i]=='{' || s[i]=='(' || s[i]=='[') {
                st.push(s[i]);
            } else {
                if (s[i]==')' && (st.top()!='('|| st.top()=='a')) {
                return false;
                } else if (s[i]=='}' && (st.top()!='{'|| st.top()=='a')) {
                return false;
                }  else if (s[i]==']' && (st.top()!='['|| st.top()=='a')) {
                return false;
                }
                st.pop();
            } 
        }
        if(st.top()=='a') {
            return true;
        } else {
            return false;
        }
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends