double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         int n = nums1.size();
         int m = nums2.size();

         
         if(n>m) {
             return findMedianSortedArrays(nums2,nums1);
         }
         int s = 0;
         int e = n;

         int realMid = (n+m+1)/2;

         while(s<=e) {
            int mid = (s+e)/2;
            int curr = mid;
            int rem = realMid-curr;

            int leftA = (curr>0) ? nums1[curr-1] : INT_MIN;
            int rightA = (curr<n) ? nums1[curr] : INT_MAX;
            int leftB = (rem>0) ? nums2[rem-1] : INT_MIN;
            int rightB = (rem<m) ? nums2[rem] : INT_MAX;

            if(leftA<=rightB && leftB<=rightA) {
                if((m+n)%2==0) {
                    return (max(leftA,leftB) + min(rightA,rightB))/2.0;
                } else {
                    return max(leftA,leftB);
                }
            } else if(leftA>rightB) {
                e = mid-1;
            } else {
                s = mid+1;
            }
         }
         return 0.0;
    }
