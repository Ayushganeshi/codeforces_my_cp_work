#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, a, b;
        cin >> n >> a >> b;

        // Number of complete groups of 3
        long long groups = n / 3;

        // Remaining items after making groups
        long long rem = n % 3;

        // Cost if we buy one extra group pack
        long long cost1 = (groups + 1) * b;

        // Cost using group packs + single items
        long long cost2 = groups * b + rem * a;

        // Cost if we buy everything separately
        long long cost3 = n * a;

        // Print minimum cost
        cout << min(cost1, min(cost2, cost3)) << endl;
    }

    return 0;
}
