class Solution {
public:
        int hIndex(vector<int>& citations) {
        int left=0, len = citations.size(), right= len-1,  mid;
        while(left<=right)
        {
            mid=(left+right)>>1;
            if(citations[mid]== (len-mid)) return citations[mid];
            else if(citations[mid] > (len-mid)) right = mid - 1;
            else left = mid + 1;
        }
        return len - (right+1);
        }
};
    
    //     int size = citations.size();
    //     if(size == 1){
    //         if(citations[0] != 0){
    //             return 1;
    //         }
    //         else return 0;
    //     }
    //     int low = 0;
    //     int high = size - 1;
    //     int mid;
    //     int ans = 0; 
    //     while(low<high){
    //         mid = (low + high)/2;
    //         if(size - mid==citations[mid]){
    //             return citations[mid];
    //         }
    //         else if(size - mid>citations[mid]){
    //             low = mid;
    //         }
    //         else if(size - mid<citations[mid]){
    //             high = mid;
    //         }
    //     }
    //     return citations[mid];
    // }