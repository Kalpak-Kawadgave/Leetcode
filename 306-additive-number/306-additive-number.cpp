bool fib(long a, long b, string abc){
    if(abc==""){
        return true;
    }
    int c = a+b;
    string s = to_string(c);
    if(s[0]=='0'){
        return false;
    }
    if(abc.substr(0,s.size())==s){
        cout<<b<<" "<<c<<"\n";
        return fib(b,c,abc.substr(s.size()));
    }
    return false;
    
}
class Solution {
public:
    bool isAdditiveNumber(string num) {
        int size = num.size();
        if (size<3){
            return false;
        }
        bool ans;
        int range = (size - 1)/2;
        long num1, num2; 
        string n1,n2;
        for(int i = 1; i <= range;i++){
            for(int j = 1; j <= range; j++){
                n1=num.substr(0, i);
                n2=num.substr(i, j);
                if((n1.size()>1&&n1[0]=='0')||(n2.size()>1&&n2[0]=='0')){
                    break;
                }
                num1=stol(n1);
                num2=stol(n2);
                string s = to_string(num1+num2);
                if(num.substr(i+j,s.size())==s){
                    cout<<num1<<" "<<num2<<" "<<num1+num2<<"\n";
                    ans=fib(num2, num1+num2, num.substr(i+j+s.size()));
                }
                if (ans==true){
                    return true;
                } 
            }
        }
        return false;
    }
};
