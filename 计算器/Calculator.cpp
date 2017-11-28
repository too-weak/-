//
// Created by Wang wei on 2017/10/1.
//

#include "Calculator.h"

double Calculator::calculator() {
    string inFixStr, sufFixStr;
    double result;
    cout<<"请输入要计算的表达式:";
    cin>>inFixStr;
    sufFixStr = infixToSuffinx(inFixStr);
    cout<<"中缀表达式："<<sufFixStr<<endl;
//    if(!whetherComp(sufFixStr)){
//        cout<<"括号不匹配"<<endl;
//        return 1;
//    }
    result = calSuffix(sufFixStr);
    cout<<"结果是："<<result<<endl;
    return 0;
}

string Calculator::infixToSuffinx(string InfixExp) {
    int length = int(InfixExp.length());
    string result;
    stack<char> operators;
    operators.push('#');
    for(int i = 0; i < length; ++i){
        if((InfixExp[i] >= '0' && InfixExp[i] <= '9') ||
                InfixExp[i] == '.' ||
                InfixExp[i] == '-'){
            result += InfixExp[i];
        } else if (InfixExp[i] == '+' ||
                InfixExp[i] == '-' ||
                InfixExp[i] == '*' ||
                InfixExp[i] == '/'){
            result += ' ';
            int comp = comparePriority(operators.top(), InfixExp[i]);
            if(comp == 1){
                result += operators.top();
                operators.pop();
                while(comparePriority(operators.top(), InfixExp[i]) == 1){
                    result += operators.top();
                    operators.pop();
                }
                if(!operators.empty() && comparePriority(operators.top(), InfixExp[i]) == 0)
                    operators.pop();
                if(!operators.empty() && comparePriority(operators.top(), InfixExp[i]) == -1)
                    operators.push(InfixExp[i]);
            } else if(comp == 0)
                operators.pop();
            else
                operators.push(InfixExp[i]);
        }
    }
    return result;
}

//string Calculator::infixToSuffinx(string InfixExp) {
//    int length = int(InfixExp.length());
//    string result;
//    stack<char>  operators;
//    operators.push('#');                    //用#作为开头或者说栈底开始对中缀的遍历
//    for(int i = 0; i < length; ++i){
//        //如果该字符是数字的一部分，储存到result中直到得到一个完整的运算数
//        if((InfixExp[i] >= '0' && InfixExp[i] <= '9' ) ||
//           InfixExp[i] == '.' ||
//           InfixExp[i] == '-'){
//            result += InfixExp[i];
//        } else if (InfixExp[i] == '+' ||
//                   InfixExp[i] == '-' ||
//                   InfixExp[i] == '*' ||
//                   InfixExp[i] == '/'){
//            //如果是运算符，就标志着一个运算数的结束，用空格将每个运算数和其他东西都分隔开
//            result += ' ';
//            int comp = comparePriority(operators.top(), InfixExp[i]);
//            if(comp == 1){
//                result += operators.top();
//                operators.pop();
//                while(comparePriority(operators.top(), InfixExp[i]) == 1){
//                    result += operators.top();
//                    operators.pop();
//                }
//                if(!operators.empty()&&comparePriority(operators.top(), InfixExp[i]) == 0)
//                    operators.pop();
//                if(!operators.empty()&&comparePriority(operators.top(), InfixExp[i]) == -1)
//                    operators.push(InfixExp[i]);
//            } else if(comp == 0){
//                operators.pop();
//            } else {
//                operators.push(InfixExp[i]);
//            }
//        }
//    }
//    return result;
//}

double Calculator::calSuffix(string PostfixExp) {
    stack<char> resultSta;
    stack<double> sta;
    string tempSta;
    char temp;
    double x, y, result = 0;
    for(int i = 0; i < int(PostfixExp.length()); ++i){
        temp = PostfixExp[i];
        if((temp >= '0' && temp <= '9') ||
                temp == '.' ||
                temp == '-'){
            //是操作数，还是暂存起来
            tempSta += temp;
        } else if(temp == ' ') {
            //是空格，并且操作数不为空，就将操作数转为double存到栈中
            if (!tempSta.empty()) {
                sta.push(strtod(tempSta.c_str(), NULL));
                tempSta.clear();
            }
        } else {
            //是运算符，就进行运算
            y = sta.top();
            sta.pop();
            x = sta.top();
            sta.pop();
            switch (temp){
                case '+':
                    result = x + y;
                    break;
                case '-':
                    result = x - y;
                    break;
                case '*':
                    result = x * y;
                    break;
                case '/':
                    result = x / y;
                    break;
                default:
                    cout<<"出现非法字符"<<endl;
                    return -1;
            }
            sta.push(result);
        }
    }
    return sta.top();
}

int Calculator::comparePriority(char in, char suf) {
    int intIn = priority(in, 1), intSuf = priority(suf, 0);
    if(intIn > intSuf)
        return 1;
    else if(intIn == intSuf)
        return 0;
    else
        return -1;
}

int Calculator::priority(char op, int inOrSuf) {
    if(op == '#')
        return 0;
    if(inOrSuf){
        switch (op){
            case '(':
                return 1;
            case '^':
                return 7;
            case '*':
            case '/':
            case '%':
                return 5;
            case '+':
            case '-':
                return 3;
            case ')':
                return 8;
            default:
                return -1;
        }
    } else {
        switch (op){
            case '(':
                return 8;
            case '^':
                return 6;
            case '*':
            case '/':
            case '%':
                return 4;
            case '+':
            case '-':
                return 2;
            case ')':
                return 1;
            default:
                return -1;
        }
    }
}

bool Calculator::whetherComp(string arr) {
    stack<int> sta;
    int index = 0;
    for (int i = 0; arr[i] != '\0'; ++i) {
        if (arr[i] == '(' ||
                arr[i] == '[' ||
                arr[i] == '{') {
            //左边的括号入栈
            sta.push(i);
        } else if (arr[i] == ')' ||
                arr[i] == ']' ||
                arr[i] == '}') {
            //右边的括号就与栈内的下标比较
            if(sta.empty())
                return false;
            index = sta.top();
            switch (arr[index]) {
                case '(':
                    if (arr[i] == ')')
                        sta.pop();
                    else {
                        return false;
                    }
                    break;
                case '[':
                    if (arr[i] == ']')
                        sta.pop();
                    else {
                        return false;
                    }
                    break;
                case '{':
                    if (arr[i] == '}')
                        sta.pop();
                    else {
                        return false;
                    }
                    break;
            }
        }
    }
    return sta.empty();
}
