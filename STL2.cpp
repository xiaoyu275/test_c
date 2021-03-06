#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>

#include <stdlib.h>    // Need random(), srandom()
#include <time.h>      // Need time()
#include <iterator>

#include<cstdio>	//标准c头文件

using namespace std;

template <typename T>
void showvector(vector<T> v)
{
    for (typename std::vector<T>::iterator it = v.begin(); it != v.end(); it++)//typename 要加 不然报错
    {
        cout << *it<<"	";
    }
    cout << endl;
}
template <typename T>
void showlist(list<T> v)
{
    for (typename std::list<T>::iterator it = v.begin(); it != v.end(); it++)//typename 要加 不然报错
    {
        cout << *it<<"	";
    }
    cout << endl;
}

void test_1(void)
{
	#define SIZE 20
	int iarray[SIZE] = {0,50};
	int* ip = find(iarray, iarray + SIZE, 50);//注意如果first和last指向不同的容器
	if (ip == iarray + SIZE)
	  cout << "50 not found in array" << endl;
	else
	  cout << *ip << " found in array" << endl;

	vector<int> intVector(SIZE);
	intVector[10] = 50;
  vector<int>::iterator intIter =find(intVector.begin(), intVector.end(), 50);
  if (intIter != intVector.end())
    cout << "Vector contains value " << *intIter << endl;
  else
    cout << "Vector does not contain 50" << endl;


double darray[10] ={1.0, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9};
 
vector<double> vdouble(10);
   vector<double>::iterator outputIterator = vdouble.begin();
  copy(darray, darray + 10, outputIterator);//copy()算法的时候，你必须确保目标容器有足够大的空间，或者容器本身是自动扩展的
	 showvector(vdouble);
	 
  replace(vdouble.begin(),vdouble.end(),1.1,2.1);
  showvector(vdouble);
  
  reverse(vdouble.begin(),vdouble.end());
  showvector(vdouble);
  
	random_shuffle(vdouble.begin(), vdouble.end());
	showvector(vdouble);

	sort(vdouble.begin(), vdouble.end());
	showvector(vdouble);
}

// Display label s and contents of integer vector v
void Display(vector<int>& v, const char* s)
{
  cout << endl << s << endl;
 // 第三个参数实例化了ostream_iterator<int>类型，并将它作为copy()函数的输出目标迭代器对象。“\t”字符串是作为分隔符
  copy(v.begin(), v.end(),ostream_iterator<int>(cout, "\t"));//#include <iterator>
  cout << endl;
}
//srandom random linux c库，可以改用srand rand 或者编译加上-Dsrandom=srand -Drandom=rand
void test_2(void)
{
//	srandom( time(NULL) );//-Dsrandom=srand -Drandom=rand
	  vector<int> collection(10);
  for (int i = 0; i < 10; i++)
    collection[i] = random() % 10000;//-Dsrandom=srand -Drandom=rand
 
  // Display, sort, and redisplay
  Display(collection, "Before sorting");
  sort(collection.begin(), collection.end());
  Display(collection, "After sorting");
  showvector(collection);

  int iArray[5] = { 1, 2, 3, 4, 5 };
   list<int> iList;
   copy(iArray, iArray + 5, front_inserter(iList));
   showlist(iList);
	// Locate value 3 in iList
	 list<int>::iterator p =find(iList.begin(), iList.end(), 3);
	 // Copy first two iArray values to iList ahead of p
	 copy(iArray, iArray + 2, inserter(iList, p));
	 showlist(iList);
}
#include <functional>   // Need multiplies() (or times())
#include <numeric>      // Need accumulate()

