class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        int i=0,j=0;
        string result="";
        while(i<m && j<n){
        
           if(i==j){
            result+=word1[i];
              i++;
           }
           else if(i>j){
            result+=word2[j];
            j++;


           }
        
        }
        if(m<=n){
            for(int i=m-1;i<n;i++){
                result+=word2[i];
            }
        }
        else if(m>n){
            for(int i=n;i<m;i++){
                result+=word1[i];
            }
        }
        return result;
    }
};