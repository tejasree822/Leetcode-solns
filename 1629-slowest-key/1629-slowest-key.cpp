class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int hash[26]={0};
        int temp[releaseTimes.size()];
        hash[keysPressed[0]-'a']=releaseTimes[0];
        for(int i=1;i<releaseTimes.size();i++){
            //temp[i]=releaseTimes[i]-releaseTimes[i-1];
            hash[keysPressed[i]-'a']=max(hash[keysPressed[i]-'a'],releaseTimes[i]-releaseTimes[i-1]);
        }
        int maxi=25;
        for(int i=25;i>=0;i--){
            if(hash[i]>hash[maxi]){
                maxi=i;
            }
        }
        char c=char(maxi+'a');
        
        return c;
       
    }
};