
//#include "stdafx.h"

#include <iostream>
using namespace std;
using std::endl;
//using std::cout;
//using namespace namespace_name1;
//using namespace namespace_name1::namespace_name2;
 // 第一个命名空�?
 namespace first_space{
	void func(){
		cout << "Inside first_space" << endl;
	}
}
// 第二个命名空�?
namespace second_space{
   void func(){
      cout << "Inside second_space" << endl;
   }
}
namespace namespace_name1 {
   // 代码声明
   namespace namespace_name2 {
      // 代码声明
   }
}
class Box
{
   public:
      double length;         // 长度
      double breadth;        // 宽度
      double height;         // 高度
      static int objectCount;
 //构造函数第一次初始化
 	Box(void){
	 	length=1;
		breadth=1;
		height=1;
		width=2;
		private_test=3;
		objectCount++; // 每次创建对象时增加1
		ptr = new int;// 为指针分配内存
		*ptr = 1;
		 cout << "Box_0 Object is being created" << endl;
	}
	      // 构造函数2  
	Box(double l, double b, double h)
  {
     cout <<"Box Constructor2 called." << endl;
     length = l;
     breadth = b;
     height = h;
	 ptr = new int;// 为指针分配内存	 
	 *ptr = 2;
  }
	Box(double i);
	Box( const Box &obj); 	 // 拷贝构造函数	
	~Box();
	  int compare(Box box)//this use
      {
         return this->getVolume() > box.getVolume();
      }
	   static int getCount()
      {
         return objectCount;
      }
      // 重载 + 运算符，用于把两个Box 对象相加
      Box operator+(const Box& b)// 如果不是类成员函数，则两个函数入口参数Box operator+(const Box&, const Box&);
      {
         Box box;
         box.length = this->length + b.length;
         box.breadth = this->breadth + b.breadth;
         box.height = this->height + b.height;
         return box;
      }      // 成员函数声明
      double getVolume(void);
      void setLength( double len );
      void setBreadth( double bre );
      void setHeight( double hei );
	  void display1(void){
		cout <<"Box_display:"<<length <<breadth<<height<<width<<private_test<<*ptr<<endl;
	  }
	  void display2(void);
	  
	  virtual void getVolume2(void){//基类中使用virtual,否则使用继承子类函数也是调用基类的函�?	  	
		  cout << "BOX getVolume2:"<<length * breadth * height<<endl;
	  }
	  //virtual int xx() = 0;//= 0 告诉编译器，函数没有主体，该虚函数是纯虚函数
	 // virtual int getVolume3() = 0;//抽象类定义一个接口，具体由子类实�? 报错待解�?	  
  protected:
      double width;
  private:
  		double private_test;
		int *ptr;
};
/*
（1） 公有继承(public)

公有继承的特点是基类的公有成员和保护成员作为派生类的成员时，它们都保持原有的状态，而基类的私有成员仍然是私有的，不能被这个派生类的子类所访问。

（2）私有继承(private)

私有继承的特点是基类的公有成员和保护成员都作为派生类的私有成员，并且不能被这个派生类的子类所访问。

（3）保护继承(protected)

保护继承的特点是基类的所有公有成员和保护成员都成为派生类的保护成员，并且只能被它的派生类成员函数或友元访问，基类的私有成员仍然是私有的。
*/
//多继承，分隔即可// 派生类
class SmallBox :public Box // SmallBox 是派生类 默认private 继承 struct 中默认public 继承�?#6#9#
{
   public:
   	SmallBox(double i){
		Box();//4#5#
		height=i;	
		width=i;//基类中的非私有成员都称为子类的私有成员private Box
		//private_test=i;错误，基类的private成员不能被派生类访问private Box�?		 
		cout << "SmallBox_i Object is being created" << endl;
	}
      void setSmallWidth( double wid );
      double getSmallWidth( void );
	  void getVolume2(void){//派生类中不使用virtual
	  	cout << "SmallBox getVolume2:"<<length * breadth * height<<endl;
	  }
//	  int getVolume3(void){//派生类中不使用virtual
//	  	cout << "SmallBox getVolume3:"<<length * breadth * height<<endl;
//		return 0;
//	  }
};


 
// 子类的成员函�?
double SmallBox::getSmallWidth(void)
{
    return width ;
}
 
