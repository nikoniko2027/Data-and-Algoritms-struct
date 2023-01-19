#pragma once
#include <iostream>

using namespace std;

struct Tree {
	int i; // Значение
	Tree* left; // Указатель на левого ребенка
	Tree* right; // Указатель на правого ребенка
	Tree* parent; // Указатель на родителя
	bool color; // Цвет
};

class RB_Tree {
private:
	Tree* root; 
	Tree* null;

	void print(Tree* root, bool last) {
		if (root != null) {
			string x;
			if (root->color)
				x = "К";
			else
				x = "Ч";
			cout << root->i << "[" << x << "] ";
			print(root->left, false);
			print(root->right, true);
		}
	}

	void AutoDel(Tree* x) {
		Tree* X;
		while (x != root && x->color == false) {
			if (x == x->parent->left) {
				X = x->parent->right;
				if (X->color == true) {
					X->color = false;
					x->parent->color = true;
					LRot(x->parent);
					X = x->parent->right;
				}

				if (X->left->color == false && X->right->color == false) {
					X->color = true;
					x = x->parent;
				}
				else {
					if (X->right->color == false) {
						X->left->color = false;
						X->color = true;
						RRot(X);
						X = x->parent->right;
					}

					X->color = x->parent->color;
					x->parent->color = false;
					X->right->color = false;
					LRot(x->parent);
					x = root;
				}
			}
			else {
				X = x->parent->left;
				if (X->color == true) {
					X->color = false;
					x->parent->color = true;
					RRot(x->parent);
					X = x->parent->left;
				}

				if (X->right->color == false && X->right->color == false) {
					X->color = true;
					x = x->parent;
				}
				else {
					if (X->left->color == false) {
						X->right->color = false;
						X->color = true;
						LRot(X);
						X = x->parent->left;
					}

					X->color = x->parent->color;
					x->parent->color = false;
					X->left->color = false;
					RRot(x->parent);
					x = root;
				}
			}
		}
		x->color = false;
	}

	void Trans(Tree* x, Tree* c) {
		if (x->parent == NULL)
			root = c;
		else if (x == x->parent->left)
			x->parent->left = c;
		else
			x->parent->right = c;
		c->parent = x->parent;
	}

	void DelNode(Tree* tree, int x) {
		Tree* z = null;
		Tree* X;
		while (tree != null) {
			if (tree->i == x)
				z = tree;

			if (tree->i <= x)
				tree = tree->right;
			else
				tree = tree->left;
		}

		if (z == null) {
			cout << "\n\nТакой элемент не найден" << endl;
			return;
		}

		Tree* y;
		y = z;
		int c = y->color;
		if (z->left == null) {
			X = z->right;
			Trans(z, z->right);
		}
		else if (z->right == null) {
			X = z->left;
			Trans(z, z->left);
		}
		else {
			y = Last(z->right);
			c = y->color;
			X = y->right;
			if (y->parent == z)
				X->parent = y;
			else {
				Trans(y, y->right);
				y->right = z->right;
				y->right->parent = y;
			}

			Trans(z, y);
			y->left = z->left;
			y->left->parent = y;
			y->color = z->color;
		}
		delete z;
		if (c == false)
			AutoDel(X);
	}

	void Insert(Tree* k) {
		Tree* u;
		while (k->parent->color == true) {
			if (k->parent == k->parent->parent->right) {
				u = k->parent->parent->left;
				if (u->color == true) {
					u->color = false;
					k->parent->color = false;
					k->parent->parent->color = true;
					k = k->parent->parent;
				}
				else {
					if (k == k->parent->left) {
						k = k->parent;
						RRot(k);
					}
					k->parent->color = false;
					k->parent->parent->color = true;
					LRot(k->parent->parent);
				}
			}
			else {
				u = k->parent->parent->right;
				if (u->color == true) {
					u->color = false;
					k->parent->color = false;
					k->parent->parent->color = true;
					k = k->parent->parent;
				}
				else {
					if (k == k->parent->right) {
						k = k->parent;
						LRot(k);
					}
					k->parent->color = false;
					k->parent->parent->color = true;
					RRot(k->parent->parent);
				}
			}
			if (k == root)
				break;
		}
		root->color = false;
	}

public:
	RB_Tree() {
		null = new Tree;
		null->color = false;
		null->left = NULL;
		null->right = NULL;
		root = null;
	}

	Tree* Last(Tree* x) {
		while (x->left != null)
			x = x->left;
		return x;
	}

	void LRot(Tree* x) {
		Tree* y = x->right;
		x->right = y->left;
		if (y->left != null)
			y->left->parent = x;
		y->parent = x->parent;
		if (x->parent == NULL)
			root = y;
		else if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
		y->left = x;
		x->parent = y;
	}

	void RRot(Tree* x) {
		Tree* y = x->left;
		x->left = y->right;
		if (y->right != null)
			y->right->parent = x;
		y->parent = x->parent;
		if (x->parent == NULL)
			root = y;
		else if (x == x->parent->right)
			x->parent->right = y;
		else
			x->parent->left = y;
		y->right = x;
		x->parent = y;
	}

	void Push(int X) {
		Tree* tree = new Tree;
		tree->parent = NULL;
		tree->i = X;
		tree->left = null;
		tree->right = null;
		tree->color = true;

		Tree* y = NULL;
		Tree* x = root;

		while (x != null) {
			y = x;
			if (tree->i < x->i)
				x = x->left;
			else
				x = x->right;
		}

		tree->parent = y;
		if (y == NULL)
			root = tree;
		else if (tree->i < y->i)
			y->left = tree;
		else
			y->right = tree;

		if (tree->parent == NULL) {
			tree->color = false;
			return;
		}

		if (tree->parent->parent == NULL)
			return;

		Insert(tree);
	}

	void Delete(int x) {
		DelNode(root, x);
	}

	void Print() {
		if (root)
			print(root, true);
	}
};