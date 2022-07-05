int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
     
}

class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<vector<int>> hcf(101,vector<int>(101,-1));
        vector<string> Fractions;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j < i; ++j){
                if (hcf[i][j]==-1){
                   hcf[i][j] = gcd(i,j); 
                   hcf[j][i] = gcd(i,j); 
                }
                if(hcf[i][j]<=1){
                Fractions.push_back((to_string(j)+"/"+to_string(i)));
            }}
        }
        return Fractions;
    }
};