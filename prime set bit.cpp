bool chek(int n)
{
    int count1=0;
    if(n<2)
    return false;
    for(int i=2;i<=n;i++)
    {
        if(n%i==0)count1++;
        
    }
    if(count1>1)
    return false;
    return true;
}
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int count=0;
        for(int i=left;i<=right;i++)
        {
            bitset<32>b(i);
            int m=b.count();
            if(chek(m))count++;
        }
        return count;
    }
};
