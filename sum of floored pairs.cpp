class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {

        const int MOD = 1000000007;

        int maxVal = *max_element(nums.begin(), nums.end());

        vector<int> freq(maxVal + 1, 0);

        for (int x : nums)
            freq[x]++;

        vector<int> prefix(maxVal + 1, 0);

        for (int i = 1; i <= maxVal; i++)
            prefix[i] = prefix[i - 1] + freq[i];

        long long ans = 0;

        for (int x = 1; x <= maxVal; x++) {

            if (freq[x] == 0)
                continue;

            for (int multiple = x; multiple <= maxVal; multiple += x) {

                int left = multiple;
                int right = min(maxVal, multiple + x - 1);

                int count = prefix[right] - prefix[left - 1];

                ans = (ans + 1LL * count * (multiple / x) * freq[x]) % MOD;
            }
        }

        return ans;
    }
};
