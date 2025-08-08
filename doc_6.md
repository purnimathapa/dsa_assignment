Q6: Build Min and Max Heap from an Unsorted Array

Overview:
This program takes an unsorted array of numbers and builds both a min-heap and a max-heap using heapify methods.

Data Structures Used:
- Arrays are used to represent heaps.
- Standard binary heap rules are applied:
  - Left child at 2*i+1
  - Right child at 2*i+2

Functions:

maxHeapify:
- Maintains max-heap property starting from index i.
- Recursively pushes the largest value to the top.

minHeapify:
- Similar to maxHeapify but for min-heap (smallest value at top).

buildMaxHeap / buildMinHeap:
- Converts the whole array into a max or min heap by heapifying from bottom-up.

printArray:
- Prints all elements of an array.

Main Function:
- An array with numbers {5, 3, 8, 4, 1, 2} is used.
- It is copied to two separate arrays.
- One is converted to a max-heap, the other to a min-heap.
- All arrays are printed.

How to Compile and Run:
gcc prog_6.c -o prog_6  
./prog_6

Sample Output:
Original array:  
5 3 8 4 1 2  
Max Heap:  
8 4 5 3 1 2  
Min Heap:  
1 3 2 4 5 8

Notes:
- This can be easily extended to build a heap for priority queues.
- Useful for understanding how heaps work internally.
