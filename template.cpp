#include <iostream>

using namespace std;
#if 0
template <typename... Ts>			  class Y {};  
template <> class Y<int>{};//实例特化 
template <> class Y<float>{};//
template <> class Y<int,int>{};//class 或者struct。  templates only available with -std=c++11 or -std=gnu++11

//2、一个函数形参包（function parameter pack）是一个接受零个或多个函数实参的函数形参。【例：

template<class ... Types> void f(Types... args){};
//template<> void func{};
//template void func<int>{};
//template void func<int,int>{};

//template <typename... TS>   // typename... TS为模板形参包，TS为模式
//static void MyPrint(const char* s, TS... args)  // TS... args为函数形参包，args为模式
//{
//    printf(s, args...);
//}

int main()
{

	Y<int> i;
	Y<float> f;
	Y<int,int> i1;
	f();
	f(0);
	f(1,2);
	return 0;
}
#else

template<class... T>
struct X : T...
{
    // 译者添加
    X(T... args) { }
};
 
template<class... T> void f(T... values) {
    X<T...> x(values...);
}
 
template void f<>();    // OK：X<>没有基类；x是类型X<>被值初始化的一个变量
 
// 译者添加：
int main() {
    struct Y { };
    struct Z { };
    f<>();    // 使用template void f<>();其中使用X<> x();
 
    // 使用template<class... T> void f(T... values)；
    // 其内部使用X<Y, Z> x(Y(), Z());
    // 而X<Y, Z>的定义为：struct X : Y, Z { X(Y arg1, Z arg2) { } };
    f(Y(), Z());
}
#endif                    
                     