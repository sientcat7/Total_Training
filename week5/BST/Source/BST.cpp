#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<queue>
#include"BSTree.h"
using namespace std;

Status BST_init(BinarySortTreePtr *hbst) {
		NodePtr p = (NodePtr)malloc(sizeof(NodePtr));
		if (p == NULL) {
			printf("��ʼ��ʧ��\n");
			return false;
		}
		else {
			p->left = NULL;
			p->right = NULL;
			(*hbst)->root = p;
			printf("��ʼ���ɹ�\n");
			return true;
		}
}

Status BST_search(BinarySortTreePtr *hbst, ElemType data) {
	if (hbst == NULL) {
		printf("��������û�г�ʼ�������ʼ����������\n");
		return false;
	}
	else {
		BinarySortTreePtr p = *hbst;
		if (data == (*hbst)->root->value) {
			printf("�ڵ����\n");
			return true;
		}
		else{
			while (p->root->right || p->root->left) {
				if (data > p->root->value) {
					p->root = p->root->right;
				}
				if (data < p->root->value) {
					p->root = p->root->left;
				}
				if (data == p->root->value) {
					printf("�ڵ����\n");
					return true;
				}
			}
			printf("�ڵ㲻����");
			return false;
		}
	}
}

Status BST_insert(BinarySortTreePtr *hbst, ElemType data) {
	if (hbst == NULL) {
		printf("��������û�г�ʼ�������ʼ����������\n");
		return false;
	}
	else {
		if (!BST_search(hbst, data)) {
			BinarySortTreePtr p = *hbst;
			while (p->root->right || p->root->left) {
				if (data > (p->root->value)) {
					p->root = p->root->right;
				}
				if (data < (p->root->value)) {
					p->root = p->root->left;
				}
			}
			if (data > p->root->value) {
				Node *q = (Node*)malloc(sizeof(Node));
				q->value = data;
				q->right = NULL;
				q->right = NULL;
				p->root->right = q;
				printf("����ڵ�ɹ�\n");
				return true;
			}
			else {
				Node* q = (Node*)malloc(sizeof(Node));
				q->value = data;
				q->right = NULL;
				q->right = NULL;
				p->root->left = q;
				printf("����ڵ�ɹ�\n");
				return true;
			}
		}
	}
}

Status BST_delete(BinarySortTreePtr *hbst, ElemType data) {
	if (hbst == NULL) {
		printf("��������û�г�ʼ�������ʼ����������\n");
		return false;
	}
	if (!BST_search(hbst, data)) {
		printf("��������û����Ҫɾ����ֵ\n");
		return false;
	}
	BinarySortTreePtr p = *hbst;
	BinarySortTreePtr parent = p;
	Node *s,*q;
	while (!p) {
		if (p->root->value == data) break;
		parent = p;
		p->root = (p->root->value < data) ? p->root->right : p->root->left;
	}
	if (p->root->left == NULL && p->root->right == NULL) {
		if (parent->root->left != NULL && parent->root->left->value == data) {
			parent->root->left = NULL;
		}
		if (parent->root->right != NULL && parent->root->right->value == data) {
			parent->root->right = NULL;
		}
		printf("ɾ���ɹ�\n");
		return true;
	}
	else if (p->root->left != NULL && p->root->right == NULL) {
		s = p->root->left;
		parent->root->left = s;
		free(p);
	}
	else if (p->root->right != NULL && p->root->left == NULL) {
		s = p->root->right;
		parent->root->right = s;
	}
	else {
		q = p->root;
		s = p->root->right;
		while (s->right != NULL) {
			q = s;
			s = s->right;
		}
		p->root->value = s->value;
		if (q != p->root) {
			q->right = s->left;
		}
		else {
			q->left = s->left;
		}
		free(s);
		printf("ɾ���ɹ�\n");
		return true;
	}
}

void visit(Node pnode) {
	printf("%2d", pnode.value);

}

