class Solution {
public:
    int maxBottlesDrunk(int num, int exch) {
        int drink = 0, full = num, empty = 0;
        while (full > 0){
            // Drinking all the full bottles : 
            drink += full;
            empty += full;
            full = 0;
            
            // Exchanging a slot of empty bottle to get 1 full bottle & increase exch by 1 :
            while (empty >= exch){
                empty -= exch;
                full ++;
                exch ++;
            }
        }
        return drink;
    }
};