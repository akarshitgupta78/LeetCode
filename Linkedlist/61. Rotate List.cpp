class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(!head || !head->next || k == 0) return head;
        int c = 1;
        ListNode* temp = head;
        while (temp->next) 
        {
            temp = temp->next;
            c++;
        }
        temp->next = head;
        k=k%c;
        temp = head;
        for (int i=1;i < c - k;i++) 
            temp = temp->next;

        head = temp->next;
        temp->next = nullptr;

    return head;
    }
};
