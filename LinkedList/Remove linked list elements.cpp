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
    ListNode* check(ListNode* temp, int value)
    {
        while(temp!= NULL && temp->next != NULL && temp->next->val == value)
        {
            temp = temp->next ;
            // cout << "temp->value" << " " << temp->val ;
        }
        return temp ;
    }
    ListNode* removeElements(ListNode* head, int val) {
        int value = val ;
        if(head == NULL)
            return NULL ;
        ListNode* ptr = head ;
        if(head->val == value)
        {
            ListNode* temp = check(ptr, value) ;
            // cout << "temp->next->value" << " " << temp->next->val << endl ;
            if(temp == NULL)
            {
                return NULL ;
            }
            else
            {
                ListNode* tempor = head ;
                head = temp->next;
                tempor = NULL ;
            }
            // cout << "head->val" <<" " <<head->val << endl ;
        }
        while(ptr != NULL)
        {
            //cout << "ptr->val" << " " << ptr->val << endl ;
            if(ptr->next != NULL)
            {
                    if(ptr->next->next == NULL and ptr->next->val == value)
                    {
                        ptr->next = NULL ;
                        
                    }
                    else if(ptr->next->val == value)
                    {
                        ListNode* temp = check(ptr, value);
                         if(temp->next == NULL)
                         {
                            ptr->next = NULL ;
                         }
                        else
                        {
                            ptr->next = temp->next ;
                            temp= NULL ;
                            //cout << "removed" << " " << ptr->next->val ;
                        }
               
                    }
            }ptr = ptr->next ;
        }
        return head ;
    }
}; 
