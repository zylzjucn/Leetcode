## Leetcode

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
- reverse current part by inserting the head before tail, while counting down
- return new head

#### 32. Longest Valid Parentheses ![#f03c15](https://placehold.it/15/f03c15/000000?text=+)

> O(n)

> 12ms (61.98%)

The others used stack while I used unordered_map. Not that fast but unique. '(' labelled +1 while ')' labelled -1 so we can get a graph like a skyline of the pyramids. In map, the key is height(y in graph) and the value is index(x in graph). When a ')' comes in, update the result with the bigger i - m[h].

### Classification (to be updated)

