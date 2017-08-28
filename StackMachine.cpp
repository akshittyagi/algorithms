#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isNum(string input)
{
    string temp = input;
    for (int i = 0; i < temp.length(); i++)
    {
        if (temp[i] >= '0' and temp[i] <= '9')
            continue;
        else
            return false;
    }
    return true;
}
class StackMachine
{
  private:
    stack<int> mStack;
    int result;

  public:
    bool isEmpty();
    void operate(string input);
    int getResult();
};

bool
StackMachine::isEmpty()
{
    return mStack.empty();
}
int StackMachine::getResult()
{
    return result;
}
void StackMachine::operate(string input)
{
    if (isNum(input))
    {
        mStack.push(stoi(input));
        return;
    }
    else if (input == "+" or input == "-" or input == "/" or input == "*")
    {
        int b = mStack.top();
        mStack.pop();
        int a = mStack.top();
        mStack.pop();
        if (input == "+")
            mStack.push(a + b);
        else if (input == "-")
            mStack.push(a - b);
        else if (input == "*")
            mStack.push(a * b);
        else if (input == "/")
            mStack.push(a / b);
        return;
    }
    else if (input == "ESC")
    {
        int ret = mStack.top();
        mStack.pop();
        result = ret;
        return;
    }
    else
        return;
}

int main()
{
    StackMachine sm;
    sm.operate("43");
    sm.operate("2");
    sm.operate("*");
    sm.operate("INVALID CHAR");
    sm.operate("8");
    sm.operate("-");
    sm.operate("7");
    sm.operate("/");
    sm.operate("ESC");
    cout << sm.getResult() << endl;
    return 0;
}