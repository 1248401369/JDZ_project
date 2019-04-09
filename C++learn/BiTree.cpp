#include "BiTree.h"

using namespace std;
///�ݹ鴴���������������#��ʾ�սڵ�
BiNode *BiTree::create(string &s, int &pos) {
	++pos;
	BiNode * t;
	if ((unsigned)pos >= s.size())
		return NULL;
	else {
		if (s[pos] == '#')
			t = NULL;
		else {
			t = new BiNode;
			t->data = s[pos];
			t->lchild = create(s, pos);
			t->rchild = create(s, pos);
		}
		return t;
	}
}
///����ǰ��������д���������
void BiTree::createBiTree(string s) {
	int pos = -1;
	root = create(s, pos);
}
///ǰ�����������
void BiTree::preOrder() {
	pre_Order(root);
	cout << endl;
}
void BiTree::pre_Order(BiNode * t) {
	if (t != NULL) {
		cout << t->data << ' ';
		pre_Order(t->lchild);
		pre_Order(t->rchild);
	}
}
///�������������
void BiTree::inOrder() {
	in_Order(root);
	cout << endl;
}
void BiTree::in_Order(BiNode *t) {
	if (t != NULL) {
		in_Order(t->lchild);
		cout << t->data << ' ';
		in_Order(t->rchild);
	}
}
///�������������(�ݹ鷽��)
void BiTree::postOrder() {
	post_Order(root);
	cout << endl;
}
void BiTree::post_Order(BiNode *t) {
	if (t != NULL) {
		post_Order(t->lchild);
		post_Order(t->rchild);
		cout << t->data << ' ';
	}
}
///�������������(ʹ��ջ�ķǵݹ鷽��)
///���������ȱ������������ٱ��������������������ڵ�
///����һ���ڵ���ԣ���һֱ����������ڵ�
///Ȼ����r��¼�������Ƿ���������û�б����������������
void BiTree::postOrder1() {
	///p��ʾ��ǰ���ڵ�ָ�룬
	///r��ʾ������ʵ����ڵ�ָ��
	BiNode *p, *r;
	r = NULL;
	p = root;
	stack<BiNode*> my_stack;
	while (p != NULL || !my_stack.empty()) {
		if (p) {
			///һֱ�ߵ����������
			my_stack.push(p);
			p = p->lchild;
		}
		else {
			p = my_stack.top();
			///���������û�б���������������
			if (p->rchild != NULL && p->rchild != r) {
				p = p->rchild;
				my_stack.push(p);
				///ע��������Ҫ����ת����Ϊ���������ת��
				///��������������ڵ�����
				p = p->lchild;

			}
			///����������ڵ�
			else {
				p = my_stack.top();
				my_stack.pop();
				cout << p->data << ' ';
				///������������Ľڵ�
				r = p;
				///��������Ľڵ���ΪNULL��������һ���ڵ�ı���
				p = NULL;
			}
		}
	}
	cout << endl;
}
///ʹ�ö��н��в������������
void BiTree::levelOrder() {
	if (root == NULL)
		return;
	queue<BiNode*> q;
	q.push(root);
	while (!q.empty()) {
		BiNode * t;
		t = q.front();
		q.pop();
		cout << t->data << ' ';
		if (t->lchild != NULL)
			q.push(t->lchild);
		if (t->rchild != NULL)
			q.push(t->rchild);
	}
	cout << endl;
}
///�����ĸ߶�
int BiTree::getHeight() {
	get_Height(root, 0);
	return height;
}
void BiTree::get_Height(BiNode *t, int h) {
	if (t != NULL) {
		++h;
		if (h>height)
			height = h;
		get_Height(t->lchild, h);
		get_Height(t->rchild, h);
	}
}
