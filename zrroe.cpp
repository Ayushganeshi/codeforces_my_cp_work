class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n=nums.size();
        int zero=count(nums.begin(),nums.end(),0);
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
            {
                nums[i]=1;
            }
        }
        int ans=0;
        for(int i=n-1;i<=0;i++)
        {
            if(nums[i]==1)
            {
                ans++;
                zero--;
                if(zero==0)
                break;
            }
        }
        return ans;
    }
};
