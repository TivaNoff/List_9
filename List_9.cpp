#include <iostream>

// Визначення структури для вузла зв'язаного списку
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Функція для розділення зв'язаного списку
ListNode* partition(ListNode* head, int x) {
    ListNode less_dummy(0); // фіктивний вузол для менших значень
    ListNode* less_tail = &less_dummy;

    ListNode greater_dummy(0); // фіктивний вузол для більших або рівних значень
    ListNode* greater_tail = &greater_dummy;

    while (head) {
        if (head->val < x) {
            less_tail->next = head;
            less_tail = head;
        }
        else {
            greater_tail->next = head;
            greater_tail = head;
        }
        head = head->next;
    }

    less_tail->next = greater_dummy.next; // з'єднання менших значень з більшими або рівними

    greater_tail->next = nullptr; // завершення списку більших або рівних значень

    return less_dummy.next;
}

// Функція для виводу зв'язаного списку
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Приклад використання
int main() {
    // Приклад 1
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(4);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(2);
    head1->next->next->next->next = new ListNode(5);
    head1->next->next->next->next->next = new ListNode(2);

    int x1 = 3;

    std::cout << "Input 1: ";
    printList(head1);

    ListNode* result1 = partition(head1, x1);

    std::cout << "Output 1: ";
    printList(result1);

    // Приклад 2
    ListNode* head2 = new ListNode(2);
    head2->next = new ListNode(1);

    int x2 = 2;

    std::cout << "Input 2: ";
    printList(head2);

    ListNode* result2 = partition(head2, x2);

    std::cout << "Output 2: ";
    printList(result2);

    return 0;
}
