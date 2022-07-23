#include <iostream>
#include "./enjoy_static/enjoy_static.h"
#include "./enjoy_const/enjoy_const.h"
int main(int argc,char **argv)
{
    std::cout<<"enjoy: public static member:"<<enjoy_static::num1<<std::endl;
    enjoy_static e1;
    std::cout<<"generate one obj"<<std::endl;
    std::cout<<"enjoy: public static member:"<<enjoy_static::num1<<std::endl;
    std::cout<<"enjoy: private static member,read by e1.get_num2:"<<e1.get_num2()<<std::endl;
    enjoy_static *e2 = new enjoy_static();
    std::cout<<"generate the second obj"<<std::endl;
    std::cout<<"enjoy: public static member:"<<enjoy_static::num1<<std::endl;
    delete(e2);
    std::cout<<"delete the second obj"<<std::endl;
    std::cout<<"enjoy: public static member:"<<enjoy_static::num1<<std::endl;
    enjoy_static::set_num(15);
    std::cout<<"set num by enjoy::set_num"<<std::endl;
    std::cout<<"enjoy: public static member:"<<enjoy_static::num1<<std::endl;
    std::cout<<"enjoy: private static member,read by e1.get_num2:"<<e1.get_num2()<<std::endl;


    enjoy_const ec;
    std::cout<<std::endl<<"const test 1 :"<<std::endl;
    ec.test1();
    std::cout<<std::endl<<"const test 2 :"<<std::endl;
    ec.test2();
    std::cout<<std::endl<<"const test 3 :"<<std::endl;
    ec.test3(ec.p2);
    std::cout<<std::endl<<"const test 4 :"<<std::endl;
     std::cout<<"p2:"<<*ec.p2 <<std::endl;
    ec.test4(ec.p2);
    std::cout<<"const test 4 change p2:"<<*ec.p2 <<std::endl;
}
/**
output:
dawanzi•build/c++/example(main⚡)» ./static_const_constexpr_exec                                                                                                                                                                   [19:07:41]
enjoy: public static member:0
generate one obj
enjoy: public static member:1
enjoy: private static member,read by e1.get_num2:-1
generate the second obj
enjoy: public static member:2
delete the second obj
enjoy: public static member:1
set num by enjoy::set_num
enjoy: public static member:15
enjoy: private static member,read by e1.get_num2:-15

const test 1 :
const int *p1 :底层const 所指常量，本身可变
p1 = &size: 32
p1 = &m: 0
int *const p2 :顶层const 所指可变，本身常量
p2 : 0
 (*p2)++; n++;p2 : 2
const int *const p3 = &size;//本身不可变，指向的值也不可变
p3 : 32

const test 2 :
const 成员函数只能读 *p3: 32
const 成员函数只能读 n: 2

const test 3 :
const 形参写保护 value: 2

const test 4 :
p2:2
const test 4 change p2:0
**/