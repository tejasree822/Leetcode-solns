class Solution {
public:
    void reverseArray(string& a,int start,int end){
        while(start<end){
            int temp=a[start];
            a[start]=a[end];
            a[end]=temp;
            start++;
            end--;
        }
    }
    bool rotateString(string s, string goal) {
        int m=s.size();
        int n=goal.size();
        if(m!=n) return false;
        for(int k=0;k<m;k++){
            string temp=goal;
         reverseArray(temp,0,n-1);
         reverseArray(temp,0,k-1);
         reverseArray(temp,k,n-1);
         if(temp==s) return true;
        }
    
        return false;
    }
};