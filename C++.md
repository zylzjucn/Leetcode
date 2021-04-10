### auto 在 for loop 中的应用

- 只读 range 的元素：(大部分情况的首选)

```
for(const auto & x : range)
```
- 修改 range 的元素：

```
for(auto & x : range)    // ?? auto&& 
```
- 拷贝 range 的元素：

> 这种情况对于bool变量不行，它会返回引用，所以会修改原数据。如果不想修改原数据，那么就将 auto 换成 bool

```
for(auto x : range)
```

### &  &&

A && B, A 为 False 就不会计算B
A & B, A 为 False 还会计算B

### 时间

> return clock ticks. The actual time is related to the system. (often 1000 per second)

```
#include<ctime>

clock_t　s = clock();
MergeSort(data, n);
clock_t　e = clock();
```

### Emplace

```emplace``` 与 ```push``` 的区别（373）:

```push``` 只能传入构造好的对象，或者在传入时构造对象
```emplace``` 除以上2种操作外，还可以直接传入构造对象需要的元素，自己调用其构造函数。这样最优，节省内存
 
```
class data {
	int a;
	int b;
public:
	data(int x, int y): a(x), b(y) {}
};

// push:

// 1. 传入构造好的对象：

data d(1,2);
S.push(d);
S.emplace(d);

// 2. 传入时构造对象：

S.push(data(1, 2));
S.emplace(data(1, 2));

// 3. 传入构造对象的元素，自己构造。只有emplace能完成:

S.emplace(1, 2);
```

可以插入，看起来会区分输入的参数：

```
vector<pair<int, int>> v;
    v.emplace_back(1, 1);
    v.emplace_back(3, 3);
    v.emplace(v.begin() + 1, 2, 2);  // 看这里的参数
    // v: (1,1),(2,2),(3,3)
```

### priority_queue

```
auto comp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
```
用multiset删除元素，如果不指定游标而是指定值，那么如果这个值有多个，就会都删掉。反之游标不会

### 游标二分查找

> 用二分实现，所以O(lgn)

```
vector<int> v = {1,2,3,4,5,6,7,8};

auto it1 = lower_bound(t.begin(),t.end(),4);  // 第一个>=目标的元素
auto it2 = upper_bound(t.begin(),t.end(),4);  // 第一个>目标的元素
bool b = binary_search(t.begin(),t.end(),4);  // 是否存在
```

### sort

效率由高到低：

1. partition
2. stable_partition
3. nth_element
4. partial_sort
5. sort
6. stable_sort

> 只要前面一小部分：partial_sort()

> 前后都不要只要第n个：nth_element();

> 按某种特征归类: partition();

```
vector<int> v = {9,8,7,6,5,4,3,2,1,0};

partial_sort(v.begin(), v.begin() + 3, v.end());  // 0 1 2 9 8 7 6 5 4 3 , 第3个开始顺序不保证

nth_element(v.begin(), v.begin() + 3, v.end());  // 第3个元素一定会在正确的位置上

vector<int>::iterator bound = partition(v.begin(), v.end(), isOdd)
// isOdd 为另一个判断是否为奇数的函数
// partition返回值为第二部分的头指针
// 另外还有stable_partition

```

常规sort都是升序，相当于最后一个参数为重载函数```less<int>()```

同理，如果要降序，可以加入参数```greater<int>()```

```sort()```使用改良后的快排

```stable_sort()```使用归并排序

```partial_sort()```使用堆排序




### bitset

```
bitset<4> bitset1;　　//0000
bitset<8> bitset2(12);　　//00001100
string s = "100101";
bitset<10> bitset3(s);　　//0000100101
char s2[] = "10101";
bitset<13> bitset4(s2);　　//0000000010101
```


加了&快了非常多：

```
auto comp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
```

### Travelling salesman problem 旅行家问题

> 暴力解法: O(n!)
> 
> 优化解法: O(2^n)
> 


### Dijkstra 迪杰斯特拉算法

> 用来计算图中，node1至node2的最短距离
> 实质也是BFS
> 一个集合保存已经遍历过的点及到达这里的路径长度，这里的路径长度一定是最优的
> 一个集合保存还未遍历过的点及到达这里的路径长度
> 每次从第二个集合中，寻找最短的距离，因为图中所有边的权重均为正数，所以这个最短距离不可能通过第二个集合中的别的路径再加上其它路线得到，所以这个最短距离是最优的
> 把这个最优点放入第一个集合中，并据此便利这个点连接的边，更新第二个集合中其它点的结果
> 时间复杂度：O(m + n)lgn
