class Solution {
    int countPalindrome(string s, int left, int right){
        int cnt = 0;

        while (left >= 0 && right < s.size() && s[left] == s[right]){
            cnt ++;
            left --;
            right ++;
        }

        return cnt;
    }

public:
    int countSubstrings(string s) {
        int n = s.size();
        int cnt = 0;

        for (int i = 0; i < n; i ++){
            cnt += countPalindrome(s, i, i); // Odd lenght palindromes with the middle element s[i]
            if (i < n - 1){
                cnt += countPalindrome(s, i, i + 1); // Even length palindromes with the middle elements s[i] & s[i + 1]
            }
        }

        return cnt;
    }
};