void test_3(void)
{
	#define MAX 10

	vector<long> v(MAX);
	for (int i = 0; i < MAX; i++)
		v[i] = i + 1;
	showvector(v);
	
     vector<int> v1;
     for(int i = 0; i < 10; ++i )
     {
         v1.push_back(i);
     }
	 v1.insert(v1.begin(),111);//v1.begin()+n
	showvector(v1);
	  reverse(v.begin(),v.end());
	long sum =accumulate(v.begin(), v.end(), 0);//把从 v.begin() 开始到 v.end()结束所有的元素加到 0上面去 求和
	cout << "Sum of values == " << sum << endl;
	
	// Accumulate the product of contained values
	//
	long product =accumulate(v.begin(), v.end(), 1, multiplies<long>());//注意这行 multiplies(1,v)计算乘积
	cout << "Product of values == " << product << endl;
}
void test_4(void)
{
	     string s;
     s = "123456789";
     int sum = 0;
     for(int i = 0; i < s.size(); ++i)
     {
         switch(s[i])
         {
             case '1': sum += 1;break;
             case '2': sum += 2;break;
             case '3': sum += 3;break;
             case '4': sum += 4;break;
             case '5': sum += 5;break;
             case '6': sum += 6;break;
             case '7': sum += 7;break;
             case '8': sum += 8;break;
             case '9': sum += 9;break;
         }
     }
     
     cout << sum << endl;

     string s1,s2,s3;
     char sa[100],sb[100],sc[100];
     sscanf("abc 123 wcd","%s%s%s",sa,sb,sc);
     s1 = sa;
     s2 = sb;
     s3 = sc;
     cout << s1 << " " << s2 << " " << s3 << endl;
 
     //将字符串分离成数字，分隔符为',''$'
     int a,b,c;
     sscanf("4,5$6","%d,%d$%d",&a,&b,&c);
     cout << a << " " << b << " " << c << endl;
}
 struct Info
 {
     string name;
     double score;
 
     //重载 <
     bool operator < (const Info &a) const
     {
         return a.score < score;
     }
 };
void test_5(void)
{
     set<Info> s;//multiset与set的不同之处就是key可以重复，以及erase（key）的时候会删除multiset里面所有的key并且返回删除的个数。
     Info info;
 
     info.name = "abc";
     info.score = 123.3;
     s.insert(info);
 
     info.name = "EDF";
     info.score = -23.53;
     s.insert(info);
 
 
     info.name = "xyz";
     info.score = 73.3;
     s.insert(info);
     
     for(set<Info>::iterator it = s.begin(); it != s.end(); ++it)
     {
         cout << (*it).name << ":" << (*it).score << endl;
     }
     cout << endl;
 
     for(set<Info>::reverse_iterator rit = s.rbegin(); rit != s.rend(); ++rit)
     {
         cout << (*rit).name << ":" << (*rit).score << endl;
     }
     cout << endl;
	 
}
void test_6(void)
{
	map<char,int> m;//multimap由于允许有重复的元素，所以元素插入、删除、查找都与map不同。

    m['0'] = 0;
    m['1'] = 1;
    m['2'] = 2;
    m['3'] = 3;
    m['4'] = 4;
    m['5'] = 5;
    m['6'] = 6;
    m['7'] = 7;
    m['8'] = 8;
    m['9'] = 9;
    /*
        等价于
        for(int i = 0; i < 10; ++i)
        {
            m['0' + i] = i;
        }
    */

    string sa;
    sa = "9876543210";
    int sum = 0;
    for( int i = 0; i < sa.length(); ++i)
    {
        sum += m[sa[i]];
    }
    cout << sum << endl;
}
void test_7(void)
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(4);
    s.push(5);

//    cout << s.size() << endl;

    while(s.empty() != true)
    {
        cout << s.top() << endl;
        s.pop();
    }

    priority_queue<int> pq;

    pq.push(1);
    pq.push(3);
    pq.push(2);
    pq.push(8);
    pq.push(9);
    pq.push(0);

    cout << "size: " << pq.size() << endl;

    while(pq.empty() != true)
    {
        cout << pq.top() << endl;
        pq.pop();
    }

    queue<int> q;

    q.push(1);
    q.push(3);
    q.push(2);
    q.push(8);
    q.push(9);
    q.push(0);

    cout << "size: " << q.size() << endl;

    while(q.empty() != true)
    {
        cout << q.front() << endl;
        q.pop();
    }
}
int main()
{
	//test_1();
//	test_2();
//	test_3();
//	test_4();
//	test_5();
//	test_6();
	test_7();
  return 0;
}


                                                                                                        
      