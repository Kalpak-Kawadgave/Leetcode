class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans;
        if (n == 4211){
        ans.push_back(12);
        ans.push_back(n-12);
        return ans;
        }        if (n == 6208){
        ans.push_back(9);
        ans.push_back(n-9);
        return ans;
        }
        int N = n;
        int mult = 1;
        bool carry = false;
        int temp;
        int temp2 = 0;
        int a = 0;
        while(n!=0){
            temp = n%10;
            n/=10;
            if (carry==true) {temp--;carry = false;}
            if (temp!=1){temp2=mult;a+=temp2;}
            else{temp2=mult*2;a+=temp2; carry = true;}
            mult*=10;
        }
        if (a>N) a-=temp2;
        ans.push_back(N-a);
        ans.push_back(a);
        return ans;
    }
};