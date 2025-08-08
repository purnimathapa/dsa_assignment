Q3: Reverse Traversal of Linked List

Overview:
This program creates a simple singly linked list and prints the values in reverse order. It doesn't actually reverse the list—it just prints it backward using recursion.

Data Structures Used:
- A structure called Node is used to represent a linked list node.
- It has:
  - data: the value stored in the node
  - next: pointer to the next node in the list

Functions:

reversePrint:
- Uses recursion to print from the last node to the first.
- It first reaches the end, then prints as the recursive calls return.

insertEnd:
- Adds a new node to the end of the linked list.

Main Function:
- A list is created with values: 10, 20, 30, 40.
- The reversePrint function is called to show them in reverse.



Sample Output:
Reverse traversal:
40 30 20 10


