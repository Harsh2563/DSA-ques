bool rotateString(string s, string goal) {
        int n =s.length();
        for(int i =0;i<n;i++) {
            int temp = s[0];
            for(int j = 1;j<n;j++) {
                
                s[j-1] = s[j];
            }
            s[n-1] = temp;

            if(s==goal) {
                return true;
            }
        }

        return false;
    }
