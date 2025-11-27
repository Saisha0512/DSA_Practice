class Solution {
public:
    string largestOddNumber(string num) {
        int i = num.size() - 1;
        while (num.size() > 0){
            int dig = num[i] - '0';
            if (dig % 2 == 0){ // Even digit
                num.pop_back();
                i = num.size() - 1;
            }
            else {
                break;
            }
        }

        return num;
    }
};