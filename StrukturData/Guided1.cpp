#include <iostream>
using namespace std;
int main()
{
    char op;
    float num1,num2;
    cout<<"asdasd";
    cin>>op;
    cin>>num1>>num2;

    switch (op)
    {
    case '+':
        cout<<num1+num2;
        break;
    case '-':
        cout<<num1-num2;
        break;
    case '*':
        cout<<num1*num2;
        break;
    case '/':
        cout<<num1/num2;
        break;

    default:
        cout<<"Error operator is not correct";
    }
    return 0;
}