class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for(char ch:expression){
            if(ch==',') continue;
            if(ch!=')'){
                st.push(ch);
            }
            else{
                int tc=0,fc=0;
                while(!st.empty() && st.top()!='('){
                    if(st.top()=='t') tc++;
                    else if(st.top()=='f') fc++;
                    st.pop();
                }
                st.pop();
                char result;
            if(st.top()=='!')
                {
                    if(tc>0)  result='f';
                    else result= 't';
                }
                else if(st.top()=='&'){
                    if(fc>0) result= 'f';
                    else result= 't';
                }
                else{
                    if(tc>0) result= 't';
                    else result='f';
                }
                st.pop();
                st.push(result);
            }
            }
            return st.top()=='t';
        
    }
};