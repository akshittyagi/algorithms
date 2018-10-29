#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> a = {1,2,3,4};
    vector<int>::iterator it = a.begin();
    for(int i=0;i<4;i++)
    {
        cout<< *(it+i)<<endl;
    }

    return 0;
}
