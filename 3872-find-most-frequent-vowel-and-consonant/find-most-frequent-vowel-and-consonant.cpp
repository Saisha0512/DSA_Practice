class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> freq;
        for (int i = 0; i < s.size(); i ++){
            freq[s[i]] ++;
        }

        int maxvow = 0, maxcons = 0;
        for (auto &p : freq){
            char ch = p.first;
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                if (p.second > maxvow)  maxvow = p.second;
            }
            else if (ch >= 'a' && ch <= 'z'){
                if (p.second > maxcons) maxcons = p.second;
            }
        }

        return maxcons + maxvow;
    }
};