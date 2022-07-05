long long nCr(long long n)
{
    return n * (n-1) / 2;
}

class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        long long ans = 0;
        int count = 1;
        size_t size = rectangles.size();
        vector<double> v;
        for(auto a: rectangles){
            v.push_back((double)a[0]/a[1]);
        }
        sort(v.begin(),v.end());
        for(int i = 0; i < size - 1; i++){
            if(v[i]==v[i+1]){
                count++;
            }
            else{
                ans+=nCr((long)count);
                count=1;
            }
        }
        ans+=nCr((long)count);
        count=1;
        return ans;
    }
};