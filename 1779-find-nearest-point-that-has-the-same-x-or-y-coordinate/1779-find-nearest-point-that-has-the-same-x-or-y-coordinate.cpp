class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int index = -1; 
        int distance = 1e5;
        int temp;
        size_t size = points.size();
        for(int i = 0; i < size; ++i){
            if(points[i][0] == x || points[i][1] == y){
                temp = abs(points[i][0] - x)+abs(points[i][1] - y);
                if(distance > temp){
                    index = i;
                    distance = temp;
                }    
            }
        }
        return index;
    }
};