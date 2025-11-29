class Solution {
public:
    int strStr(string hay, string needle) {
        int n = hay.size(), m = needle.size();
        for (int i = 0; i < n; i ++){
            if (hay[i] == needle[0]){
                string temp = hay.substr(i, m);
                if (temp == needle){
                    return i;
                }
            }
        }

        return -1;
    }
};