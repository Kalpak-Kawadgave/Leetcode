class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long sum = 0;
        long long i = 0;
        while (sum<neededApples){
            ++i;
            sum+=12*i*i;
        }
        return 8*i;
    }
};