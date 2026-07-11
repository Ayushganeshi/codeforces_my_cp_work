class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int ans=0;
        for(int i=1;i<INT_MAX;i++)//i<11
        {

            if(i> max(memory1,memory2))
            {
             ans=i;
             break;
            } 
            if(memory1>=memory2)//
            {
                memory1-=i;//1
            }
            else
            {
                memory2-=i;//0
            }
            
        }
        return {ans,memory1,memory2};
    }
};
