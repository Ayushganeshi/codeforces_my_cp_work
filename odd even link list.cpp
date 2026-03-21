/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* temp=head;
        int n=0;
        vector<int>ans;
        while(temp!=NULL)
        {
            n++;
            ans.push_back(temp->val);
            temp=temp->next;
        }//1,2,3,4,5
        vector<int>ans1;
        
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                ans1.push_back(ans[i]);
            }
        }

        for(int i=0;i<n;i++)
        {
            if(i%2!=0)
            {
                ans1.push_back(ans[i]);
            }
        }
        ListNode* dummy=new ListNode(10);
        ListNode* tempp=dummy;
        for(auto & val :ans1)
        {
            tempp->next=new ListNode(val);
            tempp=tempp->next;
        }
        return dummy->next;
        
    }
};
