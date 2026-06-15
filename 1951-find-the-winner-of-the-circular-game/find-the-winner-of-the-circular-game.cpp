class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;

        // pushing all the elements in the queue
        for (int i = 1; i <= n; i ++){
            q.push(i);
        }

        // iterate over the elements till the size > 1
        int j = k;
        while (q.size() > 1){
            // pop & reset
            if (j == 1){
                q.pop();
                j = k;
                continue;
            }

            // otherwise, move the front element to the back of the queue
            q.push(q.front());
            q.pop();
            j --;
        }

        return q.front();
    }
};