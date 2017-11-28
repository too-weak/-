#include <iostream>
#include <stack>
using namespace std;

bool whetherComp(string arr);
int main() {
    char arr[300] = "\0";
    cout << "请输入字符串：" << endl;
    cin >> arr;
    if(whetherComp(arr))
        cout<<"括号匹配"<<endl;
    else
        cout<<"括号不匹配"<<endl;
    return 0;
}

bool whetherComp(string s){
    if(s.size() % 2 != 0)
        return false;
    if(s.size() == 0){
        return true;
    }
    stack<char> chars;
    for(char c:  s){
        if(c == '(' || c == '{' || c == '[')
            chars.push(c);
        else{
            if(chars.empty())
                return false;
            char top = chars.top();
            if(c ==  ')'){
                if(top == '(')
                    chars.pop();
            }
            else if( c == '}'){
                if(top == '{')
                    chars.pop();
            }
            else if( c == ']'){
                if(top == '[')
                    chars.pop();
            }
            else{
            }
        }
    }
    return chars.size() == 0;
}