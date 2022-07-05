class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int ans = 0;
        map<int, int> m;
        sort(nums.begin(), nums.end());
        size_t size = nums.size();
        int temp = 1,temp2 = 0;
        for(int i = 0; i < size - 1; ++i){
            if(nums[i]!= nums[i+1]){
                m.insert(make_pair(nums[i],nums[i] * temp));
                temp = 1;
            }
            else{
                ++temp;
            }
        }
        m.insert(make_pair(nums[size-1],nums[size-1] * temp));
        m.insert(make_pair(-1,0));
        auto it = m.begin();
        auto trav = m.begin();
        ++it;
        temp = 0;
        for(; it != m.end(); ++it){
            if((trav->first)+1!=(it->first)){
                ans = max(ans, it->second+temp2);
            }
            else{
                ans = max(ans, it->second+temp);
            }
            temp = temp2;
            temp2 = ans;
            ++trav;
        }
        return ans;
    }
};





//         int ans = 0;
//         multimap<int, int> m;
//         set<int> s;
//         sort(nums.begin(), nums.end());
//         size_t size = nums.size();
//         int temp = 1;
//         for(int i = 0; i < size - 1; ++i){
//             if(nums[i]!= nums[i+1]){
//                 m.insert(make_pair(nums[i] * temp, nums[i]));
//                 temp = 1;
//             }
//             else{
//                 ++temp;
//             }
//         }
//         m.insert(make_pair(nums[size-1] * temp, nums[size-1]));
//         multimap<int, int>::reverse_iterator it;
//         for(it = m.rbegin(); it != m.rend(); it++){
//             if(s.find(it->second)==s.end()){
//                 ans+=it->first;
//                 s.insert((it->second)-1);
//                 s.insert((it->second)+1);
//             }
//         }
//         return ans;
        