class Solution {
public:
    bool isPathCrossing(string path) {
    
        set<pair<int,int>>st;
        int n=path.length();
        pair<int,int>p;
        p.first=0;
        p.second=0;
        st.insert({0,0});
        for(int i=0;i<n;i++)
        {
            if(path[i]=='N')
            {
                p.second+=1;
            }
            if(path[i]=='S')
            {
                p.second-=1;
            }
            if(path[i]=='E')
            {
                p.first+=1;
            }
            if(path[i]=='W')
            {
                p.first-=1;
            }
            st.insert({p.first,p.second});
        }
        if(st.size()!=n+1)
        return true;
        return false;
        
    }
};
