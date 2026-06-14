class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int mxfr=0;
        for(auto &it :mp)
        {
            if(it.second>mxfr)
            {
                mxfr=max(mxfr,it.second);
            }
        }
        int ans=0;
        for(auto &it :mp)
        {
            if(it.second==mxfr)
            {
               ans+=it.second;
            }
        }
        return ans;
        
    }
};