void SmallBox::setSmallWidth( double wid )
{
    width = wid;
}
// 成员函数定义
// 初始化类 Box 的静态成�?
int Box::objectCount = 0;
//Box::Box(double i):length(i),breadth(i)
Box::Box(double i)
{
	length=i;
	breadth=i;
	height=i;
	width=i;
	private_test=i;
	ptr = new int;// 为指针分配内�?	
	*ptr=i;
	 cout << "Box_i Object is being created" << endl;
}
Box::Box(const Box &obj)
{
	length=obj.length;
	breadth=obj.breadth;
	height=obj.height;
	width=obj.width;
	private_test=obj.private_test;
	ptr = new int;// 为指针分配内�?	
	*ptr=*obj.ptr;
	 cout << "Box_obj Object is being created" << endl;
}

Box::~Box(void)
{
	length=0;
	breadth=0;
	height=0;
	width=0;
	private_test=0;
	if (ptr != NULL)
		delete ptr;//每个构造函数分配内存，否则释放内存 出问�?	 cout << "Box Object is deleted" << endl;
}
void Box::display2( void )
{
	cout << "Box_display2:" << length << endl << breadth << endl << height << endl 
		<< width << endl << private_test << endl  << *ptr<< endl;
    //return *ptr;
}

double Box::getVolume(void)
{
    return length * breadth * height;
}
 
void Box::setLength( double len )
{
    length = len;
}
 
void Box::setBreadth( double bre )
{
    breadth = bre;
}
 
void Box::setHeight( double hei )
{
    height = hei;
}

void display(Box obj)
{
    obj.display2();
}

/*
Box_0 Object is being created
Box_0 Object is being created
Box1 volume:210
Box2 volume:1560
Box_0 Object is being created
Box_0 Object is being created
Box Object is deleted
SmallBox_i Object is being created
Width of box : 5
Box_obj Object is being created
Box_display2:6
7
5
2
3
1963060099
Box Object is deleted
Box_obj Object is being created
Box Object is deleted
Box Object is deleted
Box Object is deleted
Box Object is deleted
*/
// 程序的主函数
int main(int argc, char* argv[])//int main()
{
//	int *ptr = new int;// 为指针分配内�?//	*ptr=3;
//	cout <<"ptr:"<<*ptr<<endl;
//	delete ptr;
//	cout <<"ptr:"<<*ptr<<endl;
   Box Box1;                // 声明 Box1，类型为 Box	1# 7#
   Box Box2;                // 声明 Box2，类型为 Box	2#	8#
   double volume = 0.0;     // 用于存储体积
	// Box1.fun();
   // box 1 详述
   Box1.setLength(1.0); 
   Box1.setBreadth(2.0); 
   Box1.setHeight(3.0);
 
   // box 2 详述
   Box2.setLength(4.0); 
   Box2.setBreadth(5.0); 
   Box2.setHeight(6.0);
   Box2.display2();
   // box 1 的体积 
   volume = Box1.getVolume();
   cout << "Box1 volume:" << volume <<endl;
 
   // box 2 的体积  
   volume = Box2.getVolume();
   cout << "Box2 volume:" << volume <<endl;

   SmallBox sBox(6);//3#6#9#
 	//box.fun();
   // 使用成员函数设置宽度
   sBox.setSmallWidth(5.0);
   cout << "Width of sBox : " << sBox.getSmallWidth()  << endl;
 sBox.display2(); //继承若为基类的private，不是public不能直接访问
   //cout << "Width of sBox : "<< sBox.width<<sBox.private_test << endl;错误，protected/private成员不能在类外访问
   display(Box1);// 这里也调用了拷贝构造函�?    
   Box Box5 = Box1; // 这里也调用了拷贝构造函�?

  Box Box3(1.1,2,5);    // Declare box1
   Box Box4(2.3,6.2,9.2);    // Declare box2
 
   if(Box3.compare(Box4))
   {
      cout << "Box4 is smaller than Box3" <<endl;
   }
   else
   {
      cout << "Box4 is equal to or larger than Box3" <<endl;
   }

    Box *ptrBox;                // Declare pointer to a class.
    ptrBox = &Box3;
	cout << "Volume of Box3: " << ptrBox->getVolume() << endl;
	cout << "Total objects: " << Box::objectCount << endl;
	cout << "Final Stage Count: " << Box::getCount() << endl;

	   // 把两个对象相加，得到 Box6
   Box  Box6 = Box1 + Box2;
   cout << "Volume of Box6 : " << Box6.getVolume() <<endl;

  	Box1.getVolume2();
	sBox.getVolume2();
//	  box.getVolume3();

   // 调用第一个命名空间中的函�?   
	first_space::func();
   
   // 调用第二个命名空间中的函�?   
	second_space::func(); 
	std::cin.get();//或getchar()system("pause");
   return 0;
}

                                                                                                                                                                                                                                                                                                                       