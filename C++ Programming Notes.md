### 构造函数

- Constructor Initialization lists

- Delegating Constructors

何时会调用拷贝构造函数：
> 1. passing object by value as a parameter
> 
> 2. returning an object from a function by value
> 
> 3. constructing one object based on another of the same class

调用拷贝构造函数的语法：

> - pass by lvalue reference(&)

> 因为 pass by value 会调拷贝构造函数，就会陷入递归

> - const

> 因为我们是要拷贝，而不是对原内容进行修改

浅拷贝的问题是，会拷贝出一个指针，指向堆中同一块地址。在新指针生命周期结束时，它所指向的空间会被析构函数释放，因此旧指针指向的地址，也就是释放的这片空间，将没有意义。

### 左值，右值与move

左值是能够用&取到地址的变量，其余均为右值，包括许多中间（暂存）变量

> 左值引用用&，右值引用用&&：

```
int x {100};
int &l_ref = x;
l_ref = 10;

int &&r_ref = 200;
r_ref = 300;
```

调用移动构造函数的语法：

> - pass by rvalue reference(&&)

> - 没有const

> 因为我们要NULL out 原指针

1. 浅拷贝：用一个新指针指向被拷贝指针指向的区域
2. 深拷贝：用一个新指针指向一个新空间，将被拷贝指针指向区域中的内容复制到新空间中
3. 移动拷贝： 浅拷贝，并将被拷贝指针置为nullptr，即释放，有点像剪切

### Operator Overloading 操作符重载

##### Overloading the copy assignment operator (deep copy) 重载拷贝赋值操作符：

声明与调用：

```
Type &Type::operator=(const Type &rhs);

Mystring &Mystring::operator=(const Mystring &rhs);

s2 = s1;                        // We write this

s2.operator=(s1);               // operator= method is called 
```

> 返回object的引用，以避免额外的拷贝

实现：

```
Type &Type::operator=(const Type &rhs) {
	if (this == &rhs)
		return *this;
		
	delete [] str;
	str = new char[std::strlen(rhs.str) + 1];
	std::strcpy(str, rhs.str);
	
	return *this;
}
```

##### Overloading the move assignment operator (deep copy) 重载移动赋值操作符：

声明与调用：

```
Type &Type::operator=(Type &&rhs);

Mystring &Mystring::operator=(Mystring &&rhs);

s1 = Mystring("Faith_bian");         // move operator= called

s1 = "Shadow";                       // move operator= called 
```

实现：

```
Mystring &Mystring::operator=(Mystring &&rhs) {
	if (this == &rhs)
		return *this;
		
	delete [] str;
	str = rhs.str;
	rhs.str = nullptr;
	
	return *this;
}
```

### Static

3 different pools of memory:

1. static: global variable storage, permanent for the entire run of the program.
2. stack: local variable storage (automatic, continuous memory).
3. heap: dynamic storage (large pool of memory, not allocated in contiguous order).

静态数据成员每个class有一份，所以也叫类变量；普通数据成员每个object有一份，也叫实例变量
