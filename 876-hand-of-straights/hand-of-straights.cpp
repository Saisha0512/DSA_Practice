class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        int n = hand.size();
        if (n % k != 0){
            return false;
        }

        unordered_map<int, int> freq;
        for (auto num : hand){
            freq[num] ++;
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto &[card, count] : freq){
            pq.push(card);
        }

        while (!pq.empty()){
            int start = pq.top();

            for (int card = start; card <= start + k - 1; card ++){
                if (freq.find(card) == freq.end() || freq[card] == 0){
                    return false;
                }

                freq[card] --;

                if (freq[card] == 0 && pq.top() == card){
                    pq.pop();
                }
            }
        }

        return true;
    }
};