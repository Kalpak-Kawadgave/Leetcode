class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int time = 0;
        int arrival = 0;
        double wait = 0;
        int size = customers.size();
        for(int i = 0; i < size; i++){
            arrival = customers[i][0];
            time = customers[i][1] + max(time, arrival);
            wait += time - arrival;
        }
        return wait/size;
    }
};