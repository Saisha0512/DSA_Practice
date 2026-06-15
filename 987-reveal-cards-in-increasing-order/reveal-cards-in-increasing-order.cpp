class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();

        // sorting 
        sort(deck.begin(), deck.end());
        
        vector<int> res(n, 0);
        // queue of indices
        queue<int> q; 
        for (int i = 0; i < n; i ++){
            q.push(i);
        }

        // we simulate this logic on the queue & then place the elements in the sorted order on the indices that appear in this simulation
        int i = 0; // pointer to the sorted array
        while (!q.empty()){
            // place the currently pointed element at the front index of the queue
            res[q.front()] = deck[i];
            q.pop();
            i ++;
            // since this index of the result vector is already assigned an element, we dont need to push it again at the back

            // then push the next top most index to the back of the queue
            if (q.size() >= 1){
                q.push(q.front());
                q.pop();
            }
        }

        return res;
    }
};