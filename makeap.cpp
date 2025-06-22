#include <iostream>
using namespace std;

int main() {
   int num,ans,rem,mul;
        cout<<"enter the number";
        cin>>num;
        ans=0;
        mul=1;
        while(num>0){
            rem=num%2;
            num/=2;
            ans=rem*mul+ans;
            mul*=10;

        }
        cout<<ans<<endl;
    return 0;
}