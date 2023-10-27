string restoreString(string s, vector<int>& indices) {
        int n = indices.size();
        vector<char> v(n);
        for(int i = 0;i<n;i++) {
            v[indices[i]] = s[i];
        }
        string ans="";
        for(int i = 0;i<n;i++) {
            ans+=v[i];
        }
        return ans;
    }
