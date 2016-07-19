#include<iostream>
#include<vector>

using namespace std;

typedef struct Node{
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
}ListNode;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL;
        ListNode *temp = NULL;
        if (l1 == NULL && l2 == NULL) {
            return NULL;
        } else if (l1 == NULL) {
            return l2;
        } else if (l2 == NULL) {
            return l1;
        }
        
        while(l1 != NULL && l2 != NULL) {
            if(head == NULL) {
                if(l2->val < l1->val) {
                    head = l2;
                    l2 = l2->next;
                } else {
                    head = l1;
                    l1 = l1->next;
                }
                temp = head;
            } else {
                if(l1->val < l2->val) {
                    temp->next = l1;
                    l1 = l1->next; 
                    temp = temp->next;
                } else {
                    temp->next = l2;
                    l2 = l2->next; 
                    temp = temp->next;
                }
            }    
        }
        
        
        if(l1 != NULL) {
                temp->next = l1;
        } else {
                temp->next = l2;
        }
    
        
        return head;
    }
};

int main() {
    Solution sln;
    return 0;
}
