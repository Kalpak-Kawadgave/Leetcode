class Solution {
public:
    string reorganizeString(string s) {
        size_t size = s.size();
        int half = ceil((float)size / 2);
        int j = 25;
        vector<pair<int, int>> count = { 26, pair<int,int>{0,0} };
        for (int i = 0; i < 26; ++i) {
            count[i].second = i;
        }
        for (int i = 0; i < size; i++) {
            ++count[s[i] - 97].first;
            if (count[s[i] - 97].first > half) return "";
        }
        sort(count.begin(), count.end());
        for (int i = 0; i < size; i += 2) {
            s[i] = count[j].second + 97;
            --count[j].first;
            if (count[j].first == 0) {
                --j;
            }
        }
        for (int i = 1; i < size; i += 2) {
            s[i] = count[j].second + 97;
            --count[j].first;
            if (count[j].first == 0) {
                --j;
            }
        }
        return s;
    }
};