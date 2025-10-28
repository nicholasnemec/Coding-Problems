/**
2. Add Two Numbers (MEDIUM)
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
    
Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

**/
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *temp = malloc(sizeof(struct ListNode));
    temp -> val = 0;
    temp -> next = NULL;
    
    struct ListNode *curr = temp;
    
    int carry = 0;
    while(l1 != NULL || l2 != NULL || carry != 0){
        int x = (l1 != NULL) ? l1->val : 0;
        int y = (l2 != NULL) ? l2->val : 0;
        int sum = x + y + carry;

        carry = sum / 10;

        struct ListNode *newNode = malloc(sizeof(struct ListNode));
        newNode -> val = sum % 10;
        newNode -> next = NULL;

        curr->next = newNode;
        curr = curr->next;

        if(l1!=NULL){
            l1 = l1->next;
        }

        if(l2!=NULL){
            l2 = l2->next;
        }
    }
    struct ListNode *output = temp->next;
    free(temp);
    return output;
}
