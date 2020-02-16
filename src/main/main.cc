#include <iostream>
#include "src/lib/solution.h"

int main()
{
    MaxHeap myheap;

    for(int i = 1; i < 10; i++)
    myheap.push(i);
    myheap.pop();
    for(auto x : myheap.data_)
    std::cout<<x<<' ';
    std::cout<<'\n'<<myheap.top();
    return EXIT_SUCCESS;
}