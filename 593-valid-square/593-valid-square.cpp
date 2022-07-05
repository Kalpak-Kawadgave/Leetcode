bool compare(const vector<int>& p1, const vector<int>& p2) {
    if (p1[0] != p2[0]) {
        return p1[0] < p2[0];
    }
    return p1[1] < p2[1];
}

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if(p1==p2){
            return false;
        }
        vector<vector<int>> p;
        p.push_back(p1);
        p.push_back(p2);
        p.push_back(p3);
        p.push_back(p4);
        sort(p.begin(), p.end(), compare);
        int d1 = (pow((p[0][0] - p[1][0]) , 2)) + (pow((p[0][1] - p[1][1]) , 2));
        int d2 = (pow((p[0][0] - p[2][0]) , 2)) + (pow((p[0][1] - p[2][1]) , 2));
        int d3 = (pow((p[3][0] - p[1][0]) , 2)) + (pow((p[3][1] - p[1][1]) , 2));
        int d4 = (pow((p[3][0] - p[2][0]) , 2)) + (pow((p[3][1] - p[2][1]) , 2));
        if (d1 != d2 || d2 != d3 || d3 != d4) {
            return false;
        }
        int d5 = (pow((p[1][0] - p[2][0]) , 2)) + (pow((p[1][1] - p[2][1]) , 2));
        int d6 = (pow((p[3][0] - p[0][0]) , 2)) + (pow((p[3][1] - p[0][1]) , 2));
        if (d5 != d6) {
            return false;
        }
        return true;
    }
};