#include<bits/stdc++.h>
using namespace std;
int main(){
    int ans=0;
    int num  ,rem;
    cout<<"enter the  number";
    cin>>num;
    while(num>0){
        rem=num%10;
        num=num/10;
        ans=ans+rem;
        if(num==0&&ans>9)
        {
            num=ans;
            ans===0;
        }
        

        
    }
    cout<<ans;

}



