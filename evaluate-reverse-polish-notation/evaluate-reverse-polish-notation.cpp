class Solution {
public:
    int evaloperation(int a , int b , string& op) {
                
                if(op == "+")
                    return  a + b;
                else if(op == "-")
                     return a - b ;
                else if(op == "*")
                     return a*b;
            
                return a/b ;
    }
    
    int evalRPN(vector<string>& tokens) {
        
           stack<int> s;
        
             for(int i = 0 ; i < tokens.size() ; i++ ) {
            
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
               int  b = s.top();
                s.pop();
               int  a =  s.top();
                s.pop();
                
               int res = evaloperation(a , b , tokens[i]);
                  
                s.push(res);
                
            }
            else 
            {
                s.push(stoi(tokens[i]));
            } 
        }
        
      return s.top();
        
    }
};