class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int size = releaseTimes.size();
        int m = releaseTimes[0];
        int temp = 0;
        char c = keysPressed[0];
        for (int i = 0; i < size-1;i++){
            temp = releaseTimes[i+1]-releaseTimes[i];
            if(temp>m){
                m = temp;
                c = keysPressed[i+1];
            }
            else if(temp==m){
                if(keysPressed[i+1]>c){
                    c=keysPressed[i+1];
                }
            }
        }
        return c;
    }
};