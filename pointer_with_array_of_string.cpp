#include<bits/stdc++.h>
using namespace std;
int main()
{
    const char* arr[]={"sumit","ayush","rajveer","ravikant"};
    const char** p=arr;
    for(int i=0;i<4;i++)
    {
        cout<<*(p+i)<<endl;
    }

    return 0;

}