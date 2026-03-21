
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        vector<int>ans;
        ListNode* temp=head;

        while(temp!=NULL)
        {
            ans.push_back(temp->val);
            temp=temp->next;
        }
        //1,2,3,4,5
        reverse(ans.begin(),ans.end());//5,4,3,2,1
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
