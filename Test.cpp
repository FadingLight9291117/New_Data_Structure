/*括号匹配*/
#include<iostream>
#include<list>
#include<string>
bool test(std::string a, int n)
{
    std::list<char>* stack = new std::list<char>();
    for (int i = 0; i < n; i++)
    {
        switch (a[i])
        {
        case '(':
        case '[':
        case '{':
                stack->push_back(a[i]); 
                break;
        case ')':
        case ']':
        case '}':
                char c = stack->back();
                stack->pop_back();
                if (c == a[i])
                    break;
                else return false;
        default:
                break;
        }
        return true;
    }
} 
int main()
{
    std::string str;
    std::cin>>str;
    bool b = test(str, str.length);
    printf("%d\n", b);
    return 0;
}