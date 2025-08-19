class Solution {
public:
    bool checkValidString(string s) {
        int len = s.size() - 1;
        int open = 0, close = 0;
        for (int i = 0; i < s.size(); i ++){
            if (s[i] == '(' || s[i] == '*'){
                open ++;
            }
            else {
                open --;
            }

            if (s[len - i] == ')' || s[len - i] == '*'){
                close ++;
            }
            else {
                close --;
            }

            if (open < 0 || close < 0){
                return false;
            }
        }
        return true;
    
    }
};