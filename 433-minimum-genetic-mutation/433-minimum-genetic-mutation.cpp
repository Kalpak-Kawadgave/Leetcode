int diff(string a, string b)
{
    int diff = 0;
    for (int i = 0; i < 8; i++)
    {
        if (a[i] != b[i])
        {
            diff++;
        }
    }
    return diff;
}
int count(string s)
{
    int c = 0;
    int strsize = s.size();
    for (int i = 0; i < strsize; i++)
    {
        if (s[i] == '1')
        {
            c++;
        }
    }
    return c;
}
void check(string current, string end, string visited, vector<string> &bank, int *ans)
{
    if (current == end){
        {
            int temp = count(visited);
            if (*ans > temp)
            {
                *ans = temp;
            }
        }
    }
    else{
        int size = bank.size();
        for (int i = 0; i < size; i++)
        {
            if (visited[i] == '0')
            {
                if (diff(current, bank[i]) == 1)
                {
                    visited[i] = '1';
                    check(bank[i], end, visited, bank, ans);
                    visited[i] = '0';
                }
            }
        }
    }
}
class Solution {
public:
    int minMutation(string start, string end, vector<string> &bank)
    {
        if (start == end)
        {
            return 0;
        }
        int size = bank.size();
        if (size == 0)
        {
            return -1;
        }
        string visited = "";
        bool possible = false;
        for (int i = 0; i < size; i++)
        {
            if (end == bank[i])
            {
                possible = true;
            }
            visited += '0';
        }
        if (possible == false)
        {
            return -1;
        }
        int ans = size+1;
        check(start, end, visited, bank, &ans);
        if (ans != size+1)
        {
            return ans;
        }
        else
        {
            return -1;
        }
    }
};