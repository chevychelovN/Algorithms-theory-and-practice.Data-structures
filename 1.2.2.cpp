// Высота дерева

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <utility>

int main() {
    
    int size;
    std::cin >> size;
    std::vector<std::vector<int>> list(size);
    int root = 0;
    for(int i = 0; i < size; i++)
    {
        int parent;
        std::cin >> parent;
        if(parent == -1)
        {
            root = i;
            continue;
        }
        
        list[parent].push_back(i);
        
    }
    std::map<int, int> vis;
    std::queue<std::pair<int, int>> q;
    int step = 0;
    q.push({root, 0});
    

    std::pair<int,int> first;
    while(!q.empty())
    {
        first = q.front();
        q.pop();
        vis[first.first] = 1;
        step = std::max(step, first.second);
        
        for(auto i:list[first.first])
        {
            if(!vis[i])
            {
                q.push({i, first.second + 1});
            }
        }
        
    }
    std::cout << step + 1;
    
    return 0;
}
