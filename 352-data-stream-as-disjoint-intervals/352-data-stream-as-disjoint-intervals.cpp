int BS(vector<vector<int>>& p, int val) {
    int low = 0;
    int high = p.size() - 1;
    int mid = 0;
    while (low <= high) {
        mid = (high + low) / 2;
        if (p[mid][0] == val && p[mid][1] == val) {
            return mid;
        }
        else if (p[mid][0] < val || p[mid][0] == val && p[mid][1] < val) {
            low = mid+1;
        }
        else {
            high = mid;
        }
    }
    return -1;
}

class SummaryRanges {
public:
    vector<vector<int>> p;
    set<int> s;
    SummaryRanges() {
    }

    void addNum(int val) {
        if(s.find(val)==s.end()){
            s.insert(val);
            p.push_back({ val, val });
            sort(p.begin(), p.end());
            int temp = BS(p, val);
            if (temp < p.size() - 1 && p[temp][1] + 1 == p[temp + 1][0]) {
                p[temp][1] = p[temp + 1][1];
                p.erase(p.begin() + temp + 1);
            }
            if (temp > 0 && p[temp - 1][1] + 1 == p[temp][0]) {
                p[temp - 1][1] = p[temp][1];
                p.erase(p.begin() + temp);
            }
        }
    }

    vector<vector<int>> getIntervals() {
        return p;
    }
};