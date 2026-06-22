class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> f(5, 0);
        string res = "balon";

        for (char ch : text){
            for (int i = 0; i < 5; i ++){
                f[i] += ((ch == res[i])? 1 : 0);
            }
        }

        return min({f[0], f[1], f[2]/2, f[3]/2, f[4]});
    }
};