class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area = 0;
        size_t size = heights.size(); 
        vector<int> left(size,0);
        vector<int> right(size,0);
        int trav;
        for (int i = 0; i < size; ++i){
            trav = i - 1;
            while(trav>=0&&heights[i]<=heights[trav]){
                trav = left[trav];
            }
            left[i]=trav;
        }
        for (int i = size - 1; i >= 0; --i){
            trav = i + 1;
            while(trav<size&&heights[i]<=heights[trav]){
                trav = right[trav];
            }
            right[i]=trav;
        }
        for(int i = 0; i < size; ++i){
            max_area = max(max_area, heights[i]*(right[i]-left[i]-1));
        }        
        return max_area;
    }
};

/*
        int c = 0;
        int b = 0;
        size_t size = heights.size();
        set<int> s(heights.begin(), heights.end());
        unordered_map<int, vector<int>> m;
        set<pair<int, int>> ps;
        for (int i = 0; i < size; i++) {
            m[heights[i]].push_back(i);
        }
        set<int>::reverse_iterator itr;
        set<pair<int, int>>::iterator it;
        set<pair<int, int>>::iterator temp;
        for (itr = s.rbegin(); itr != s.rend(); itr++) {
            for (int a : m[*itr]) {
                ps.insert(make_pair(a, a + 1));
            }
            temp = ps.begin();
            for (it = ps.begin(); it != ps.end(); ++it) {
                if (temp->second == it->first) {
                    ps.insert(make_pair(temp->first, it->second));
                    ps.erase(temp);
                    temp = it;
                    ++it;
                    ps.erase(temp);
                    --it;
                    temp = it;
                }
                else {
                    if (it!=ps.begin())
                    temp++;
                }
            }
            for (auto a : ps) {
                b = max(b, a.second - a.first);
            }
            c = max(c, b * (*itr));
        }
        return c;
*/