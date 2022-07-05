class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int size = heights.size();
        int sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < size-1; i++){
            int h = heights[i+1]-heights[i];
            if(h>0){
                pq.push(h);
            }
            if(pq.size()>ladders){
                sum+=pq.top();
                pq.pop();
            }
            if(sum>bricks){
                return i;
            }
        }
        return size-1;
    }
};