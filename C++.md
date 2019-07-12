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