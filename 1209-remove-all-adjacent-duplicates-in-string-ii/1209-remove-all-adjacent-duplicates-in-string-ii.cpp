class Solution {
public:
string removeDuplicates(string s, int k)
{
    bool flag = true;
    int size = s.size();
    int count = 1;
    while (flag == true && size > k)
    {
        flag = false;
        count = 1;
        for (int i = size-2; i >=0; i--)
        {
            if (s[i] == s[i+1])
            {
                count++;
            }
            else
            {
                count = 1;
            }
            if (count == k)
            {
                s.erase(i, k);
                size = size - k;
                count = 1;
                flag = true;
            }
        }
    }
    return s;
}
};