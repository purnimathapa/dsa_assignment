Q8: Random Numbers with Sorting Algorithm of User's Choice

Overview:
This program generates a list of random integers and sorts them based on the algorithm the user selects. It also shows the number of comparisons and swaps (or shifts) used during sorting.

Data Structures Used:
- An array to store random integers.
- A duplicate of the array is made before sorting so the original remains unchanged.

Functions:

bubbleSort:
- Classic bubble sort comparing adjacent elements.

selectionSort:
- Selects the smallest element in each pass and places it in order.

insertionSort:
- Builds a sorted array by inserting elements one by one in the right place.

mergeSort:
- Uses divide-and-conquer to split the array and merge them back in sorted order.

Main Function:
- Takes input for the number of elements (N).
- Fills the array with N random integers from 1 to 1000.
- Asks the user to choose the sorting algorithm.
- Sorts the array and prints both original and sorted lists.
- Displays total comparisons and swaps (or shifts).

How to Compile and Run:
gcc prog_8.c -o prog_8  
./prog_8

Sample Output:
Enter number of elements: 6  
Choose sorting algorithm:  
1. Bubble Sort  
2. Selection Sort  
3. Insertion Sort  
4. Merge Sort  
2  
Before sorting:  
743 102 88 619 5 300  
After sorting:  
5 88 102 300 619 743  
Comparisons: 15  
Swaps/Shifts: 3

Notes:
- Merge sort uses a temporary array for merging and tracks comparisons/swaps.
- Bubble and insertion sorts may perform more swaps for larger inputs.

