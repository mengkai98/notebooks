#ifndef ENJOY_STATIC_H
#define ENJOY_STATIC_H
class enjoy_static{
    public:
    enjoy_static();
    ~enjoy_static();
    int get_num2();
    static void set_num(const int num);

    static int num1 ;
    private:
    static int num2 ;

};
int enjoy_static::num1 = 0;//初始化
int enjoy_static::num2 = 0;
enjoy_static::enjoy_static(){
    num1++;
    num2--;
}
enjoy_static::~enjoy_static(){
    num1--;
    num2++;
}
int enjoy_static::get_num2(){
    return enjoy_static::num2;
}
void enjoy_static::set_num(const int num ){
    num1 = num;
    num2 = -num;
}
#endif
