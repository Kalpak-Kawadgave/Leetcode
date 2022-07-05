class Solution {
public:
    bool buddyStrings(string s, string goal) {
        size_t size = s.size();
        if(goal.size() != size){
            return false;
        }
        vector<int> alphabets(26,0);
        vector<pair<char,char>> diff;
        for(int i = 0; i < size; ++i){
            ++alphabets[s[i] - 'a'];
            if(s[i]!=goal[i]){
                diff.push_back(make_pair(s[i], goal[i]));
            }
        }
        if(diff.size()==0){
            for(int x : alphabets){
                if(x>=2){
                    return true;
                }
            }
        }
        else if(diff.size()==2){
            if(diff[0].second==diff[1].first&&diff[0].first==diff[1].second){
                return true;
            }
        }
        return false;
    }
};