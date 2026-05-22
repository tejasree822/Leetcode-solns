class Solution {
public:
long long mod=1e9+7;
long long pow(long long x,long long n){
    if(n==0) return 1;
    long long ans=1;
    while(n>0){
    if(n%2==0) {
        x=(x*x)%mod;
        n=(n/2);
    }
    else{
      ans=(ans*x)%mod;
      n--;
    }
    }
    return ans;
}
    int countGoodNumbers(long long n) {
       
        long long even=(n+1)/2;
        long long odd=n/2;
       
        
        return (pow(5,even)*pow(4,odd))%mod;
    }
};