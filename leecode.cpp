/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
	    if(l2 == NULL) return l1;
	    if(l1==NULL &&l2==NULL) return NULL;
	    struct ListNode *rr,*result,*result2 = l1->val<=l2->val?l1:l2;
	    result=result2;
	    while(l1&&l2) {
	        if(l1 && l1->val<=l2->val){
	            rr = l1;
	            l1=l1->next;
	        } else if(l2 && l2->val <= l1->val){
	            rr = l2;
	            l2=l2->next;
	        }
	        if (result2 != l1 && result2 !=l2){
	             result->next = rr;
	             result=result->next;
	        }
	    }
	    result->next = l1?l1:l2;
	    return result2;
	    }
};
