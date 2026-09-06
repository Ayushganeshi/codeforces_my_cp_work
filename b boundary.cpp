using namespace std;
#include<bits/stdc++.h>

#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;

#define ll long long

int main() {

    int t = 0;
    cin >> t;

    while (t--){
        int x = 0;
        int n = 0;

        cin >> x >> n;
        ll max_val = -1;
        ll iter_to = floor(sqrt(x));
        for (ll i = iter_to; i > 0; i--) {
            if (x % i == 0) {
                if (n * (x/i) <= x) { max_val = max(max_val, x/i); }
                else if ((n * i) <= x) { max_val = max(max_val, i); }
            }
        }
        cout << max_val << endl;
    }
    
    return 0;
}
