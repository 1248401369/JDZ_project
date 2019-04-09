#include "MySort.h"
#include "MyBinaryTree.h"
#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
#include<list>
#include<vector>
#include <iomanip>
#include<deque>
#include<map>
#include<tuple>


using namespace std;
//float Com(float a, float b)
//{
//	return  -a*log(a) / log(2) - b*log(b) / log(2);
//};

//bool fncomp(char lhs, char rhs) {
//	return lhs < rhs;
//};
//struct classcomp {
//	bool operator()(const char&lhs, const char& rhs)const {
//		return lhs < rhs;
//	}
//};

//template<typename T>
int main() {
	//static int iii = 0;
	//unsigned char c = -2;
	//cout << c << endl;
	//unsigned u = 10;
	//int i = -42;
	//unsigned j = i;
	//cout << j << endl;
	//cout << u + i << endl;

	//unsigned u = 10, u2 = 42;
	//cout << u2 - u << endl;
	//cout << u - u2 << endl;
	//int i = 10, i2 = 42;
	//cout << i2 - i << endl;
	//cout << i - i2 << endl;
	//cout << i - u << endl;
	//cout << u - i << endl;
	/*cout << 3.14159E2 << endl;*/

	//cout << "Who goes with F\145rgus?\012" << endl;

	//int units_sold = 0;
	//cout << units_sold << endl;
	//int units_sold = { 0 };
	//cout << units_sold << endl;
	//int units_sold(0);
	//cout << units_sold << endl;
	//int units_sold{ 0 };
	//cout << units_sold << endl;

	//long double ld = 3.1415926536;
	////int a{ ld }, b = { ld };
	//int c( ld ), d = ld;
	//int a;
	//cout << a << endl;
	//double Double = 3.14;
	//cout << Double << endl;
	//int _;
	//_ = 3;
	//cout << _ << endl;
	/*int sum = 0;*/
	//int i = 100, sum = 0;
	//for (int i = 0; i != 10; ++i)
	//		sum += i;
	//cout << i << " " << sum << endl;

	//int ival = 1.01;
	//cout << ival << endl;
	//int ival = 42;
	//int *p = &ival;
	//cout << *p <<" "<< p << endl;

	//int *p1 = nullptr;
	//int *p2 = 0;

	//int i = 42;
	//int *p1 = &i;
	//*p1 = *p1 * *p1;
	//cout << *p1 <<" "<<i<< endl;

	//const int p = 3;
	//p = 2;

	//int i = 42;
	//const int &r1 = i;
	//const int &r2 = 42;
	//const int &r3 = r1 * 2;
	//int &r4 = r1 * 2;

	//double pi = 3.14;
	//const double *ptr = &pi;
	//*ptr = 23;
	//cout << *ptr << endl;

	//const int s = 3;
	//const int y = 2;
	//constexpr int i = s*y;

	// int s = 3;
	// int y = 2;
	//const int i = s*y;
	//using QAQ = int;

	//typedef char *ptring;
	//const ptring cstr = 0;
	//const ptring *ps;

	//int i = 0;
	//int j = 10;
	//const int s = 3;
	//int * const pi = &i;
	//cout << *pi << endl;

	//pi = &j;
	//cout << *pi << endl;

	//struct Sales_data
	//{
	//	string bookNo;
	//	unsigned units_sold = 0;
	//	double revenue = 0.0;
	//};
	//string s;
	//cin >> s;
	//cout << s << endl;
	//string s;
	//while (getline(cin, s))
	//	cout << s << endl;

	//string s1, s2;
	//cin >> s1 >> s2;
	//string s3 = s1 + s2;
	//cout << s3 << endl;
	//s1 += s2;
	//cout << s1 << endl;
	//string s1 = "hello", s2 = "world";
	//string s3 = s1 + "," + s2 + '\n';
	//cout << s3 << endl;
	//string s5 = "hello" + "sss";
	//cout << s5 << endl;
	//string str("some string");
	//for (auto c : str)
	//	cout << c << endl;
	//string s("Hello World!!!");
	//decltype(s.size()) punct_cnt = 0;
	//for (auto c : s)
	//	if (ispunct(c))

	//		++punct_cnt;
	//cout << punct_cnt
	//	<< " in" << s << endl;
	//for (auto &t : s)
	//	t = toupper(t);
	//cout << s << endl;
	//int i = 0;
	//for (decltype(s.size()) index = 0;
	//	index != s.size() && !isspace(s[index]); ++index)
	//	s[index] = toupper(s[index]);
	//string s;
	//cout << s[0] << endl;
	//vector<unsigned> scores(11, 0);
	//unsigned grade;
	//while (cin >> grade) {
	//	if (grade <= 100)
	//		++scores[grade / 10];
	//}

//////////////////////////////////////////////////////3.18
	//vector<string> svec;
	//string word;
	//while (cin >> word &&word !="end") {
	//	svec.push_back(word);
	//}
	//for (decltype(svec.size()) i= 0; i < svec.size(); i++) {
	//	for (decltype(svec[i].size()) j = 0; j < svec[i].size(); j++)
	//	{
	//		svec[i][j] = toupper(svec[i][j]);
	//		cout << j << endl;
	//	}
	//	cout << svec[i] << endl;
	//}


////////////////////////////////////////////////3.20
	//vector<int> vec;
	//int num;
	//while (cin >> num)
	//	vec.push_back(num);
	//for (decltype(vec.size()) i = 0; i < vec.size(); i += 2)
	//{
	//	if (i == vec.size() - 1)
	//		break;
	//	cout << vec[i] <<"+"<< vec[i + 1]<<"="<< vec[i]+vec[i + 1]<<endl;

	//}
	//cout << "************" << endl;
	//for (decltype(vec.size()) i = 0; i < vec.size(); i++)
	//{
	//	if (i == int(vec.size()/2))
	//		return -1;
	//	cout << vec[i] << "+" << vec[vec.size() - i-1] << "=" << vec[i] + vec[vec.size() - i-1] << endl;

	//}


	/*string s("some string");*/
	//if (s.begin() != s.end()) {
	//	auto it = s.begin();
	//	*it = toupper(*it);
	//	//cout << *it << endl;
	//}
	//for (auto it = s.begin(); it != s.end(); ++it)
	//{
	//	*it = toupper(*it);
	//	cout << *it << endl;
	//}

//////////////////////////////////////////3.23
	//vector<int> vec(10, 1);
	//for (auto it = vec.begin(); it != vec.end(); it++)
	//{
	//	*it = 2 * *it;
	//	cout << *it << endl;
	//}
	//int ia[] = { 0,1,2,3,4,5,6,7,8,9 };
	//auto ia2(ia);
	//*ia2 = 100;
	//cout << *ia << endl;
	//int *b = begin(ia);
	//int *e = end(ia);
	//while (b != e) {
	//	cout << *b << endl;
	//	++b;
	//}

	//int i = 0;
	//const int j = 0;
	///*const int *s = &i;*/
	//int *const pp = &i;
	////*s = 45;
	//*pp = 200;


	//cout << "this is a:" << endl;
	//cout << "hi!" << flush;
	//cout << "adf:" << ends;
	//template<typename T>;
	//vector<int> V; 

	//float a = 5 / 14.0, b = 9 / 14.0;

	//float H_D = Com(a,b);
	//cout << H_D << endl;
	//float H_D_outlook = H_D - 5/14.*Com(3 / 5., 2 / 5.) - 5 / 14.*Com(2 / 5., 3 / 5.);
	//cout << "outlook的:" << H_D_outlook << endl;
	//float H_D_temp = H_D - 4/14.*Com(2 / 4., 2 / 4.) - 6/14.*Com(2/6., 4/6.) - 4/14.*Com(1 / 4., 3 / 4.);
	//cout << "temp的:" << H_D_temp << endl;
	//float H_D_humid = H_D - 7/14.*Com(4 / 7., 3 / 7.) - 7/14.*Com(1 / 7., 6 / 7.);
	//cout << "humid的:" << H_D_humid << endl;
	//float H_D_wind = H_D - 8/14.*Com(2 / 8., 6 / 8.) - 6/14.*Com(3 / 6., 3 / 6.);
	//cout << "wind的:" << H_D_wind << endl;


	//float H_D = Com(3/5.,2/5.);
	//cout << H_D << endl;
	//float H_D_temp = H_D - 2 / 5.*Com(1 / 2., 1 / 2.);
	//cout << "temp的:" << H_D_temp << endl;
	//float H_D_humid = H_D;
	//cout << "humid的:" << H_D_humid << endl;
	//float H_D_wind = H_D - 3/5.*Com(2 / 3., 1/ 3.) - 2/5.*Com(1 / 2., 1 / 2.);
	//cout << "wind的:" << H_D_wind << endl;


	//int i;
	//if (i)
	//	cout << "df" << endl;
	//string s = to_string(i);
	//cout << s << endl;
	//double d = stod(s);
	//cout << d <<endl;
	//list<int> ls{ 1,2,3,4 };
	//ls.remove(0);


	//int a1 = 3;                     ///non-const data
	//int aa1 = 0;
	//const int a2 = a1;             ///const data
	//int * a3 = &a1;                ///non-const data,non-const pointer
	//const int * a4 = &a1;          ///const data,non-const pointer 
	//int * const a5 = &a1;          ///non-const data,const pointer
	//const int * const a7 = &a1;    ///const data,const pointer
	//array<int,10> A{ 1,23 };
	//cout << A.max_size() << endl;
	//extern char a;
	//printf("%c\n", a);
	//msg();

	//array<int, 5> myarray = { 2,16,77,34,50};
	//for (auto it = myarray.begin(); it != myarray.end(); ++it) {
	//	cout << *it << endl;
	//}
	
	//for (auto rit = myarray.cbegin(); rit != myarray.cend(); ++rit) {
	//	cout << *rit << endl;
	//}
	//cout << "fronnt:" << myarray.front() << endl;
	//cout << "back:" << myarray.back() << endl;

	//const char* cstr = "Test string!";
	//array<char, 12> charray;
	//memcpy(charray.data(), cstr, 10);
	//cout << charray.data() << endl;
	//array<int,10> myarray;
	//myarray.fill(10);
	//for (int &x : myarray) {
	//	cout << x << " ";
	//}
	
	//array<int, 5> first = { 10,20,30,40,50 };
	//tuple<int,int,int> second(10,20,30);
	////first.swap(second);
	//for (int &x : first) cout << " " << x;
	//cout << endl;
	//for (int &x : second) cout << " " << x;

	/*tuple_element<0, decltype(first)>::type  myelement;
	myelement = get<2>(first);
	cout<<*/

	//std::array<int, 3> myarray = { 10, 20, 30 };
	//std::tuple<int, int, int> mytuple(10, 20, 30);

	//std::tuple_element<0, decltype(myarray)>::type myelement;  // int myelement
	//int myelement;
	//myelement = std::get<2>(myarray);
	//std::get<2>(myarray) = std::get<0>(myarray);
	//std::get<0>(myarray) = myelement;

	//std::cout << "first element in myarray: " << std::get<0>(myarray) << "\n";
	//std::cout << "first element in mytuple: " << std::get<0>(mytuple) << "\n";
	
	//unsigned int i;
	//deque<int> first;
	//deque<int> second(4, 100);
	//for (auto &i : second) cout << i << endl;
	//deque<int> third(second.begin(), second.end());
	//deque<int> fourth(third);
	//int myints[] = { 16,2,77,29 };
	//deque<int> fifth(myints, myints + sizeof(myints) / sizeof(int));
	//for (deque<int>::iterator it = fifth.begin(); it != fifth.end(); ++it) {
	//	cout << " " << *it;
	//}

	//cout << endl;
	//map<char, int> first;
	//first['a'] = 10;
	//first['b'] = 30;
	//first['c'] = 150;
	//first['d'] = 70;
	//first['s'] = 100;

	//map<char, int> second(first.begin(), first.end());
	//map<char, int> third(second);
	//map<char, int, classcomp> fourth;
	//bool(*fn_pt)(char, char) = fncomp;
	//map<char, int, bool(*)(char, char)>fifth(fn_pt);
	//for (auto &x : first) cout << x.first <<"=>" << x.second << endl;
	//bool ss = true;
	//pair<char, int> highest = *first.begin();
	//map<char, int>::iterator it = first.begin();
	//while (ss = first.value_comp()(*it++, highest)) {
	//	std::cout << it->first << " => " << it->second << " " << ss << '\n';
	//}

	//cout << "a=>" << first.find('a')->second << endl;
	//cout << "s=>" << first.find('s')->second << endl;
	//cout << "b=>" << first.find('b')->second << endl;
	//cout << "c=>" << first.find('c')->second << endl;

	

	//vector<int> V = { 66,1,2,7,9,3,4,5,10,8 };
	//vector<int> &v = V;
	//QuickSort(v, 0, V.size());
	//for (auto &x : v) cout << x << endl;
	//int i = 0;
	//char *str = (char*)malloc(100);
	//assert(str != nullptr);
	//free(str);
	//assert(str != nullptr);
	
	//binaryTreeNode tt;
	
	
	//binaryTreeNode<int> *root;
	//root->element = 23;
	//binaryTree<int> root(9,-1,-1);

	//binaryTree<binaryTreeNode<int>> *tt=new binaryTree<binaryTreeNode<int>>;
	//tt->Creat();
	
	//BinTree a;
	//string s;
	//s = "ABD##E#F##C##";
	//a.creatTree(s);
	//cout << "前序遍历：" << endl;
	//a.preOrder();

	//BiTree a;
	//string s;
	//s = "ABD##E#F##C##";
	//a.createBiTree(s);
	//cout << "前序遍历:" << endl;
	//a.preOrder();
	//cout << "中序遍历：" << endl;
	//a.inOrder();
	//cout << "后序遍历1：" << endl;
	//a.postOrder();
	//cout << "后序遍历2：" << endl;
	//a.postOrder1();
	//cout << "层序遍历：" << endl;
	//a.levelOrder();
	//cout << "树高：" << endl;
	//cout << a.getHeight() << endl;


	//BinTree a;
	//string s;
	//s = "ABD##E#F##C##";
	//a.creatTree(s);
	//cout << "前序遍历:" << endl;
	//a.preOrder();
	//cout << "中序遍历：" << endl;
	//a.inOrder();
	//cout << "后序遍历1：" << endl;
	//a.postOrder();
	//cout << "后序遍历2：" << endl;
	//a.postOrderStrack();
	//cout << "层序遍历：" << endl;
	//a.leveOrder();
	//cout << "树高：" << endl;

	//cout << a.getHeight() << endl;
	//BinaryTreeNode *r;
	//BinTree b;
	//string s = "ABD##E#F##C##";
	//a.creatTree(s);
	//b.creatTree();
	//b.preOrder();
	//b.inOrder();
	//b.postOrder();
	//b.getHeight();
	//cout << r->data << endl;
	
	
	
	//vector<int> v = { 1,4,34,2,67,5,6,7,34,-1 };
	//vector<int> a = v;
	//QuickSort(v,0,v.size());
	//for (auto &x : v) cout << x << endl;
	//vector<int> &aa = a;
	//cout << "***********" << endl;
	//HeapSort(a, 0, a.size());
	//for (auto &x : a) cout << x << endl;

	//chessboard cb;
	//snake s;
	//s.move();

	//for (int i = 0; i < 10; i++) {
	//	int ch = _getch();
	//	cout << ch << endl;
	// }
	//

	//	int num;
	//	while (1) {
	//		if ((num = getch())<127)
	//			cout << num << endl;
	//	}
	//	return 0;
	//}















	
	return 0;
}
