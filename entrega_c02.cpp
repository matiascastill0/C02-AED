// Integrantes:
// 202120533 - Aldair Seminario Sanchez
// 202210081 - Matias Castillo Quincho
// 202220226 - Renzo Felix Aponte

#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}

  void printList() const {
    const ListNode *temp = this;
    while (temp != nullptr) {
      cout << temp->val << " ";
      temp = temp->next;
    }
    cout << endl;
  }
};

// Ejercicio 1: Inversión de una lista enlazada
class Solution1 {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode *prev = nullptr;
    ListNode *current = head;
    while (current != nullptr) {
      ListNode *nextNode = current->next;
      current->next = prev;
      prev = current;
      current = nextNode;
    }
    return prev;
  }
};

// Ejercicio 2: Rotación de una lista enlazada
class Solution2 {
public:
  ListNode *rotateRight(ListNode *head, int k) {
    if (!head || k == 0)
      return head;


    int length = 1;
    ListNode *tail = head;
    while (tail->next) {
      tail = tail->next;
      length++;
    }

    tail->next = head;
    k = k % length;
    int stepsToNewHead = length - k;

    ListNode *newTail = head;
    for (int i = 0; i < stepsToNewHead - 1; i++) {
      newTail = newTail->next;
    }
    ListNode *newHead = newTail->next;
    newTail->next = nullptr;

    return newHead;
  }
};

// Ejercicio 3: Inversión parcial de una lista enlazada
class Solution3 {
public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    if (!head || left == right)
      return head;

    ListNode dummy(0);
    dummy.next = head;
    ListNode *prev = &dummy;

    for (int i = 0; i < left - 1; i++) {
      prev = prev->next;
    }

    ListNode *current = prev->next;
    for (int i = 0; i < right - left; i++) {
      ListNode *temp = current->next;
      current->next = temp->next;
      temp->next = prev->next;
      prev->next = temp;
    }

    return dummy.next;
  }
};

void ejercicio1() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  cout << "LISTA ORIGINAL: ";
  head->printList();
  Solution1 s1;
  ListNode *reversed = s1.reverseList(head);
  cout << "LISTA INVERTIDA: ";
  reversed->printList();
  delete reversed;
}

void ejercicio2() {
  ListNode *head = new ListNode(0);
  head->next = new ListNode(1);
  head->next->next = new ListNode(2);
  cout << "LISTA ORIGINAL: ";
  head->printList();
  Solution2 s2;
  ListNode *rotated = s2.rotateRight(head, 4);
  cout << "LISTA ROTADA: ";
  rotated->printList();
  delete rotated;
}

void ejercicio3() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  cout << "LISTA ORIGINAL: ";
  head->printList();
  Solution3 s3;
  ListNode *partiallyReversed = s3.reverseBetween(head, 2, 4);
  cout << "LISTA PARCIALMENTE INVERTIDA: ";
  partiallyReversed->printList();
  delete partiallyReversed;
}

int main() {
  int opcion;
  cout << "Selecciona el ejercicio a ejecutar (1, 2 o 3): ";
  cin >> opcion;

  switch (opcion) {
  case 1:
    ejercicio1();
    break;
  case 2:
    ejercicio2();
    break;
  case 3:
    ejercicio3();
    break;
  default:
    cout << "Opción no válida :v " << endl;
    break;
  }

  return 0;
}
