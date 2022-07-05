class Solution {
public:
    string largestTimeFromDigits(vector<int>& arrr) {
        vector<int> arr{arrr};
        string s = "";
        int temp = -1;
        int pos = -1;
        int lim = 10;
        for(int i = 0; i < 4; ++i){
            if(arr[i] > temp&&arr[i]<3){
                temp = arr[i];
                pos = i;
            }
        }
        if (temp == -1) goto label;
        s+=to_string(temp);   
        if (temp == 2) lim = 4;
        temp = -1;
        arr.erase(arr.begin()+pos);
        for(int i = 0; i < 3; ++i){
            if(arr[i] > temp&&arr[i]<lim){
                temp = arr[i];
                pos = i;
            }
        }
        if (temp == -1) goto label;
        s+=to_string(temp);  
        s+=":";   
        temp = -1;       
        arr.erase(arr.begin()+pos);
        for(int i = 0; i < 2; ++i){
            if(arr[i] > temp&&arr[i]<6){
                temp = arr[i];
                pos = i;
            }
        }
        if (temp == -1) goto label;
        s+=to_string(temp);   
        arr.erase(arr.begin()+pos);
        s+=to_string(arr[0]);   
        return s;
        label:
        arr.clear();
        s = "";
        for (int i = 0; i < 4 ; ++i){
            arr.push_back(arrr[i]);
        }
        temp = -1;
        pos = -1;
        lim = 10;
        for(int i = 0; i < 4; ++i){
            if(arr[i] > temp&&arr[i]<2){
                temp = arr[i];
                pos = i;
            }
        }
        if (temp == -1) return "";
        s+=to_string(temp);   
        if (temp == 2) lim = 4;
        temp = -1;
        arr.erase(arr.begin()+pos);
        for(int i = 0; i < 3; ++i){
            if(arr[i] > temp&&arr[i]<lim){
                temp = arr[i];
                pos = i;
            }
        }
        if (temp == -1) return "";
        s+=to_string(temp);  
        s+=":";   
        temp = -1;       
        arr.erase(arr.begin()+pos);
        for(int i = 0; i < 2; ++i){
            if(arr[i] > temp&&arr[i]<6){
                temp = arr[i];
                pos = i;
            }
        }
        if (temp == -1) return "";
        s+=to_string(temp);   
        arr.erase(arr.begin()+pos);
        s+=to_string(arr[0]);  
        return s;
    }
};