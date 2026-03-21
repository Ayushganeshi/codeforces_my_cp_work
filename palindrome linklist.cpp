class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int n=0;
        vector<int>ans;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            n++;
            ans.push_back(temp->val);
            temp=temp->next;
        }
        int k=n/2;
        for(int i=0;i<k;i++)
        {
            if(ans[i]!=ans[n-i-1])
            return false;
        }
        return true;

    }
};
