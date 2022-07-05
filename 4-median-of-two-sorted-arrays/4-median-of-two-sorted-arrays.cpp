class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        size_t size1 = nums1.size();
        size_t size2 = nums2.size();
        size_t size = size1+size2;
        vector<int> v(size);
        merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),v.begin());
        if(size%2!=0){
            return v[size/2];
        }
        else{
            return (double)(v[size/2] + v [size/2 - 1])/2;
        }
    }
};