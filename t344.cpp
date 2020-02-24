class Solution {
public:
    void reverseString(vector<char>& s)
    {
        if (s.empty())
            return;
        size_t start = 0;
        size_t end = s.size() - 1;
        while (start < end)
        {
            swap(s[start], s[end]);
            ++start;
            --end;
        }
    }
};