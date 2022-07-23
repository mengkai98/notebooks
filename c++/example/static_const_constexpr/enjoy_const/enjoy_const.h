#ifndef ENJOY_CONST
#define ENJOY_CONST
#include <iostream>
class enjoy_const{
    public:
    const int size = 32;//必须在此初始化
    const int m = 0;
    int n = 0;
    
    const int *p1;//本身可变，指向的值不可变
    int *const p2 = &n;//指向的值可变
    const int *const p3 = &size;//本身不可变，指向的值也不可变

    void test1();
    void test2()const;
    void test3(const int* value);
    void test4( int* const value);
};
void enjoy_const::test1()
{
    std::cout<<"const int *p1 :底层const 所指常量，本身可变"<<std::endl;
    p1 = &size;
    std::cout<<"p1 = &size: "<<*p1<<std::endl;
    p1 = &m;
    std::cout<<"p1 = &m: "<<*p1<<std::endl;
    std::cout<<"int *const p2 :顶层const 所指可变，本身常量"<<std::endl;
    std::cout<<"p2 : "<<*p2<<std::endl;
    (*p2)++;
    n++;
    std::cout<<" (*p2)++; n++;p2 : "<<*p2<<std::endl;
    std::cout<<"const int *const p3 = &size;//本身不可变，指向的值也不可变"<<std::endl;
    std::cout<<"p3 : "<<*p3<<std::endl;
}
void enjoy_const::test2() const{
    //n= 9; 报错
    std::cout<<"const 成员函数只能读 *p3: "<<*p3<<std::endl;
    std::cout<<"const 成员函数只能读 n: "<<n<<std::endl;
}
void enjoy_const::test3(const int* value){//可传入 const int*  | int *const | const int* const 
    //*value = 2;报错 不管形参可不可写，一律不可写（只读特性）
    std::cout<<"const 形参写保护 value: "<<*value<<std::endl;

}
void enjoy_const::test4( int* const value)//顶层，传入的指针不可改，但是变量可改；
{
    //传入的变量必须可读，但是不会改指针所指
    *value =0; 
}
#endif