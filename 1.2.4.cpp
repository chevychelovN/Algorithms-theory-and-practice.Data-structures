// Стек с поддержкой максимума

#include <iostream>
#include <stack>
#include <sstream>

int main() {
    std::stack<int> stack1;
    std::stack<int> stack2;
    int size;
    std::cin >> size;
    
    

    
    for(int i = 0; i < size; i++)
    {    
        std::string str;
        std::getline(std::cin >> std::ws, str);
        std::stringstream sin(str);
        std::string command;
        sin >> command;
        
        if(command == "push")
        {
            int number;
            sin >> number;
            stack1.push(number);
            
            if(stack2.empty())
            {
                stack2.push(number);
            }
            else if(stack2.top() < number)
            {
                stack2.push(number);
            }
            else
            {
                stack2.push(stack2.top());
            }
        }
        if(command == "pop")
        {
            stack1.pop();
            stack2.pop();
        }
        if(command == "max")
        {
            if(stack2.empty())
            {
                std::cout << 0;
            }
            else
            {
                std::cout << stack2.top() << "\n";
            }
        }
        
    }
    return 0;
}
