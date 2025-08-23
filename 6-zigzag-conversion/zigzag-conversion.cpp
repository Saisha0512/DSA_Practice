class Solution {
public:
    string convert(string s, int num) {
        if(num == 1 || num >= s.size()){
            return s;
        }

        vector<string> rows(num);
        int curr = 0;
        bool down = false;
        for (char c : s){
            rows[curr] += c;
            if (curr == 0 || curr == num - 1){
                down = !down;
            }

            if (down){
                curr ++;
            }
            else {
                curr --;
            }
        }
        string res;
        for (string &row : rows){
            res += row;
        }
        return res;
    }
};