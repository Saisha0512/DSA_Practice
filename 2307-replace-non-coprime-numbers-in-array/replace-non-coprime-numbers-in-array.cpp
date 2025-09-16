class Solution {
public:

    long long gcd(long long a, long long b){
        while(b != 0){
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    long long lcm(long long a, long long b){
        return (a / gcd(a, b)) * b;
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int i = 0; 
        stack<long long> s;
        for (auto &num : nums){
            long long curr = num;
            while (!s.empty() && gcd(s.top(), curr) > 1){
                curr = lcm(s.top(), curr);
                s.pop();
            }
            s.push(curr);
        }
        vector<int> res(s.size());
        for (int i = s.size() - 1; i >= 0; i --){
            res[i] = (int)s.top();
            s.pop();
        }
        return res;
    }
};