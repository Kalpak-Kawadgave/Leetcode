class Solution {
public:
    int openLock(vector<string>& DEs, string target) {
        string temp;
        std::unordered_set<std::string> deadends;
        std::unordered_set<std::string> visited;
        std::vector<std::string> currentLevel;
        std::vector<std::string> nextLevel;
        int level = 0;
        for (auto de : DEs) {
            deadends.emplace(de);
        }
        if(deadends.find("0000")!=deadends.end()){
            return -1;
        }
        if (target == "0000"){
            return 0;
        }
        currentLevel.emplace_back(target);
        while (!currentLevel.empty()) {
            for (auto current : currentLevel) {
                for (int i = 0; i < 4; ++i) {
                    temp = current;
                    ++temp[i];
                    if (temp[i] > '9') {
                        temp[i] -= 10;
                    }
                    if (deadends.find(temp) == deadends.end() && visited.find(temp) == visited.end()) {
                        if (temp == "0000") {
                            return ++level;
                        }
                        nextLevel.emplace_back(temp);
                        visited.emplace(temp);
                    }
                    temp = current;
                    --temp[i];
                    if (temp[i] < '0') {
                        temp[i] += 10;
                    }
                    if (deadends.find(temp) == deadends.end() && visited.find(temp) == visited.end()) {
                        if (temp == "0000") {
                            return ++level;
                        }
                        nextLevel.emplace_back(temp);
                        visited.emplace(temp);
                    }
                }
            }
            ++level;
            currentLevel.clear();
            currentLevel=nextLevel;
            nextLevel.clear();
        }
        return -1;
    }
};