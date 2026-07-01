class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>pref;
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,nums[i]);
            int cm=gcd(nums[i],maxi);
            pref.push_back(cm);

        }
        sort(pref.begin(),pref.end());
        int m=pref.size();
        long long ans=0;
        for(int i=0;i<m/2;i++)
        {
              ans+=gcd(pref[i],pref[m-i-1]);
        }
        return ans;
    }
};
