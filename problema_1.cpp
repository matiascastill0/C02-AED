// Definition for singly-linked list.
#include "iostream"
using  namespace std;
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
     void printList(ListNode *head) {
          ListNode * temp= head;
          while (temp!=nullptr) {
              cout<<temp->val<<endl;
              temp=temp->next;
          }
      }


 };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode * temp;
        ListNode * prev=nullptr;
        while (head!=nullptr) {
            temp=head->next;
            head->next=prev;
            prev=head;
            head=temp;
        }
        return  prev;
    }

};
int main() {
   ListNode * head= new ListNode(1);
    head->next= new ListNode(2);
    head->next->next= new ListNode(3);
    head->next->next->next= new ListNode(4);
    cout<<" LISTA ORIGINAL : "<<endl;
    head->printList(head);
    cout<<"LISTA INVERTIDA  : "<<endl;
    Solution s1;
     head= s1.reverseList(head);
    head->printList(head);
}