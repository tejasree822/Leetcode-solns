class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int m=moves.size();
        int i=0,j=0;
        for(char c:moves){
            if(c=='L') i++;
            else if(c=='R') j++;

        }
        for(char &c:moves){
            if(i>=j &&c=='_'){
                
                c='L';
            }
            else if(i<j && c=='_'){
                c='R';
            }
        }
        int k=0;
        for(char c:moves){
         if(c=='L') k+=1;
         else k-=1;
        }
        return abs(k);

    }
};