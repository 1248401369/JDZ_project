#ifndef MYBINARYTREE_H
#define MYBINARYTREE_H
#include<iostream>
#include<stack>
#include<queue>
//template<typename T>
using namespace std;
class BinaryTreeNode  //二叉树节点
{
public:
	char data;
	BinaryTreeNode *leftChild;
	BinaryTreeNode *rightChild;
};

//template<typename T>
class BinTree{
private:
	
	int height;
	void pre_Oreder(BinaryTreeNode *t);
	void in_Order(BinaryTreeNode *t);
	void post_Order(BinaryTreeNode *t);
	BinaryTreeNode* creat(string &s, int &pos);
	void get_Height(BinaryTreeNode *t, int h);
public:
	BinaryTreeNode *root;
	BinTree() { root = NULL; height = 0; };
	void creatTree(string s);//以字符串形式创建二叉树
	BinaryTreeNode* creatTree();//重载，输出字符串创建二叉树
	void preOrder();
	void inOrder();
	void postOrder();
	void postOrderStrack();
	void leveOrder();
	int getHeight();
	//BinaryTreeNode* comAncestor(BinaryTreeNode *root, BinaryTreeNode *A, BinaryTreeNode *B);
};


#endif
#pragma once
