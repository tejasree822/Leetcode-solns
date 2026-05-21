class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int m=arr1.size();
        int n=arr2.size();
        unordered_set<int> a;
        for(int i=0;i<m;i++){
            while(arr1[i]!=0){
                a.insert(arr1[i]);
                arr1[i]/=10;
            }
        }
        unordered_set<int> b;
        for(int i=0;i<n;i++){
            while(arr2[i]!=0){
                b.insert(arr2[i]);
                arr2[i]/=10;
            }
        }
int max_prefix=0;
        for(auto it:a){
            if(b.find(it)!=b.end()){
                int prefix=it;
                max_prefix=max(max_prefix,prefix);
            }
        }
        int count=0;
        while(max_prefix!=0){
            max_prefix/=10;
            count++;
        }
        return count;
    }
};