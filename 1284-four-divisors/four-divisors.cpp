class Solution {
private : 
    int factors(int n){
        int sum = 0, cnt = 0;
        for (int i = 2; i * i <= n; i ++){
            if (n % i == 0){
                int j = n / i;
                if (j == i || cnt > 0){
                    return 0;
                }
                sum += i + j;
                cnt ++;
            }
        }

        if (cnt == 0){
            return 0;
        }
        return sum + 1 + n;
    }

public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        
        int sum = 0;
        for (int i = 0; i < n; i ++){
            sum += factors(nums[i]);
        }

        return sum;
    }
};