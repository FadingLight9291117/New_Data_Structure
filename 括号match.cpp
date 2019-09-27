/*括号匹配*/
#include<iostream>
#include<list>
#include<string>
bool test(std::string a)
{
    std::list<char>* stack = new std::list<char>();
    for (int i = 0; i < a.length(); i++)
    {
        switch (a[i])
        {
            case '(':
            case '[':
            case '{':
                stack->push_back(a[i]);
                break;
            case ')':
                if (stack->back() == '(')
                {
                    stack->pop_back();
                    break;
                }
                else
                {
                    return false;
                }
                
            case ']':
                if (stack->back() == '[')
                {
                    stack->pop_back();
                    break;
                }
                else
                {
                    return false;
                }
            case '}':
                if (stack->back() == '{')
                {
                    stack->pop_back();
                    break;
                }
                else
                {
                    return false;
                }
            default:
                break;
        }
    } 
    if (stack->size())
    {
        return false;
    }
    return true;
}

int main()
{
    std::string str;
    std::cout<<"请输入: ";
    getline(std::cin, str);
    bool b = test(str);
    if (b)
    {
        std::cout<<"匹配成功"<<std::endl;
    }
    else
    {
        std::cout<<"匹配失败"<<std::endl;
    }
    return  0;
}