class Solution {
public:
    char processStr(string s, long long k) {
        int n=s.size();
        vector<long long> track_lengths(n,0);
        long long current_len=0;
        for(int i=0;i<n;i++){
            if(islower(s[i])){
                current_len++;
            }else if(s[i]=='*'){
                if(current_len>0)current_len--;
            }else if(s[i]=='#'){
                current_len*=2;
            }else if(s[i]=='%'){
                current_len=current_len; 
            }
            track_lengths[i]=current_len;
        }
        if(k<0||k>=current_len){
            return '.';
        }
        for(int i=n-1;i>=0;i--){
            long long prev_len=(i==0)?0:track_lengths[i-1];
            if(islower(s[i])){
                if(k==prev_len){
                    return s[i];
                }
            }else if(s[i]=='#'){
                if(k>=prev_len){
                    k-=prev_len;
                }
            }else if(s[i]=='%'){
                k=current_len-1-k;
            }
            current_len=prev_len;
        }
        return '.';
    }
};