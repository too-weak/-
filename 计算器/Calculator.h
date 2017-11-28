//
// Created by Wang wei on 2017/10/1.
//

#ifndef WEEK_6_CALCULATOR_H
#define WEEK_6_CALCULATOR_H

#include <iostream>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

class Calculator {
public:
    double calculator();
private:
    string infixToSuffinx(string InfixExp);
    double calSuffix(string PostfixExp);
    int comparePriority(char in, char suf);
    int priority(char op, int inOrSuf);
    bool whetherComp(string arr);
};


#endif //WEEK_6_CALCULATOR_H
