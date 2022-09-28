class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size();
        int n = nums2.size();
        if(m>n)
            return findMedianSortedArrays(nums2,nums1);
        int lmax1, rmin1, lmax2, rmin2, c1, c2, low=0, heigh = 2*m;
        while(low<=heigh){
            int c1 = (low+heigh)/2;
            int c2 = n + m - c1;
            lmax1 = c1 == 0 ? INT_MIN : nums1[(c1-1)/2];
            rmin1 = c1 == 2*m ? INT_MAX : nums1[c1/2];
            lmax2 = c2 == 0 ? INT_MIN : nums2[(c2-1)/2];
            rmin2 = c2 == 2*n ? INT_MAX : nums2[c2/2];
            
            if(lmax1>rmin2) heigh = c1-1;
            else if(lmax2>rmin1) low = c1+1;
            else break;
        }
        return (max(lmax1,lmax2)+min(rmin1,rmin2))/2.0;
    }
};