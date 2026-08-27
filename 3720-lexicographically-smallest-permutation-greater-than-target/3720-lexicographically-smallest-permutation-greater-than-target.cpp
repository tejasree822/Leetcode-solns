class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> hash(26,0);
        string k="";
        int m=s.size();
        int p=0;

        for(int i=0;i<s.size();i++)
            hash[s[i]-'a']++;

        for(int i=0;i<m;i++){
            if(hash[target[i]-'a']!=0 && p==0){
                k+=target[i];
                hash[target[i]-'a']--;
            }
            else{
                if(p==0){
                    int l=target[i]-'a';
                    while(l<26 && hash[l]==0)
                        l++;

                    if(l<26){
                        k+=char('a'+l);
                        hash[l]--;
                        p=1;
                    }
                    else{
                        for(int j=i-1;j>=0;j--){
                            hash[k[j]-'a']++;
                            int x=target[j]-'a';
                            int l=x+1;

                            while(l<26 && hash[l]==0)
                                l++;

                            if(l<26){
                                k=k.substr(0,j);
                                k+=char('a'+l);
                                hash[l]--;

                                for(int z=0;z<26;z++){
                                    while(hash[z]>0){
                                        k+=char('a'+z);
                                        hash[z]--;
                                    }
                                }
                                return k;
                            }
                        }
                        return "";
                    }
                }
            }
        }

        if(p==0){
            for(int j=m-1;j>=0;j--){
                hash[target[j]-'a']++;
                int x=target[j]-'a';
                int l=x+1;

                while(l<26 && hash[l]==0)
                    l++;

                if(l<26){
                    k=k.substr(0,j);
                    k+=char('a'+l);
                    hash[l]--;

                    for(int z=0;z<26;z++){
                        while(hash[z]>0){
                            k+=char('a'+z);
                            hash[z]--;
                        }
                    }
                    return k;
                }
            }
            return "";
        }

        for(int i=0;i<26;i++){
            while(hash[i]!=0){
                k+=char(i+'a');
                hash[i]--;
            }
        }

        return k;
    }
};