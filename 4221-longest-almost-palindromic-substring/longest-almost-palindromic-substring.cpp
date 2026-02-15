class Solution {
    bool isPalindrome(string &s, int l, int r){
        while (l <= r){
            if (s[l] == s[r]){
                l ++;
                r --;
            }
            else {
                return false;
            }
        }

        return true;
    }
    
    bool check(string &s, int l, int r){
        while (l < r){
            if (s[l] == s[r]){
                l ++;
                r --;
            }
            else {
                // Trying to remove the character at l or at r : 
                return (isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1));
            }
        }

        return true;
    }
    
public:
    int almostPalindromic(string s) {
        int n = s.size();

        int maxlen = 0;
        for (int i = 0; i < n; i ++){
            for (int j = i; j < n; j ++){
                if (j - i + 1 <= maxlen){
                    continue;
                }

                if (check(s, i, j)){
                    maxlen = j - i + 1;
                }
            }
        }

        return maxlen;
    }
};