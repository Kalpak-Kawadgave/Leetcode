unordered_map<int,int> m;

bool cm(int a,int b){
   if(m[a]>m[b])
       return true;
   return false;
}
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        m.clear();
        sort(barcodes.begin(),barcodes.end());
        int size = barcodes.size();
        vector<int> ans(size);
        for(int i=0;i<size;i++){
           m[barcodes[i]]++;
       }
        sort(barcodes.begin(),barcodes.end(),cm);
        if(size%2==1){
            for(int i = 0; i < size; i++){
                if(2*i<size){
                    ans[i*2]= barcodes[i];
                }
                else{
                    ans[((2*i)%size)]= barcodes[i];
                }
            }
        }
        else{
            for(int i = 0; i < size; i++){
                if(2*i<size){
                    ans[i*2]= barcodes[i];
                }
                else{
                    ans[((2*i)%size)+1]= barcodes[i];
                }
            }
        }
        return ans;
    }
};