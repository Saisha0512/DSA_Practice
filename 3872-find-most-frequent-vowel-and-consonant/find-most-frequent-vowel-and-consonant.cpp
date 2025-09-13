class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> arr(26, 0);
        for (int i = 0; i < s.size(); i ++){
            arr[s[i] - 'a'] ++;
        }

        int maxvow = 0, maxcons = 0;
        for (int i = 0; i < 26; i ++){
            char ch = 'a' + i;
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                maxvow = max(maxvow, arr[i]);
            }
            else {
                maxcons = max(maxcons, arr[i]);
            }
        }
        return maxvow + maxcons;
    }
};