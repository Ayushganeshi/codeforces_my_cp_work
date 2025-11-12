#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    map<int,int>m;
    while(q--){
       
        int x;
        cin>>x;
        if(x==1){
            int y;
            cin>>y;
            m[y]++;
        }
        else{
            int y;
            cin>>y;
            cout<<m[y]<<endl;
        }
    }
}