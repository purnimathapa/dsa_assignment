Q4: Insert and Delete in Doubly Linked List

Overview:
This program creates a simple doubly linked list and shows how to insert a new node after a specific node and delete a node from anywhere in the list.

Data Structures Used:
- A structure called Node is used for the doubly linked list.
- It contains:
  - data: the value stored
  - prev: pointer to the previous node
  - next: pointer to the next node

Functions:

insertAfter:
- Inserts a new node after a given node.
- Adjusts the next and prev pointers to maintain the links.

deleteNode:
- Deletes a specific node from the list.
- Fixes the links of the nodes before and after it.

insertEnd:
- Adds a node to the end of the list.

printList:
- Prints all nodes in the list from head to tail.

Main Function:
- The list starts with 1, 2, 3.
- Then 4 is inserted after the first node.
- The second node is deleted.
- List is printed after each step.

How to Compile and Run:
gcc prog_4.c -o prog_4  
./prog_4

Sample Output:
Original list:  
1 2 3  
After inserting 4 after first node:  
1 4 2 3  
After deleting second node:  
1 2 3

Notes:
- Inserting or deleting from a doubly linked list needs careful pointer updates.
- This example can be modified to add nodes at the start or end directly.
