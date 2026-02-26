class Solution {
    void add(string &s){
        int n = s.size();
        int carry = 1;
        for (int i = n - 1; i >= 0; i --){
            int dig = s[i] - '0';
            int sum = carry + dig;
            s[i] = (sum % 2) + '0';
            carry = sum / 2;
        }

        if (carry){
            s = '1' + s;
        }
    }

public:
    int numSteps(string s) {
        int cnt = 0;
        while (s != "1"){
            if (s.back() == '0'){
                s.pop_back();
            }
            else {
                add(s);
            }

            cnt ++;
        }

        return cnt;
    }
};