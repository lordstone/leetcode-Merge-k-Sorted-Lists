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

    ListNode* merge(ListNode* x, ListNode* y){
        if(x == NULL && y == NULL) return NULL;
        if(x == NULL) return y;
        if(y == NULL) return x;
        ListNode* head = new ListNode(-1);
        ListNode* cur = head;
        while( x != NULL || y != NULL){
            if(x == NULL) {
                cur->next = y;
                y = y->next;
            }else if(y == NULL){
                cur->next = x;
                x = x->next;
            }else{
                if(x->val < y->val){
                    cur->next = x;
                    x = x->next;
                }
                else {
                    cur->next = y;
                    y = y -> next;
                }
            }//end if
            cur = cur->next;
        }//end while
        cur = head->next;
        delete head;
        return cur;
    }//end merge
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        if (lists.size() == 1) return lists[0];
        if (lists.size() == 2) return merge(lists[0], lists[1]);
        vector<ListNode*> left, right;
        left.insert(left.end(), lists.begin(), lists.begin() + lists.size()/2);
        right.insert(right.end(), lists.begin() + lists.size()/2, lists.end());
        ListNode *newleft = mergeKLists(left);
        ListNode *newright = mergeKLists(right);
        ListNode* mylist = merge(newleft, newright);
        return mylist;
    }//end margekLists
    
    
};
