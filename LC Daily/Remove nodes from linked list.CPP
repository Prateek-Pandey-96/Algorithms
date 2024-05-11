// 2487. Remove Nodes From Linked List

class Solution {
public:
    ListNode* reverseList(ListNode* head){
        ListNode *curr= head, *prev = NULL, *next = NULL;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        head = reverseList(head);
        ListNode *crawl = head;
        int max_val = INT_MIN;
        ListNode *traverser = new ListNode(-1);
        ListNode *headPtr = traverser;
        while(crawl){
            if(crawl->val >= max_val){
                max_val = crawl->val;
                traverser->next = new ListNode(max_val);
                traverser = traverser->next;
            }
            crawl = crawl->next;
        }
        return reverseList(headPtr->next);
    }
};