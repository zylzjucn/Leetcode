### auto 在 for loop 中的应用

- 只读 range 的元素：(大部分情况的首选)

```
for(const auto & x : range)
```
- 修改 range 的元素：

```
for(auto && x : range)
```
- 拷贝 range 的元素：

> 这种情况对于bool变量不行，它会返回引用，所以会修改原数据。如果不想修改原数据，那么就将 auto 换成 bool

```
for(auto x : range)
```

### &  &&

A && B, A 为 False 就不会计算B
A & B, A 为 False 还会计算B

### 语法

> 基于C++，其它语言参考意义不大

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

### 游标二分查找

> 用二分实现，所以O(lgn)

```
vector<int> v = {1,2,3,4,5,6,7,8};

auto it1 = lower_bound(t.begin(),t.end(),4);  // 第一个>=目标的元素
auto it2 = upper_bound(t.begin(),t.end(),4);  // 第一个>目标的元素
bool b = binary_search(t.begin(),t.end(),4);  // 是否存在
```

### bitset

```
bitset<4> bitset1;　　//0000
bitset<8> bitset2(12);　　//00001100
string s = "100101";
bitset<10> bitset3(s);　　//0000100101
char s2[] = "10101";
bitset<13> bitset4(s2);　　//0000000010101
```



decltype 问大佬

加了&快了非常多：

```
auto comp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
```