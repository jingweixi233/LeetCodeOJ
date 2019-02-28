/*

while(p q !){
    sum = sum + p + q;
    if(sum >= 10){
        sum = sum % 10;
        new ListNode sum
        sum = 1;
    }
}
if(p !){
    new node
}
*/

 //Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), nex) {}
 };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p = l1;
        ListNode *q = l2;
        ListNode *a, *b, *ans;
        int sum = 0;
        sum = p -> val + q -> val;
        if(sum >= 10){
            sum = sum - 10;
            ans = new ListNode(sum);
            sum = 1;
        }
        else{
            ans = new ListNode(sum);
            sum = 0;
        }
        a = ans;
        p = p -> next;
        q = q -> next;
        while(p ! && q !){
            sum = sum + p -> val + q -> val;
            if(sum >= 10){
                sum = sum - 10;
                b = new ListNode(sum);
                a -> next = b;
                a = b;
                sum = 1;
            }
            else{
                b = new ListNode(sum);
                a -> next = b;
                a = b;
                sum = 0;
            }
            p = p -> next;
            q = q -> next;
        }

        if(p !){
            while(p !){
                sum = sum + p -> val;
                if(sum >= 10){
                    sum = sum - 10;
                    b = new ListNode(sum);
                    a -> next = b;
                    a = b;
                    sum = 1;
                }
                else{
                    b = new ListNode(sum);
                    a -> next = b;
                    a = b;
                    sum = 0;
                }
                p = p -> next;            
            }
        }

        if(q !){
            while(q !){
                sum = sum + q -> val;
                if(sum >= 10){
                    sum = sum - 10;
                    b = new ListNode(sum);
                    a -> next = b;
                    a = b;
                    sum = 1;
                }
                else{
                    b = new ListNode(sum);
                    a -> next = b;
                    a = b;
                    sum = 0;
                }
                q = q -> next;            
            }
        }

        if(sum == 1){
            b = new ListNode(sum);
            a -> next = b;
        }

        return ans;  
    }
};
