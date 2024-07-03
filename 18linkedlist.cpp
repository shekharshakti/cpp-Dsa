#include <iostream>
#include <vector> // Include vector header for vector<int>
#include <map>    // Include map header for cycle detection

using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Reverse a linked list using recursion
    ListNode* reverseUsingRecursion(ListNode* prev, ListNode* curr) {
        // Base case
        if(curr == nullptr) {
            return prev;
        }
        // Recursive case
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        return reverseUsingRecursion(prev, curr);
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        return reverseUsingRecursion(prev, curr);
    }

    // Find the middle node of a linked list
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    // Compare two linked lists
    bool compareList(ListNode* head1, ListNode* head2) {
        while (head1 != nullptr && head2 != nullptr) {
            if (head1->val != head2->val) {
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        return true;
    }

    // Check if a linked list is palindrome
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true; // empty or single element list is palindrome
        }

        ListNode* midNode = middleNode(head);
        ListNode* head2 = midNode->next;
        midNode->next = nullptr; // Split the list into two halves

        ListNode* prev = nullptr;
        ListNode* curr = head2;
        head2 = reverseUsingRecursion(prev, curr); // Reverse the second half

        // Compare the two halves
        return compareList(head, head2);
    }

    // Check if a linked list has a cycle
    bool hasCycle(ListNode *head) {
        map<ListNode*, bool> visited;

        ListNode* temp = head;
        while(temp != nullptr) {
            if (visited[temp]) {
                return true; // Cycle detected
            }
            visited[temp] = true;
            temp = temp->next;
        }
        return false; // No cycle
    }
};

// Function to create a linked list from an array and return the head
ListNode* createListFromArray(vector<int>& arr) {
    ListNode* dummy = new ListNode();
    ListNode* current = dummy;
    for (int num : arr) {
        current->next = new ListNode(num);
        current = current->next;
    }
    return dummy->next;
}

// Function to print a linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Solution sol;

    // Test reverseList
    vector<int> arr1 = {1, 2, 3, 4, 5};
    ListNode* head1 = createListFromArray(arr1);
    cout << "Original list: ";
    printList(head1);
    ListNode* reversedHead1 = sol.reverseList(head1);
    cout << "Reversed list: ";
    printList(reversedHead1);

    // Test middleNode
    vector<int> arr2 = {1, 2, 3, 4, 5};
    ListNode* head2 = createListFromArray(arr2);
    ListNode* middleNode = sol.middleNode(head2);
    cout << "Middle node value: " << middleNode->val << endl;

    // Test isPalindrome
    vector<int> arr3 = {1, 2, 3, 2, 1};
    ListNode* head3 = createListFromArray(arr3);
    bool palindrome = sol.isPalindrome(head3);
    cout << "Is palindrome? " << (palindrome ? "Yes" : "No") << endl;

    // Test hasCycle
    vector<int> arr4 = {1, 2, 3, 4, 5};
    ListNode* head4 = createListFromArray(arr4);
    // Adding a cycle for testing
    ListNode* cycleStart = head4->next->next; // Point to node with value 3
    ListNode* temp = head4;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = cycleStart; // Create cycle
    bool hasCycle = sol.hasCycle(head4);
    cout << "Has cycle? " << (hasCycle ? "Yes" : "No") << endl;

    return 0;
}
