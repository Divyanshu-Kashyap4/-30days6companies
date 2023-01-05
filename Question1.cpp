class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>q;
        set<string>s;
        s.insert("+");
        s.insert("-");
        s.insert("*");
        s.insert("/");
        for(int i=0;i<tokens.size();i++)
        {
            if(s.count(tokens[i])==0)q.push(stoi(tokens[i]));
            else
            {
                int b=q.top();
                q.pop();
                int a=q.top();
                q.pop();
            if(tokens[i]=="+")
            {
                q.push(a+b);   
            }
            else if(tokens[i]=="-")
            {
                q.push(a-b);                  
            }
            else if(tokens[i]=="*")
            {
                q.push(a*b);                 
            }
            else 
            {
                q.push(a/b);                   
            }
            }
        }
        return q.top();
    }
};