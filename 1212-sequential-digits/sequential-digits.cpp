class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string temp = "123456789";
        vector<int> res;
        string left = to_string(low), right = to_string(high);

        for (int len = left.size(); len <= right.size(); len ++){
            for (int i = 0; i <= 9 - len; i ++){
                string n = temp.substr(i, len);
                int num = stoi(n);

                if (num >= low && num <= high){
                    res.push_back(num);
                }
            }
        }

        return res;
    }
};