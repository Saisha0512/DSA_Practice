class Solution {
    const int mod = 1e9 + 7;
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> left(n), right(n);
        stack<int> s;
        // left[i] = number of subarrays that extend to the left with the min elements as arr[i]
        // right[i] = number of subarrays that extend to the right with the min element as arr[i]
        
        // calculating for the previous smaller elements and storing the result in left
        for (int i = 0; i < n; i ++){
            // popping the elements that are greater than the current element
            while (!s.empty() && arr[s.top()] > arr[i]){
                s.pop();
            }

            left[i] = s.empty()? i + 1 : i - s.top();
            s.push(i);
        }

        // emptying the current stack
        while (!s.empty()){
            s.pop();
        }

        // calculating for the next smaller elements and storing the result in right
        for (int i = n - 1; i >= 0; i --){
            // popping the elements that are greater than the current element
            while (!s.empty() && arr[s.top()] >= arr[i]){
                s.pop();
            }

            right[i] = s.empty()? n - i : s.top() - i;
            s.push(i);
        }

        // calculating the sum
        int sum = 0;
        for (int i = 0; i < n; i ++){
            // mapping each of the left extendable subarray to the right extendable subarrays
            sum = (sum + 1LL * arr[i] * left[i] * right[i]) % mod;
        }

        return sum;
    }
};