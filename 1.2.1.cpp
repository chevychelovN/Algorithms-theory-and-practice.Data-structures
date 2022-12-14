// Расстановка скобок в коде

#include <iostream>
#include <stack>
#include <string>

int main() {
    std::stack<char> stack;
    std::stack<int> stack2;
    std::string str;
    char top;
    std::cin >> str;
    bool flag = true;
    int i;
    for(i = 0; i < str.length(); i++)
    {
        if(str[i] == '(' or
           str[i] == ')' or 
           str[i] == '[' or 
           str[i] == ']' or 
           str[i] == '{' or 
           str[i] == '}')
        {
        
        if(str[i] == '(' or str[i] == '[' or str[i] == '{')
        {
            stack.push(str[i]);
            stack2.push(i);
            continue;
        }
        else if(stack.empty())
        {
            flag = false;
            std::cout << i + 1;
            break;
        }
        top = stack.top();
        stack.pop();
        stack2.pop();
        if((top == '[' and str[i] != ']') or 
           (top == '(' and str[i] != ')') or 
           (top == '{' and str[i] != '}'))
        {
            flag = false;
            std::cout << i + 1;
            break;
        }
        }
    }
    if(stack.empty() and flag == true)
    {
        std::cout << "Success";
    }
    if(!stack.empty() and flag == true)
    {
        std::cout << stack2.top() + 1;
    }
    

    
    return 0;
}
