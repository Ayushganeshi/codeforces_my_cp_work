class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.size();
        int ans1=0;
        int ans2=0;
        for(int i=0;i<n/2;i++)
        {
            if(string("AEIOUaeiou").find(s[i]!=string::npos))
            ans1++;
        }
        for(int i=n/2;i<n;i++)
        {
            if(string("AEIOUaeiou").find(s[i]!=string::npos))
            ans2++;
        }
        if(ans1==ans2)return true;
        return false;
    }
};
