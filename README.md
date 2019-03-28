## Leetcode

> Welcome Lenka!!!

### Summary (updating)

- ![#1589F0](https://placehold.it/15/008000/000000?text=+) `Easy`
- ![#c5f015](https://placehold.it/15/F4D03F/000000?text=+) `Medium`
- ![#f03c15](https://placehold.it/15/f03c15/000000?text=+) `Hard`


#### 11. Container With Most Water ![#c5f015](https://placehold.it/15/F4D03F/000000?text=+)

> O(n)

> 20ms (98.29%)

Use 2 pointers starting at very left and right, then shrink to middle by replacing the shorter edge between the l and r.


#### 25. Reverse Nodes in k-Group ![#f03c15](https://placehold.it/15/f03c15/000000?text=+)

> O(n)

> 12ms (100.00%)

Recursively solved(but got an amazingly fast result). For each recursion:
- Get the tail for current part (the head of next part) by recursion of next part
- Reverse current part by inserting the head before tail, while counting down
- Return new head

#### 32. Longest Valid Parentheses ![#f03c15](https://placehold.it/15/f03c15/000000?text=+)

> O(n)

> 12ms (61.98%)

The others used stack while I used unordered_map. Not that fast but unique. '(' labelled +1 while ')' labelled -1 so we can get a graph like a skyline of the pyramids. In map, the key is height(y in graph) and the value is index(x in graph). When a ')' comes in, update the result with the bigger i - m[h].

#### 37. Sudoku Solver ![#f03c15](https://placehold.it/15/f03c15/000000?text=+)

> 8ms (92.73%)

Recursively solved. For each recursion:
- Try 1~9. If no conflict, go to next recursion
- If filled up, set found = true
- If found == false, retreat current step

#### 39. Combination Sum ![#c5f015](https://placehold.it/15/F4D03F/000000?text=+)

> 8ms (100.00%)

Recursively like No.39. Start from last i to avoid duplicates results.

#### 42. Trapping Rain Water ![#f03c15](https://placehold.it/15/f03c15/000000?text=+)

> O(n)

> 4ms (100.00%)

Retrieve from left to right and reverse to find the left and right wall.

#### 45. Jump Game II ![#f03c15](https://placehold.it/15/f03c15/000000?text=+)

> O(n^2)

> 12ms (99.33%)

For each i, check every valid next step to get the farthest point this i could reach. while reach the last one, return.

#### 48. Rotate Image ![#c5f015](https://placehold.it/15/F4D03F/000000?text=+)

> O(n^2)

> 8ms (N/A)

Swap is a good choice for in-place operation. Swap the elements by 0, 45, 90, 135 degree and by combining them, we can get what we want.

#### 148. Sort List ![#c5f015](https://placehold.it/15/F4D03F/000000?text=+)

> O(nlgn)

> 44ms (99.36%)

Implementation of classic Merge Sort. 2 functions:
- Sort. Split the linked list by half, return head of the merged list of 2 half lists.
- Merge. Merge 2 sorted linked list to 1 sorted list. return the new head.



### Classification (to be updated)

