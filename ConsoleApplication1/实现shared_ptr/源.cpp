/*智能指针包含的步骤：
1.智能指针是个模板类
2.智能指针内有个模板指针T* ptr，指向实际的对象
3.有一个引用计数器，而且必须定义成指针，因为如果自己初始化一个真实指针对象，
就自己new一个计数器出来，并从1开始计数；如果是被拷贝的，则不自己new计数器出来，
而是用源头的那个shared_ptr new出来的计数器；
4.各种重载，包括：
（1）*重载；
（2）->重载；
（3）拷贝构造函数重载；（引用计数器+1）
（4）=赋值运算符重载；（被赋值掉的那个shared_ptr引用计数器-1）
（5）析构函数重载，引用计数器-1并判断是否为0，为0即调用delete释放真实对象*/

#include<iostream>
using namespace std;
template<typename T>
class Shared_ptr
{
public:
	//默认构造
	Shared_ptr():count(nullptr),_ptr(nullptr){}
	//带参构造函数
	Shared_ptr(T *p) :count(new int(1)), _ptr(p) {}//调用这个构造函数表示存在了第一个p的对象
	//拷贝构造函数
	Shared_ptr(Shared_ptr<T>& other):count(&(++(*other.count))),_ptr(other._ptr){}//拷贝的另一个shared_ptr，因此找到源头count加1
	//重载*
	T& operator*() { return *_ptr; }//遇到*shared_ptr，就返回*_ptr,看起来就像shared_ptr像个真实指针那样
	//重载->
	T* operator->() { return _ptr; }//Shared_ptr.operator->()->....
	//重载=赋值运算符，如果被赋值的原Shared_ptr有对象，则被赋值后原来的指向就失效 了，因此要把原来指向的计数器-1
	Shared_ptr<T>& operator=(Shared_ptr<T>& other)
	{
		if (this == &other)//左值、右值是同一个对象
			return *this;

		//只要=两边不是同一个对象，那必然右值里的真实指针对象就多了次引用，先加上再说
		++*other.count;//右值多了个分身，因此右值里的计数器+1
		//左值被覆盖掉前，要先处理下左值自家指针的计数情况，死前料理好后事
		if (this->_ptr && --*this->count == 0)//自家指针还不为0，且自家计数器刚好为1，自己一死就不再有自家指针的引用了，因此死前把自家指针指向的对象释放掉
		{
			delete count;//释放掉自家计数器
			delete _ptr;//释放掉自家指针
		}
		//左值死前已料理完后事，下面开始被右值覆盖
		this->_ptr = other._ptr;//自家原来的ptr被覆盖
		this->count = other.count;//自己的计数器也被other的计数器取代。。。好惨
		return *this;//再见到我，已不是原来的我了。。。
	}
	//析构函数
	~Shared_ptr()
	{
		//进到这个函数，表示这个我的生命即将终结，不论我出生从一而终也好、被人附体也罢，生命
		//即将终结，还是要做好该做的后事。
		if (_ptr && --*count == 0)//计数只剩1了，我死后，我的ptr再没有人照顾了，为了防止我的ptr变野，一起死吧！
		{
			delete count;
			delete _ptr;
		}
	}
	//对了，还有这个函数哦，用这个可以查看自家的ptr被引用情况
	int GetCount()
		return *count;


private:
	int *count;//必须是指针定义，不能直接定义int
	T* _ptr;   //真实的指针；
};