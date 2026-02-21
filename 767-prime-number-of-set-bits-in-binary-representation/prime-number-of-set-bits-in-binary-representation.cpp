class Solution {
    bool isPrime(int num){
        if (num <= 1){
            return false;
        }

        for (int i = 2; i * i <= num; i ++){
            if (num % i == 0){
                return false;
            }
        }

        return true;
    }

    bool check(int num){
        int cnt = 0;
        while (num){
            if (num & 1){
                cnt ++;
            }

            num >>= 1;
        }

        if (isPrime(cnt)){
            return true;
        }

        return false;
    }

public:
    int countPrimeSetBits(int left, int right) {
        int cnt = 0;
        for (int i = left; i <= right; i ++){
            if (check(i)){
                cnt ++;
            }
        }

        return cnt;
    }
};