bool compare(int a, int b){
    string c,d;
    c = to_string(a);
    d = to_string(b);
    return (c+d>d+c);
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans = "";
        string def = "0";
        int size = nums.size();
        sort(nums.begin(), nums.end(), compare);
        for(int i = 0; i < size; i++){
            ans += to_string(nums[i]);
        }
        if(ans[0]=='0')
        {
            return def;
        }
        return ans;
    }
};