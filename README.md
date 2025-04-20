# 🔀Push Swap
This project is about sorting algorithm and optimization to get less number of steps to sort 100 numbers below 700 steps and 500 numbers below 5500 steps.

# 📝Step by step guide
## 💣Initialize stack
There are two stacks which is **stack A** and **stack B**.\
Stack A will be the sorted numbers.\
Stack B must be NULL after sorting.\
![Image](https://github.com/user-attachments/assets/28d9a17a-fc1d-4806-a3cb-55421c7c3cb7)

In this project, I choose to use **double linked list** for the stack. \
![Image](https://github.com/user-attachments/assets/207a9c16-4c4d-4199-b36a-dca08129f182) \
Every argument passed (int) is stored in each node.\
In the following argument given, the **first number** is the **head** of the linked list, and the subsequent argument is appended to the list from top to bottom.
```
./push_swap 4 2 3 5 1
```
## 💣Handle argument error
+ arg not integer
+ arg larger/ smaller than int max/min
+ duplicate values\
**Must Return:** 
```
Error\n
```

## 💣Build operations
### Swap (sa, sb, ss)
![Image](https://github.com/user-attachments/assets/8e923186-fd45-40d5-98dd-043efe7995c3)

### Rotate (ra, rb, rr)
![Image](https://github.com/user-attachments/assets/1a7e729d-1446-4b05-bd9a-c1148b2861fc)

### Reverse rotate (rra, rrb, rrr)
![Image](https://github.com/user-attachments/assets/c06fffd6-40d9-4290-a187-97fc36b89e43)

### Push (pa, pb)
![Image](https://github.com/user-attachments/assets/c06fffd6-40d9-4290-a187-97fc36b89e43)

## 💣Choose algorithm
### 1. Quicksort 
+ Principle: divide and conquer\
**Step 1:** Choose pivot (the last element of array)\
**Step 2:** Create partition of the array (based on position of pivot)\
**Step 3:** Recursion (sub-array after partition)\
**Step 4:** Base case (left < right)\
![Image](https://github.com/user-attachments/assets/973056c9-80ed-4855-9486-4d2fa73369d1)

### 2. Merge Sort
**Step 1:** Divide\
Divide the list or array recursively into two halves until it can no more be divided.\
**Step 2:** Conquer\
Each subarray is sorted individually using the merge sort algorithm\
**Step 3:** Merge\
The sorted subarrays are merged back together in sorted order. The process continues until all elements from both subarrays have been merged.\
![Image](https://github.com/user-attachments/assets/d749070e-0c8a-4d20-b116-481fab5beaf3)

### 3. Bubble sort
**Step 1:** Compare the first number with the next number\
**Step 2:** Move the larger number to the right of the array\
**Step 3:** Repeat until the number are sorted\
+ slow for large data sets\
![Image](https://github.com/user-attachments/assets/9d6db702-f27d-4db0-b02b-e950e2ec30eb)

### 4. Insertion sort
### 5. Radix sort
### 6. Turk algorithm
### 7. Binary search (searching algorithm)
+ give index for sorted numbers in array\
![Image](https://github.com/user-attachments/assets/ac719a97-607a-4738-8560-044fb55e4f31)
