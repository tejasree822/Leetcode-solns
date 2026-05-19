class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int count=0;
        int m=s.size();
        int n=goal.size();
        if(m!=n) return false;
        vector<int>hash(26,0);
        if(s==goal){
          for(char c:s){
            hash[c-97]++;
          }
          for(int i=0;i<26;i++){
         if(hash[i]>1) return true;
          }
          return false;
 }
        for(int i=0;i<m;i++){
            if(s[i]!=goal[i]){ count++;
            }
        }vector<int>sa;
        vector<int>g;
       
        if(count!=2) return false;
        if(count==2) {
            for(int i=0;i<m;i++){
                if(s[i]!=goal[i]){
                    sa.push_back(s[i]);
                    g.push_back(goal[i]);
                }
            }
          
            
        }
        return sa[0]==g[1]&&sa[1]==g[0];
        
    }
};