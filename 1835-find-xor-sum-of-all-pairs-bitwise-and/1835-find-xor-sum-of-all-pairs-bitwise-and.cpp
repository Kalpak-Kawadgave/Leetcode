class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        size_t size1 = arr1.size(), size2 = arr2.size();
        if(size1==1&&size2==1){
            return arr1[0] & arr2[0];
        }
        int x = arr1[0];
        int y = arr2[0];
        for(int i = 1; i < size1; ++i){
            x ^= arr1[i];
        }
        for(int i = 1; i < size2; ++i){
            y ^= arr2[i];
        }
        return x&y;
    }
};