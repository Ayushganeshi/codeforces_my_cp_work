class Solution {
public:
    int minOperations(string s) {
        string t=s;
        sort(t.begin(),t.end());
        if(t==s)return 0;
        int n=s.size();
        if(s.front()==t.front() || s.back()==t.back())
        {
            return 1;
        }
        if(n==2)return -1;
        int first_min=s.find(t.front());//first occur of smallest char
        int last_max=s.rfind(t.back());//last occur of maxm character;
        if(first_min==n-1 && last_max==0)
        return 3;
        return 2;

    }
};
