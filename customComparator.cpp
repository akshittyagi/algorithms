#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct Obj{
    int val;
    string name;    
};

struct Comparator{
    bool operator() (const Obj &a, const Obj &b)
    {
        return a.val > b.val;
    }
};

int main()
{
    priority_queue<Obj, vector<Obj>, Comparator> pq;
    Obj a;
    a.val = 5;
    a.name = "A";
    Obj b;
    b.val = 6;
    b.name = "B";
    Obj c;
    c.val = 1;
    c.name = "C";
    Obj d;
    d.val = 0;
    d.name = "D";
    vector<Obj> vec = {a,b,c,d};
    
    pq.push(a);
    pq.push(b);
    pq.push(c);
    pq.push(d);

    sort(vec.begin(), vec.end(), Comparator());

    for( auto &it: vec )
    {
        cout<<it.val<<" "<<it.name<<endl;
        cout<<"PQ "<<pq.top().val<<" "<<pq.top().name<<endl;
        pq.pop();
    }

    return 0;
}