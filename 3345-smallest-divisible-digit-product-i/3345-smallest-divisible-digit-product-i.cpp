class Solution {
public:
int find(int n){
    int digprod=1;
    while(n!=0){
            int dig=n%10;
         digprod*=dig;
         n=n/10;
        }
        return digprod;

}
    int smallestNumber(int n, int t) {
        int temp=n;
        while(find(n)%t!=0){
            n++;
        }
        return n;
        
    }
};