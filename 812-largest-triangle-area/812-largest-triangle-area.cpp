double area(vector<int> a, vector<int> b ,vector<int> c){
    double sa , sb, sc, s;
    sa = sqrt((double)pow((b[1] - a[1]), 2) + pow((b[0] - a[0]), 2));
    sb = sqrt((double)pow((c[1] - a[1]), 2) + pow((c[0] - a[0]), 2));
    sc = sqrt((double)pow((b[1] - c[1]), 2) + pow((b[0] - c[0]), 2));
    s = ((double)sa +sb + sc) / 2;
    return sqrt(s*(s-sa)*(s-sb)*(s-sc));
}

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0.0;
        int size = points.size();
        for(int i = 0; i < size - 2; i++){
            for(int j = i + 1; j < size - 1; j++){
                for(int k = j + 1; k < size; k++){
                    ans = max (ans, area(points[i], points[j], points[k]));
                }
            }
        } 
        return ans;
    }
};