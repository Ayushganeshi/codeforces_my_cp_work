#include<iostream>
using namespace std
// AUTHOR:->Ayush Kumar Gupta
//      !!CHES S   & CODE!!
int main(){
    int num,rem;
    int ans;
    ans=0;
    cin>>num;
    while(num>=0)
    {
        
        
        rem=num%10;
        num=num/10;
        ans=ans*10+rem;
    }
    cout<<ans;
}



