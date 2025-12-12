#include <iostream>
using namespace std;

int main() {
   int num,ans,rem,mul;
        cout<<"enter   the number";
        cin>>num;
        ans=0;
        mul=1;
        while(num>0){
            rem=num%10;
            num/=10;
            ans=rem*mul+  ans;
            mul*=2;

        }
        cout<<ans<<endl;
    return 0;

}

