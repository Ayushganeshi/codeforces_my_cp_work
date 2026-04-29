#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    map<long ,long>m;

    ////////////////////////////// time complexity 0(n);
    //////////////////////////     space complexity  0(n);
    while(q--){
       
        int x;
        cin>>x;
        if(x==1){
            int y;

            
            
            m[y]++;
        }
        else{
            int y;
            cin>> y;
            cout<<m[y]<<endl;
        }
    }

}





