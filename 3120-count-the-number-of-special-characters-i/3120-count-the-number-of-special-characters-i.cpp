class Solution {
public:
    int numberOfSpecialChars(string word) {
        int m=word.size();
        vector<int> hash1(26,0);
        vector<int> hash2(26,0);
        for(int i=0;i<m;i++){
            if(isupper(word[i])){
                 hash1[word[i]-65]++;
            }
            else if(islower(word[i])){
                hash2[word[i]-97]++;
            }
        }
        int count=0;

        for(int i=0;i<26;i++){
            if(hash1[i]!=0 &&hash2[i]!=0){
                count++;
            }
        }
        return count;
    }
};