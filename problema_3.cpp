/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <iostream>
#include <regex>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}

    ~ListNode() {
        delete next;
    }

    void printList(ListNode* heap) {
        while (heap) {
            cout << heap->val << " ";
            heap = heap->next;
        }
        cout << endl;
    }

};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head==nullptr || left == right) {
            return head;
        }
        ListNode* temp=  new ListNode(0);
        temp->next = head;
        ListNode* anterior = temp;
        ListNode* current = NULL;
        ListNode* siguiente =  NULL;

        for (int i = 0; i < left - 1; i++) {
            anterior = anterior->next;
        }

        current = anterior->next;

        for (int i = 0; i < right - left; i++) {
            siguiente = current->next;
            current->next = siguiente->next;
            siguiente->next = anterior->next;
            anterior->next = siguiente;
        }

        ListNode* hep_2 = temp->next;
        temp->next =  NULL;

        delete temp;
        return hep_2;
    }
};



int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "LISTA ORIGINAL  ";
    head->printList(head);

    Solution S1;
    ListNode* reversed = S1.reverseBetween(head, 2,4 );
    cout << " ROTADA :  ";
    head->printList(reversed);
    // todo case two
    cout<<" - - -- CASO 2 ----"<<endl;
    ListNode*head2= new ListNode(5);
    cout << "LISTA ORIGINAL  ";
    head2->printList(head2);
    cout << " ROTADA :  ";
    Solution S2;
    ListNode* reversed_2 = S2.reverseBetween(head2, 1,1 );
    head2->printList(reversed_2);
    delete reversed;
    delete reversed_2;
    return 0;
}