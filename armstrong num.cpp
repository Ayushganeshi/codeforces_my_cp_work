#include<iostream>
using namespace std;
int main()
{
    int store,ans,rem,num;
    ans=0;
    cout<<"enter the number:";
    cin>>num;
    store=num;
    while(num> 0)
    {
        rem=num%10;
        num/=10;
        ans+=rem*rem*rem;
    }
    cout<<ans;
    
    if(ans=store){
        cout<<"armstrog number";
    }
    else{
        cout<<"not an armstrong number";
    }
    return 0;


    

}

