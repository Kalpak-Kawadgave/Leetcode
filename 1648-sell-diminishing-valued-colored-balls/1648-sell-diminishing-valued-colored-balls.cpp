class Solution {
public:
    int maxProfit(vector<int>& a, int N) {
        long MOD = 1e9 + 7;
        size_t size = a.size();
        a.push_back(0);
        sort(a.begin(), a.end(), greater<int>());
        long sum = 0;
        for (long i = 0; i < size; ++i) {
            long mult = (i + 1) * (a[i] - a[i + 1]);
            if (N == 0) {
                break;
            }
            else if (N > mult) {
                sum += (mult * (a[i] + a[i + 1] + 1) / 2) % MOD;
                sum %= MOD;
                N -= mult;
            }
            else {
                long t1 = N / (i + 1);
                long t2 = N % (i + 1);
                sum += ((i+1)*(t1 * (2*a[i] - t1 + 1) / 2)+((a[i]-t1)*t2)) % MOD;
                N -= t1 * (i + 1) + t2;
                sum %= MOD;
            }
        }
        return sum;
    }
};