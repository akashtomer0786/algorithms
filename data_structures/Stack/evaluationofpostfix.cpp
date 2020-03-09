class Solution {
public:
    bool isoperator(string s){
        return (s=="+"||s=="*"||s=="-"||s=="/");
    }
    int compute(int a,int b,string s){
        if(s=="+")return a+b;
        if(s=="-")return a-b;
        if(s=="/")return a/b;
        if(s=="*")return a*b;
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        if(tokens.size()==0)return 0;
        stack<string>st;
        int n = tokens.size();
        for(int i=0;i<n;i++){
            if(!isoperator(tokens[i]))st.push(tokens[i]);
            else{
                int val1 = stoi(st.top());
                st.pop();
                int val2 = stoi(st.top());
                st.pop();
                int res = compute(val2,val1,tokens[i]);
                st.push(to_string(res));
            }
        }
        return stoi(st.top());
    }
};
