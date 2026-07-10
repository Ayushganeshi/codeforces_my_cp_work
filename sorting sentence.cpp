class Solution {
public:
    string sortSentence(string s) {
        stringstream ss(s);
        string x;
        vector<string>ans;
        while(ss>>x)
        {
           ans.push_back(x);
        }
        vector<string>res(ans.size());
        for(auto &val : ans)
        {
            int indx=val.back()-'0';//converson to int
            val.pop_back();
            res[indx-1]=val;
        }
        string resf="";
        for(int i=0;i<res.size();i++)
        {
            resf+=res[i];
            if(i!=res.size()-1)
            {
                resf+=" ";
            }
            
        }
        return resf;
        
    }
};
