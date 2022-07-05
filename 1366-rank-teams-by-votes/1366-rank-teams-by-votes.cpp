class Solution {
public:
string rankTeams(vector<string>& votes) {
    string ans;
    size_t size1 = votes.size();
    size_t size2 = votes[0].size();
    vector<vector<int>> v(size2, vector<int>(size2, 0));
    map<char, int> m;
    map<int,char> im;
    vector<char> temp;
    for (int i = 0; i < size2; ++i) {
        temp.push_back(votes[0][i]);
    }
    sort(temp.begin(),temp.end());
    for (int i = 0; i < size2; ++i) {
        m.insert(make_pair(temp[i], i));
        im.insert(make_pair(size2-1-i, temp[i]));
    }
    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) {
            ++v[m[votes[i][j]]][j];
        }
    }
    for (int i = 0; i < size2; ++i) {
        v[i].push_back(size2-1-m[temp[i]]);
    }
    sort(v.begin(), v.end());
    for (int i = size2-1; i >=0 ; --i) {
        ans += im[v[i][size2]];
    }
    return ans;
}
};