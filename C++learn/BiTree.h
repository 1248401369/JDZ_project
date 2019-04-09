#ifndef BITREE_H_INCLUDED
#define BITREE_H_INCLUDED
#include<queue>
#include<stack>
#include<vector>
#include<iostream>
using namespace std;
class BiNode {
public:
	char data;
	BiNode *lchild, *rchild;
};

class BiTree {
private:
	BiNode * root;
	int height;
	void pre_Order(BiNode * t);
	void in_Order(BiNode * t);
	void post_Order(BiNode * t);
	BiNode* create(string &s, int&pos);
	void get_Height(BiNode *t, int h);
public:
	BiTree() { root = NULL; height = 0; }
	///����ǰ��������д���������
	void createBiTree(string s);
	///ǰ�����������
	void preOrder();
	///�������������
	void inOrder();
	///�������������(�ݹ鷽��)
	void postOrder();
	///�������������(ʹ��ջ�ķǵݹ鷽��)
	void postOrder1();
	///�������������
	void levelOrder();
	///�����ĸ߶�
	int getHeight();
	///�������ڵ����󹫹�����
	void ancestor(char A, char B);
};
#endif
#pragma once
