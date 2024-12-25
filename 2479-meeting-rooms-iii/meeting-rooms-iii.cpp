class Solution {
public:
    std::set<std::pair<unsigned int, unsigned int>>::iterator fetchPair(std::set<std::pair<unsigned int, unsigned int>>& freeTimeAndRoomNoPairs, unsigned int x) {
        // Iterate through the set to find the pair that matches the condition
        auto bestIt = freeTimeAndRoomNoPairs.begin();
        for (auto it = freeTimeAndRoomNoPairs.begin(); it != freeTimeAndRoomNoPairs.end(); ++it) {
            // Check if the current pair's first element is greater than or equal to x
            if (it->first <= x) {
                if (it->second < bestIt->second) {
                    bestIt = it;
                }
            }
            else{
                break;
            }
        }

        return bestIt;
    }

    unsigned int mostBooked(int n, vector<vector<int>>& meetings) {
        unsigned int result = 0;
        if (n != 1){
            unsigned int duration = 0;
            unsigned int freeTime, roomNo, nextFreeTime;
            std::vector<unsigned int> roomUsageCount(n, 0);
            std::set<std::pair<unsigned int, unsigned int>> freeTimeAndRoomNoPairs;
             
            //Sort the meetings by their start time
            std::sort(meetings.begin(), meetings.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
                return a[0] < b[0]; 
            });

            //initialize all the freeTimeAndRoomNoPairs 
            for (unsigned int i = 0; i < n; ++i) {
                freeTimeAndRoomNoPairs.insert({0, i});
            }

            //logic to assign the rooms
            for(const auto & meeting:meetings){
                auto nextAvailableRoom = fetchPair(freeTimeAndRoomNoPairs, meeting[0]);
                freeTime = nextAvailableRoom->first;
                roomNo = nextAvailableRoom->second;
                freeTimeAndRoomNoPairs.erase(nextAvailableRoom);
                ++roomUsageCount[roomNo];
                if(freeTime < meeting[0]){
                    nextFreeTime = meeting[1];
                }
                else{
                    nextFreeTime = freeTime + meeting[1]-meeting[0];
                }
                freeTimeAndRoomNoPairs.insert(make_pair(nextFreeTime, roomNo));
            }

            // Get the room with max usage count
            auto maxRoomUsageCountIt = std::max_element(roomUsageCount.begin(), roomUsageCount.end());
            result = std::distance(roomUsageCount.begin(), maxRoomUsageCountIt); 
        }
        return result;
    }  
};