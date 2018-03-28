# Kth Largest Element Problem

## Problems

- Leetcode 215. Kth Largest Element in an Array

## Idea

Method: **Divide and Conquer**

Similar to Quick Sort algorithm, the array is split into two. But there is no need to take care of the order of the split array only if the partition position is right ordered.

**partition() function**

There are many different versions of picking pivot in different ways.

Always pick first element as pivot.
Always pick last element as pivot (implemented below)
Pick a random element as pivot.
Pick median as pivot.

## Reference

- [QuickSort](https://www.geeksforgeeks.org/quick-sort/)

