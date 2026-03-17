
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        bool flag=false;;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                flag=true;
                break;
            }
        }
        if(flag==false)
        return NULL;// after detecting cycle we have to move slow and temp one
        ListNode* temp=head;//unit it is proven they meet at the first cycle node
        while(slow!=temp)
        {
            slow=slow->next;
            temp=temp->next;
        }
        return temp;
    }
};
