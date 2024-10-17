#include <iostream>
#include <stack>

using namespace std;

bool isOperator(char ch){
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int getPriority(char ch){
    if(ch == '+' || ch == '-') return 1;
    if(ch == '*' || ch == '/') return 2;
    if(ch == '(') return 3;
    if(ch == ')') return 0;
    return 0;
}

string postfixToInfix(string str){
    stack<string> stack;
    for(char i : str){
        if(isOperator(i)){
            string op1 = stack.top();
            stack.pop();
            string op2 = stack.top();
            stack.pop();
            string newString = "(" + op2 + i + op1 + ")";
            stack.push(newString);
        }
        else{
            stack.push(string(1, i));
        }
    }
    return stack.top();
}

string toPrefix(string first, string second){
    first = postfixToInfix(first);
    string str = first + second;
    string prefix;
    stack<char> stack;
    reverse(str.begin(), str.end());
    for(char i : str){
        if(isalpha(i)){
            prefix += i;
        }
        else if(i == ')') stack.push(i);
        else if(i == '('){
            while(stack.top() != ')'){
                prefix += stack.top();
                stack.pop();
            }
            stack.pop();
        }
        else if(stack.empty()) stack.push(i);
        else{
            while(!stack.empty() && getPriority(i) < getPriority(stack.top())){ 
                prefix += stack.top();
                stack.pop();
            }
            stack.push(i);
        }
    }
    while(!stack.empty()){
        prefix += stack.top();
        stack.pop();
    }
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main(){
    int n;
    
    cin >> n;

    for(int i = 0; i < n; i++){
        string strA, strB;
        cin >> strA >> strB;
        string prefix = toPrefix(strA, strB);
        cout << prefix << endl;
        
    }
    
}

