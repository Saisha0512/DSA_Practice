class Solution {
    void addString(int n, string &s, int &k, string &res){
        // Base Case : 
        if (n == 0){
            k --;
            if (k == 0){
                res = s;
            }
            return;
        }

        // Recursive Case : 
        char prev;
        if (s.size() != 0){
            prev = s.back();
        }
        else {
            prev = ' ';
        }

        for (char ch = 'a'; ch <= 'c'; ch ++){
            if (ch != prev){
                s.push_back(ch);
                addString(n - 1, s, k, res);
                s.pop_back();
                if (k == 0){
                    return;
                }
            }
        }
    }

public:
    string getHappyString(int n, int k) {
        string res = "";
        string temp = "";
        addString(n, temp, k, res);

        return res;
    }
};