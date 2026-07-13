class Solution {
public:
    void reorderList(ListNode* head) 
    {
        if(!head || !head->next || head->next->next) exit;
        int c=0;
        ListNode*temp=head;
        while(temp)
        {
            c++;
            temp=temp->next;
        }
        temp=head;
        for(int i=1;i<(c+1)/2 ;i++)
        temp=temp->next;
        ListNode* del = temp;
        temp=temp->next;
        del->next=nullptr;
        ListNode* prev = nullptr;      
        while (temp != nullptr) 
        {
            ListNode* temp2 = temp->next;
            temp->next = prev;               
            prev = temp;                    
            temp = temp2;               
        }
        ListNode* dummy=new ListNode(0);
        temp=dummy;
        ListNode* t1=head;
        ListNode* t2=prev;
        while(t2)
        {
            temp->next=t1;
            temp=t1;
            t1=t1->next;

            temp->next=t2;
            temp=t2;
            t2=t2->next;
        }
        temp->next=t1;
    }
};
