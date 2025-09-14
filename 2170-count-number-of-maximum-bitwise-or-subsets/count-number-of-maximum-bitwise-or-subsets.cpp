class Solution {
public:
    void calculateMaxOr(vector<int> &nums, int i, int &maxor, int curror, int &cnt){
        // Base Case : 
        if (i >= nums.size()){
            return;
        }

        // Recursive Case : 
        // Case 1 : Not considering the current element : 
        calculateMaxOr(nums, i + 1, maxor, curror, cnt);

        // Case 2 : Considering the current element : 
        curror = curror | nums[i];
        if (maxor == curror){
            cnt ++;
        }
        else if (curror > maxor){
            maxor = curror;
            cnt = 1;
        }
        calculateMaxOr(nums, i + 1, maxor, curror, cnt);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxor = 0, curror = 0, cnt = 0;
        calculateMaxOr(nums, 0, maxor, curror, cnt);
        return cnt;
    }
};