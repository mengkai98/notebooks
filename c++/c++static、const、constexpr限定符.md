#  C++ static、const、contexpr限定符

## 1 static

### 1.1 静态全局变量

在全局变量前加上 **static** 关键字，该变量就为一个静态全局变量，对于一个静态全局变量，有以下特点：

1.  该变量在**全局数据区**分配内存；
2.  未被初始化的静态全局变量会被程序自动初始化为0；
3.  静态全局变量在声明他的整个文件都是可见的，而在**文件之外**是不可见的 <font style = "color:red">※</font>；

因此，静态全局变量不会被其他文件所用(*即使是加上 extern 也是不行的*) ，在其他的文件中也可以定义相同名字的变量不会发生冲突。

```c++
#include <iostream>
static int n; //定义一个整数类型的全局静态变量。
int main(int argc,char** argv)
{
    std::cout<<n<<std::endl;
}
```

### 1.2 静态局部变量

在局部变量前加上 **static** 关键字，该变量就为一个静态局部变量，它具有以下特点：

1. 静态局部变量的内存分配不再是**栈内存** 而是和全局变量一样保存在全局数据区；
2. 静态局部变量在程序首次执行到该对象时初始化，随后就**不再初始化**；
3. 虽然它始终驻留在全局数据区但它的作用域是局部作用域。

当我们需要在两次甚至多次函数调用之间保存变量的值，静态全局变量成为了一个很好的选择。

```c++
#include <iostream>
int fun(int a){
	static int base =7;
	return base + a;
}
int main(int argc , char** argv){
    
    std::cout<<fun(1)<<std::endl;//output 8
    std::cout<<fun(2)<<std::endl;//output 9
}
```

### 1.3 静态函数

在函数的返回类型前加上**static** 关键字，函数就被定义为静态函数，静态函数的特点就是：**它只能在声明它的文件中课件，不能被其他文件使用**。 所以在其他文件中可以定义相同名字的函数，不会发生冲突。

```c++
static int hello(){
	std::cout<<hello<<std::endl;
}
```

### 1.4 静态数据成员

在类内的数据成员声明前加上关键字**static** 该成员就是一个静态数据成员，对于静态数据成员，有以下特性：

1. 相较于其他成员变量在每个类对象中都有一份自己的拷贝，但静态数据成员在程序中仅有一份拷贝，由该类型的所有对象共享访问；
2. 静态数据成员遵循 **public、protected、private** 访问规则；
3. 静态数据成员在全局数据区分配内存，不属于特定的类对象，因此不需要产生任何该类的实例也可以操作它。

```c++
class enjoy{
    public:
    /**
    	...
    */
    static int public_num;//可以通过enjoy::public_num访问
    private:
    /**
    	...
    */
    static int private_num;//private权限，所有类对象都可以共同访问
}
```

### 1.5 静态成员函数

相较于普通的成员函数，在调用时会隐含一个**this** 指针，但是在静态成员函数中，这个指针是缺省的。因此静态成员函数不与**任何对象**相联系。所以它无法访问非静态数据成员，也没法访问非静态成员函数，只能调用其余的静态成员函数和静态数据成员。

```c++
class enjoy{
    public:
    /**
    	...
    */
    static int get_num2();//可以通过enjoy::get_num2()调用

}
```

## 2 const 

### 2.1 常量(顶层const与底层const)

关键字 **const** 指定变量的值是常量，并告知编译器防止程序员修改它。

在 C++ 中，可以使用 const 关键字而不是 #define 预处理器指令来定义常量值。 定义的 const 值受**类型检查的约束**，可用于代替常量表达式。 在 C++ 中，可以使用变量指定数组 const 的大小，如下所示：

```c++
const int maxarray = 255;
char store_char[maxarray];  // allowed in C++; not allowed in C
```

**const** 约束它右边最邻近的类型或变量名：

```c++
int n;
const int num；//const 约束int，表明“值”不发生变化，因此num的值不可被修改
const int *num_ptr1 = &num; //const 约束int，表明“值”不发生变化,num_ptr为一个“地址”，因此num_ptr指向的地址的数据不可被更改，但num_ptr本身可被更改
int *const num_ptr2 = &n;// const 约束 num_ptr,因此num_ptr指向的地址不可更改，但地址里的值可以更改。

```

通过以上例子，了解了**const**的作用范围，接下来说明顶层和底层const：

- 顶层const：指针或变量本身是个常量；
- 底层const：指针所指的变量是个常量。

```c++
int n;
const int num；//顶层const
const int *num_ptr1 = &num; //底层
int *const num_ptr2 = &n;// 顶层
const int *const num_ptr3 = &num;//底层 顶层(左至右)
//对于引用，特殊的
const int &r = num;//顶层 一但引用，引用为常值，引用所指也为常值。
```

### 2.2 const 成员函数

如果不想让函数修改其调用的对象，可以使用const关键字。常量成员函数不能修改任何非静态数据成员或调用不常量的任何成员函数。

```c++
class enjoy_const{
    public:
    int num;
    int get_num() const;
}
int enjoy_const::getnum() cost{
  return num;  
};
```



### 2.3 const 形参

顶层 const 不影响传入函数的对象，一个拥有顶层 const 的形参无法和另一个没有顶层 const 的形参区分开：

```c++
//如不使用指针，则形参只负责传值，修改形参不会修改原来的数据，因此会重定义
Record lookup(Phone);
Record lookup(const Phone);         //重复声明了Record lookup(Phone)

Record lookup(Phone*);
Record lookup(Phone* const);        //该const是顶层，重复声明了Record lookup(Phone* const)
```

如果形参是引用或者指针，则可以根据引用和指针是否指向常量进行重载，此时const是**底层**的，注意此时引用的const也是底层的。

```c++
Record lookup(Phone&);
Record lookup(const Phone&);        //正确，底层const实现了函数的重载
Record lookup(Phone*);
Record lookup(const Phone*);        //正确，底层const实现了函数的重载
```



### 2.4 c++与c 中的const

c中的const

```c
//1.声明：
const int i = 2;
//2.在另一个模块（文件）中引用
extern const int i ;
```

c++中若要也这样操作则要：

```c++
extern const int i = 2;
```

c++向c兼容这类操作的声明：

```c++
extern "C" const int x=10;
```


## 3 constexptr

constexptr 定义即是常量；const对比constexptr更偏向只读这一属性。

*代码测试，放在c++/example/static_const_constexpr/static_const_constexpr.cpp*