void NodeTraverse(Node* node, void (*visit)(Node node), int n) {
	if (n == 1) {
		if (!node) {
			visit(*node);
			NodeTraverse(node->left, visit, n);
			NodeTraverse(node->right, visit, n);
		}
	}
	if (n == 2) {

	}
}
Status BST_preorderI(BinarySortTreePtr *hbst) { //�ݹ��������
	int n = 1;
	NodeTraverse((*hbst)->root, &visit, n);
	return true;
}

Status BST_preorderR(Node *bst, void (*visit)(NodePtr)) { //�ǵݹ��������
	if (!bst) {
		BST_preorderR(bst->left, visit);
		visit(bst);
		BST_preorderR(bst->right, visit);
	}
	else {
		stack<Node*> prBst;
		Node* p = bst;
		prBst.push(p);
		while (!prBst.empty()) {
			p = prBst.top();
			visit(p);
			prBst.pop();  //ջΪFILO�Ľṹ��Ϊ����Ҫ�Ƚ�������ѹ��ջ
			if (p->right) {
				prBst.push(p->right);
			}
			if (p->left) {
				prBst.push(p->left);
			}
	}
		printf("\n");
		printf("�����ɹ�\n");
		return true;
	}
}


Status BST_inorderI(NodePtr *bst , void (*visit)(NodePtr)) { //�������
	if (!bst) {
		BST_preorderR((*bst)->left, visit);
		visit(*bst);
		BST_preorderR((*bst)->right, visit);
	}
	return true;
}

Status BST_inorderR(Node *bst, void (*visit)(NodePtr)) { //�ǵݹ��������
	if (bst == NULL) {
		printf("ĿǰΪ�����������ڵ��������\n");
		return false;
	}
	else {
		stack<Node*> inBst;
		Node* p = bst;
		while (!inBst.empty() || bst != NULL) {
			if (p) {
				inBst.push(p);
				p = p->left;
			}
			else {  //���ڵ�Ϊ��ʱ��˵����һ���ڵ��µ��������Ѿ�û��ֵ�ˣ���Ҫ����һ���ڵ㵯������ֵ��ӡ����ȥ����������
				p = inBst.top(); //��ʱ�ڵ㷵����һ��
				visit(p);
				inBst.pop();
				p = p->right;
			}
		}
		printf("\n");
		printf("�������\n");
		return true;
	}
}

Status BST_postorderI(NodePtr *bst, void (*visit)(NodePtr)) { //�ݹ�������
	if (!bst) {
		BST_preorderR((*bst)->left, visit);
		BST_preorderR((*bst)->right, visit);
		visit(*bst);
	}
	return true;
}
Status BST_postorderR(Node *bst, void (*visit)(NodePtr)) {
	if (bst == NULL) {
		printf("ĿǰΪ�����������ڵ�������\n");
		return false;
	}
	else {
		Node *p = bst;
		stack<Node*> postbst1, postbst2; //postbst1���ڱ����ڵ�,postbst2���ڵ�����ֵ
		postbst1.push(p);
		//��postbst1��������ѹ��postbst2��
		while (!postbst1.empty()) {
			p = postbst1.top();
			postbst2.push(p);
			postbst1.pop();
			//��ѹ��������
			if (p->left) {
				postbst1.push(p->left);
			}
			//��ѹ��������
			if (p->right) {
				postbst1.push(p->right);
			}
		}
		while (!postbst2.empty()) {
			Node *r = postbst2.top();
			visit(r);
			postbst2.pop();
		}
	}
	printf("\n");
	printf("�������\n");
	return true;
}

Status BST_levelOrder(Node* bst, void (*visit)(NodePtr)) { //��α���
	if (bst == NULL) {
		printf("ĿǰΪ�����������ڵ��������\n");
		return false;
	}
	else {
		Node* p;
		queue<Node*>lebst;
		lebst.push(bst);
		while (!lebst.empty()) {
			p = lebst.front();
			lebst.pop();
			visit(p);
			if (p->left) {
				lebst.push(p->left);
			}
			if (p->right) {
				lebst.push(p->right);
			}
		}
		printf("\n");
		printf("�������\n");
		return true;
	}
}
