#include<iostream>
using namespace std;

void recursion(int k)
{
    int count = 0;
    cout<<"Hello ";
    count++;
    recursion(k);
    if(count == k)
    {
        return;
    }
}

int main()
{
    int k = 3;
    recursion(k);

    return 0;
}