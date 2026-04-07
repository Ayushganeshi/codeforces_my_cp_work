class Solution {
public:
    int maximumProduct(vector<int>& nums) {///////////////////////////space compl,exitym  0(1))
        int n=nums.size();/////////////////////////////////////////////time compexity   0(n)

        sort(nums.begin(),nums.end(),greater<int>());
        int res=nums[0]*nums[1]*nums[2];
        int res1=nums[n-1]*nums[n-2]*nums[0];
        int ans=max(res,res1);
        return ans;
    }
};
