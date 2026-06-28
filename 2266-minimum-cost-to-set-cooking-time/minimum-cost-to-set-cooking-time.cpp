class Solution {
    int calcCost(int start, int move, int push, int m, int s){
        vector<int> arr(4, 0);
        // getting the buttons to be pushed
        arr[1] = m % 10;
        m /= 10;
        arr[0] = m % 10;
        arr[3] = s % 10;
        s /= 10;
        arr[2] = s % 10;

        int loop_start = 0;
        while (loop_start < 3 && arr[loop_start] == 0){
            loop_start ++;
        }
        int curr_cost = 0;
        for (int i = loop_start; i < 4; i ++){
            // if start is at current digit
            if (start == arr[i]){
                curr_cost += push;
            }
            else {
                curr_cost += (move + push);
                start = arr[i];
            }
        }
        
        return curr_cost;
    }

public:
    int minCostSetTime(int start, int move, int push, int target) {
        int min_cost = INT_MAX;
        for (int m = 0; m <= 99; m ++){
            int s = target - m * 60;
            if (s > 99 || s < 0){
                continue; // out of bound
            }

            int curr_cost = calcCost(start, move, push, m, s);
            min_cost = min(min_cost, curr_cost);
        }

        return min_cost;
    }
};