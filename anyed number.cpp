#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool baseCase(ll *target_K,ll *target_S){
    if(*target_K==0) return *target_S==0;
    if(*target_S<*target_K) return false;
    return true;
}

bool edgeCase(ll *target_K,ll *target_S,ll *N,ll *M){

    if(*M==1){
        if(*N==1) return false;
        return (*target_S>=2*(*target_K) && *target_S<=(*N)*(*target_K));
    }

    if(*M==*N){
        return (*target_S>=*target_K && *target_S<=(*N-1)*(*target_K));
    }

    return true;
}

bool generalCase(ll *target_K,ll *target_S,ll *N,ll *M){

    ll c_max=(*target_S-*target_K)/(*M);

    ll num=*target_S-(*target_K)*((*M)-1);
    ll den=*N-*M+1;

    ll c_min=0;
    if(num>0) c_min=(num+den-1)/den;

    return max(0LL,c_min)<=min(*target_K,c_max);
}

bool can_form(ll *target_K,ll *target_S,ll *N,ll *M){

    if(!baseCase(target_K,target_S)) return false;

    if(*M==1 || *M==*N)
        return edgeCase(target_K,target_S,N,M);

    return generalCase(target_K,target_S,N,M);
}

ll findAnswer(ll *N,ll *K,ll *S,ll *M){

    for(ll x=0;x<=*K;x++){

        ll rK=*K-x;
        ll rS=*S-x*(*M);

        if(can_form(&rK,&rS,N,M))
            return x;
    }

    return -1;
}

void solve(){

    ll N,K,S,M;
    cin>>N>>K>>S>>M;

    ll ans=findAnswer(&N,&K,&S,&M);

    if(ans!=-1) cout<<ans<<"\n";
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin>>T;

    while(T--) solve();
}
