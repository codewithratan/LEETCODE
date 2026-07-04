class Solution {
public:
    int countPrimes(int n) {
        if(n == 0) return 0 ;
        vector<bool>isPrime(n , true);
        int count = 0 ;
        isPrime[0] = false ;
        isPrime[1] = false ;
        for(int i = 0 ; i < n ; i++){
            if(isPrime[i]){ 
                count++;
                int k = 2 ;
                int j = i * k ;
                while(j < n){
                    isPrime[j] = false ;
                    j = j + i ;
                }
            }
        }
        return count ;
    }
};