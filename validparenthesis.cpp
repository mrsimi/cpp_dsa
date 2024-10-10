#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isvalid(string s){
    stack<char> stack;
    unordered_map<char, char> parenthesis = {
        {'{', '}'},
        {'[', ']'},
        {'(', ')'}
    };

    for(char c: s){
        if(parenthesis.find(c) != parenthesis.end()){
            stack.push(c);
        }else{
            if(stack.empty()){
                return false;
            }else{
                char top = stack.top();
                if(parenthesis[top] != c){
                    return false;
                }
                stack.pop();
            }
        }
    }
    return stack.empty();
}
int main(){
    string s = "[";
    bool isvalidParenthesis = isvalid(s);
    cout << isvalidParenthesis;
    return 0;
}