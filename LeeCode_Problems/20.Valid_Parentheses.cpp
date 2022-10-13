
// Time Complexity: O(n);
//Space Complexity: O(n) //auxiliary space
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        int i=0;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            
            if(ch=='(' || ch=='{' || ch=='['){
                stk.push(ch);
            }
            else{
                if(ch==')'){
                    if(stk.empty() || stk.top()!='('){
                        return false;
                    }
                    else{
                        stk.pop();
                    }
                }
                 else if(ch=='}'){
                    if(stk.empty() || stk.top()!='{'){
                        return false;
                    }
                    else{
                        stk.pop();
                    }
                }
                 else{
                    if(stk.empty() || stk.top()!='['){
                        return false;
                    }
                    else{
                        stk.pop();
                    }
                }
               
            }
            
        }
        return stk.empty();
    }
};