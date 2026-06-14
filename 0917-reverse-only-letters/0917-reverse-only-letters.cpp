class Solution {
public:
    string reverseOnlyLetters(string& s) {
        int l=0;
        int r=s.size();
        while(l<r){
            if(isalpha(s[l]) && isalpha(s[r])){
                char temp=s[l];
                s[l]=s[r];
                s[r]=temp;
                l++;
                r--;
            }
            if(!isalpha(s[l])) l++;
            if(!isalpha(s[r])) r--;
        }
        return s;

    }
};