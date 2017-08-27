#include <stack>

bool isNum(string input)
{
    string temp = input;
    for(int i=0;i<temp.length();i++)
    {
        if(temp[i]>='0' and temp[i]<='9')
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
  public:
    bool isEmpty();
    void operate(char input);
}

bool StackMachine::isEmpty()
{
    return mStack.empty();
}

void StackMachine::operate(string input)
{
    if(isNum(input))
        mStack.push(input);
    else if(input=="+" or input=="-" or input=="/" or input=="*")
    {
        int b = mStack.top();
        mStack.pop();
        int a = mStack.top();
        mStack.pop();
        if(input=="+")
            mStack.push(a+b);
        else if(input=="-")
            mStack.push(a-b);
        else if(input=="*")
            mStack.push(a*b);
        else if(input=="/")
            mStack.push(a/b);
    }
    else
        return;
}

