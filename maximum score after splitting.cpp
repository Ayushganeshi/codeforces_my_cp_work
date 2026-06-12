class Solution {
public:
    int maxScore(string s) {
        int zero=0;
        int ones=0;
        int n=s.size();
        int ans=0;
        int total_ones=count(s.begin(),s.end(),'1');
        for(int i=0;i<n-1;i++)
        {
            if(s[i]=='0')
            {
                zero++;
            }
            
            else
            {
                ones++;
            }
            int right_ones=total_ones-ones;
            
            ans=max(ans,zero+right_ones);
    
        }
        return ans;
    }
};
