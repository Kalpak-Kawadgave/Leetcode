// void update(int i, vector<int> &time, vector<int> manager, vector<int> informTime)
// {
//     if (time[manager[i]] == -1)
//     {
//         update(manager[i], time, manager, informTime);
//     }

//     time[i] = informTime[manager[i]] + time[manager[i]];
// }


class Solution {
public:

            int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int res = 0;
        for (int i = 0; i < n; ++i)
            res = max(res, dfs(i, manager, informTime));
        return res;
    }

    int dfs(int i, vector<int>& manager, vector<int>& informTime) {
        if (manager[i] != -1) {
            informTime[i] += dfs(manager[i], manager, informTime);
            manager[i] = -1;
        }
        return informTime[i];
    
    }
//         vector<int> time(n, -1);
//         time[headID] = 0;
//         int maximum = 0;

//         for (int i = 0; i < n; i++)
//         {
//             if (manager[i] != -1)
//             {
//                 if (time[i] == -1)
//                 {
//                     update(i, time, manager, informTime);
//                 }
//             }
//             if (maximum < time[i])
//             {
//                 maximum = time[i];
//             }
//         }
//         return maximum;
//     }
};
