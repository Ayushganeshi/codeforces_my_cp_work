class Solution {
public:
    string maximumXor(string s, string t) {
        int zero=0;
        int ones=0;
        for(char ch :t)
        {
         if(ch=='0')zero++;
         else
         ones++;
        }
        string tnew="";
        for(char ch :s)
        {
            if(ch=='0')
            {
                if(ones>0)
                {
                    tnew+='1';
                    ones--;
                }
                else
                {
                    tnew+='0';
                    zero--;
                }
            }
            else
            {
                if(zero>0)
                {
                    tnew+='0';
                    zero--;
                }
                else
                {
                    tnew+='1';
                    ones--;
                }
            }
        }
        string ans="";
        for(int i=0;i<t.size();i++)
        {
            if(s[i]==tnew[i])
            ans+='0';
            else
            ans+='1';
        }
        return ans;
    


    }
};
