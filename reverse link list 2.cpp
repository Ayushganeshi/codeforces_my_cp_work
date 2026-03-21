class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp=head;
        int n=0;
        vector<int>ans;
        while(temp!=NULL)
        {
            n++;
            ans.push_back(temp->val);
            temp=temp->next;
        }
        reverse(ans.begin()+left-1,ans.begin()+right);
        ListNode* dummy=new ListNode(10);
        ListNode* tempp=dummy;
        for(auto & val :ans)
        {
            tempp->next= new ListNode(val);
            tempp=tempp->next;
        }
        return dummy->next;
    }
};
