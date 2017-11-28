#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int > sta;
    int ten = 0;
    int hex = 0;
    int reminder = 0;
    int result = 0;
    cout<<"请输入十进制数："<<endl;
    cin>>ten;
    cout<<"请输入要转换的进制，范围为2~9：";
    cin>>hex;
    while(hex < 2 || hex > 9){
        cout<<"请输入2~9之间的进制："<<endl;
        cin>>hex;
    }
    if(ten == 0){
        cout<<"0";
    } else {
        while (ten != 0) {
            reminder = ten % hex;
            sta.push(reminder);
            ten /= hex;
        }
        while (!sta.empty()) {
            result = sta.top();
            cout << result << "";
            sta.pop();
        }
    }
//    } else {
//
//    }
    return 0;
}