class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
           for(auto & ch :paragraph)
           {
            if(!isalpha(ch))
            ch=' ';//////////////////////////////////////////   SPACE COMPLEXITY   0(N)
                /////////////////////////////////////////        TIME COMPLEXITY  0(N);
            else
            ch=tolower(ch);
            
           }
           unordered_set<string>st;
           for(auto & wor :banned)
           {
            st.insert(wor);
           }
           stringstream ss(paragraph);
           unordered_map<string,int>mp;
           string word;
           string ans;
           int mxcnt=0;
           while(ss>>word)
           {
            if(st.find(word)==st.end())
            {
                mp[word]++;
            }
           }
           int m=INT_MIN;
           for(auto &it: mp)
           {
            if(it.second>m)
            {
                ans=it.first;
                m=it.second;
            }
           }
           return ans;
           


    }
};
