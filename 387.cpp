/*
//方法1
class Solution {
public:
    int firstUniqChar(string s)
    {
        int count[256] = {0};
        int size = s.size();
        for (int i = 0; i < size; ++i)
        {
            count[s[i]] += 1;
        }
        for (int i = 0; i < size; ++i)
        {
            if (count[s[i]] == 1)
                return i;
        }
        return -1;
    }
};
*/

//方法2
class Solution {
public:
    int firstUniqChar(string s)
    {
        for (int i = 0; i < s.size(); ++i)
        {
            size_t index1 = s.find(s[i]);
            size_t index2 = s.rfind(s[i]);
            if (index1 == index2)
                return i;
        }
        return -1;
    }
};