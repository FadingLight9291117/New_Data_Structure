#include<iostream>
#include<string>
#include<list>
using namespace std;
/*C++ 迭代器遍历list*/
int main(int argc, char const *argv[])
{
    list<string> l;
    string a;
    while (true)
    {
        cin>>a;
        if (a.compare("exit") == 0)
        {
            break;
        }
        l.push_back(a);
    }
    list<string>::iterator iter = l.begin();
    while (iter != l.end())
    {
        cout<<*(iter++)<<" ";
    }
    cout<<endl;
    return 0;
}
