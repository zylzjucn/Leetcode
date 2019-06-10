## Leetcode

### Summary (updating)

- ![#1589F0](https://placehold.it/15/008000/000000?text=+) `Easy`
- ![#c5f015](https://placehold.it/15/F4D03F/000000?text=+) `Medium`
- ![#f03c15](https://placehold.it/15/f03c15/000000?text=+) `Hard`

|#|Title|Solution|
|---|---|---|
|1|Two Sum|用unordered_map，降至O(n)|
|2|Add Two Numbers|一个变量存储进位，当l1,l2,进位非均为空时，继续计算|
|3|Longest Substring Without Repeating Characters|用一个数组存储字符出现的次数。if为0，则没出现过，end++; else出现过，start++。每步操作都要修改数组|
|4|Median of Two Sorted Arrays||
|5|Longest Palindromic Substring||
|6|ZigZag Conversion||
|7|Reverse Integer||
|8|String to Integer (atoi)||
|9|Palindrome Number|设置一个sum来存储x从右边吐出数字的倒序，直到sum > x，相当于折半。如果此时两者相等或者为10倍关系，则返回true|
|10|Regular Expression Matching||
|11|Container With Most Water|O(n2)降至O(n)。由外而内，不断替换短边。因为宽度在减少，要找到更大的必须高度增加。而只有替换短边，才可能高度增加。|
|12|Integer to Roman||
|13|Roman to Integer||
|14|Longest Common Prefix||
|15|3Sum|时间复杂度大于O(n2)。可以直接sort，然后每个外层循环固定游标1，游标2在可达到最左侧（游标1右1位），游标3在最右侧。根据三者和与目标值（0）的大小关系，决定是2进，还是3退。注意如果有重复元素，需要多加一个循环来跳过。|
|16|3Sum Closest|同15。通过sort减少一层时间复杂度。通过和与目标值的大小关系决定2进或3退|
|18|4Sum|同15。通过sort减少一层时间复杂度。通过和与目标值的大小关系决定3进或4退|
|19|Remove Nth Node From End of List|**链表倒数**。设置快慢2个游标，快的先跑差速步，然后同时跑即可|
|21|Merge Two Sorted Lists|递归。比较2个链表第1个node大小，取小的，递归剩余|
|22|Generate Parentheses|递归。每次记录剩余左括号和右括号（或者较左括号多）的数量，依此确定是否终止|
|24|Swap Nodes in Pairs|new一个新的头。很适合这种头node会变的情况|




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

#### 115. Distinct Subsequences ![#f03c15](https://placehold.it/15/f03c15/000000?text=+)

> O(n^2)

> 4ms (100.00%)

Classic DP using a matrix. The elements in the matrix stands for the number of the subsequences of S.substr(0, i) equals T.substr(0, j). Initialize the first row with 0 and first colume with 1, then update the rest. If 2 char do not equal, then keep the old result. Else, add the upleft result.

#### 124. Binary Tree Maximum Path Sum ![#f03c15](https://placehold.it/15/f03c15/000000?text=+)

> O(n)

> 36ms (98.14%)

2 functions. The maxPathSum function calls the maxBranch function and keeps a variable to store the max value(the result), the maxBranch one calls itself recursively and return the branch with the max sum containing the current node.

#### 138. Copy List with Random Pointer ![#c5f015](https://placehold.it/15/F4D03F/000000?text=+)

> O(n)

> 28ms (100.00%)

Very tricky. 3 steps:
- Add a new node after every old ones
- Build the random pointer for the new ones according to the relative positions of the old ones.
- Seperate 2 groups of the nodes.

#### 148. Sort List ![#c5f015](https://placehold.it/15/F4D03F/000000?text=+)

> O(nlgn)

> 44ms (99.36%)

Implementation of classic Merge Sort. 2 functions:
- Sort. Split the linked list by half, return head of the merged list of 2 half lists.
- Merge. Merge 2 sorted linked list to 1 sorted list. return the new head.

#### 149. Max Points on a Line ![#f03c15](https://placehold.it/15/f03c15/000000?text=+)

> O(n^2)

> 20ms (57.54%)

Use a pair to represent a line. The pair is also the key for the map. We must devide the GCD of the pair elements so that the same slopes share the same pair. Not just using a k cuz difficulty comparison of float values.

#### 419. Battleships in a Board ![#c5f015](https://placehold.it/15/F4D03F/000000?text=+)

> O(n)

> 8ms (98.74%)

We only count the first cell(left-top one of a battleship) to avoid duplicate counting. Every valid first cells have no left or up 'X'.

#### 424. Longest Repeating Character Replacement ![#c5f015](https://placehold.it/15/F4D03F/000000?text=+)

> O(n)

> 8ms (100.00%)

Sliding window. Use 2 pointers and always add the end while adjust start in the inner loop to meet the requirement of the substring. The biggist trick here is we only need to update the maxCount while there is a bigger count, instead of reducing it while the actual maxCount decrease, since we only wants the longer substring instead of the shorter result.

#### 442. Find All Duplicates in an Array ![#c5f015](https://placehold.it/15/F4D03F/000000?text=+)

> O(n)

> 116ms (95.60%)

O(n) required. So we use the index itself to track the element show times in the array. We flip the element on the specific position to negative thus next time we come here, we know this is the second time.

#### 542. 01 Matrix ![#c5f015](https://placehold.it/15/F4D03F/000000?text=+)

> O(n)

> 208ms (56.84%)

BFS. Shares the same idea with many other matrix and tree problems. We only need to keep the height(distance here) and traverse the elements level by level.

### Classification (to be updated)

