class Solution {
public:
bool isvowel(char c){
    c=tolower(c);
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}
    string reverseVowels(string& s) {
      int l=0;
      int r=s.size()-1;
     while(l<r){
        if(isvowel(s[l]) && isvowel(s[r])){
          
        char temp=s[l];
        s[l]=s[r];
        s[r]=temp;
        l++;
        r--;
     }
        if( !isvowel(s[l])) l++;
        if(!isvowel(s[r])) r--;
     
      }
      return s;

    }
};