#include "MyBinaryTree.h"

using namespace std;

BinaryTreeNode *BinTree::creat(string &s, int&pos) {  //字符串创建二叉树
	++pos;
	BinaryTreeNode *t;
	if ((unsigned)pos >= s.size()) return NULL;
	else {
		if (s[pos] == '#') t = NULL;
		else {
			t = new BinaryTreeNode;
			t->data = s[pos];
			t->leftChild = creat(s, pos);
			t->rightChild = creat(s, pos);
		}
		return t;
	}
}

void BinTree::creatTree(string s) {  //创建根节点
	int pos = -1;
	root = creat(s, pos);
}

static int i = 0;
BinaryTreeNode* BinTree::creatTree() {//创建二叉树
	char val;
	cin >> val;
	if (val == '#') {
		return NULL;
	}
	else {
		BinaryTreeNode *current = new BinaryTreeNode;
		if (i == 0) root = current;
		i++;
		current->data = val;
		current->leftChild = creatTree();
		current->rightChild = creatTree();
		return current;
	}
}


void BinTree::preOrder() {//前序遍历，调用根节点
	cout << "前序遍历：";
	pre_Oreder(root);
	cout << endl;
}
void BinTree::pre_Oreder(BinaryTreeNode *t) {
	if (t != NULL) {
		cout << t->data << ' ';
		pre_Oreder(t->leftChild);
		pre_Oreder(t->rightChild);
	}
}


void BinTree::inOrder() {//中序遍历，调用根节点
	cout << "中序遍历：";
	in_Order(root);
	cout << endl;
}
void BinTree::in_Order(BinaryTreeNode *t) {
	if (t != NULL) {
		post_Order(t->leftChild);
		cout << t->data << ' ';
		post_Order(t->rightChild);
	}
}

void BinTree::postOrder() {//后序遍历
	cout << "后序遍历：";
	post_Order(root);
	cout << endl;
}

void BinTree::post_Order(BinaryTreeNode *t) {
	if (t != NULL) {
		post_Order(t->leftChild);
		post_Order(t->rightChild);
		cout << t->data << ' ';
	}
}


void BinTree::postOrderStrack() {//
	BinaryTreeNode *p, *r;
	r = NULL;
	p = root;
	stack<BinaryTreeNode*> my_stack;
	while (p != NULL || !my_stack.empty()) {
		if (p) {
			my_stack.push(p);
			p = p->leftChild;
		}
		else {
			p = my_stack.top();
			if (p->rightChild != NULL && p->rightChild != r) {
				p = p->rightChild;
				my_stack.push(p);
				p = p->leftChild;
			}
			else {
				p = my_stack.top();
				my_stack.pop();
				cout << p->data << ' ';
				r = p;
				p = NULL;
			}
		}
	}
	cout << endl;
}


void BinTree::leveOrder() {    //层序遍历
	if (root == NULL) return;
	queue<BinaryTreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		BinaryTreeNode *t;
		t = q.front();
		q.pop();
		cout << t->data << ' ';
		if (t->leftChild != NULL) q.push(t->leftChild);
		if (t->rightChild != NULL) q.push(t->rightChild);
	}
	cout << endl;
}


int BinTree::getHeight() {
	get_Height(root, 0);
	cout << "树深度：" << height << endl;
	return height;
}
void BinTree::get_Height(BinaryTreeNode *t, int h) {
	if (t != NULL) {
		++h;
		if (h > height) height = h;
		get_Height(t->leftChild, h);
		get_Height(t->rightChild, h);
	}
}

//BinaryTreeNode *comAncestor(BinaryTreeNode *root, BinaryTreeNode *A, BinaryTreeNode *B) {
//	if (root == NULL || A == NULL || B == NULL) return{};
//	if (root->data == A->data || root->data == B->data) return root;
//	BinaryTreeNode *left = comAncestor(root->leftChild, A, B);
//	BinaryTreeNode *right = comAncestor(root->rightChild, A,B);
//	if (left != NULL && right != NULL) return root;
//	if (left == NULL) return right;
//	else return left;
//}

