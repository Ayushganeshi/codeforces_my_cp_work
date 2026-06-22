class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int n=s.length();
        unordered_map<char,int>mp,mp1;
        for(int i=0;i<n;i++)
        {
            if(target.find(s[i])!=string::npos)
            mp[s[i]]++;
        
        }
        for(int i=0;i<target.size();i++)
        {
            
            mp1[target[i]]++;
        
        }
        int ans=INT_MAX;
        for(int i=0;i<target.size();i++)         //o e c o d o e e c o d e/
        {
            ans=min(mp[target[i]]/mp1[target[i]],ans);
        }
        return ans;
    }
};
