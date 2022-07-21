 

# C++ 中struct 与class的区别

### 1 区分

1. 成员默认权限不同，class默认为private，struct默认为public；

2. 默认继承权不同，class继承默认是private继承，而struct默认是public继承；

3. class可以用于定义模板参数，但是struct关键词不能：

   ```c++
   //正确的
   <class T>
   T fun(T a)
   {
       .....
   }
   //错误的
   <struct T>
    T fun(T a)
   {
       .....
   }
   ```

### 2 c++保留struct关键字的原因

1. 保证对C语言的向下兼容性，又要具有C++的一些类似对象的拓展，方便c语言代码能更容易的移植到C++中；
2. C++中一般只用struct来存储结构化数据，不会有结构体继承的写法(没必要)。
