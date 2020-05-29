#pragma once
#include <glut.h>
#include <iostream>
#include<string>
#include<vector>
using namespace std;

struct SGlutContextStruct {
	void* tree;
	int window_width, window_height, shift, k, R, x, y, state;
};
extern SGlutContextStruct glutContext;
extern vector<int> Value;

template<class T>
void initWindow(int argc, char** argv);
template <class T>
void display(void);
static void reshape(int w, int h);
template <class T>
static void mouseMove(int x, int y);
int getPoss(int index, int width, int curLevel, int maxLevel);
template <class T>
static void mouseClick(int btn, int stat, int x, int y);
 void drawLine(int x1, int y1, int x2, int y2);
 void drawButtons();
 void drawFillCircle(int x, int y, int R);
 void drawBlueCircle(int x, int y, int R);
template<class T>
static void drawText(T text, void* font, int text_x, int text_y, int R, int k);

extern const int SHIFT;
extern const int WIDTH;
extern const int HEIGHT;


template <class T>
class Tree {
public:
	int node_x;
	int node_y;
	int text_x;
	int text_y;

	Tree(T); 
	~Tree(); 
	void insertLeft(T); 
	void insertRight(T); 
	void insertNode(T dt);
	void setData(T dt) { data = dt; } 
	T getData()
	{ 
	if (this != NULL) return data;
	else return NULL;
	} 
	Tree<T>* getLeft() { return left; } 
	Tree<T>* getRight() { return right; } 
	Tree<T>* getParent() { return parent; } 

	void addLeftTree(Tree<T>* tree) { left = tree; } 
	void addRightTree(Tree<T>* tree) { right = tree; } 
	void deleteNode();
	static void inOrder(Tree<T>* node, int);
	static void preOrder(Tree<T>*);
	Tree<T>* copyTree(); 
	void printTree(int); 
	int getAmountOfNodes(); 
	int getHeight(); 
	void deleteTree() { delete this; } 
	Tree<T>* replaceNULLforEmpty();

	void findElement_insertLeft(Tree<T>*, T, T); 
	void findElement_insertRight(Tree<T>*, T, T); 
	static Tree<T>* balancedTree(int n); 
	void setCoordsForText(int k, int shift);
	void setCoordsForNode(int window_width, int window_height,
		int shift, int tree_width, int tree_height, int x, int y, int R);
	Tree* getNodeByCoords(int x, int y, int R);
	void drawTree(int argc, char** argv, int window_width, int window_height, int shift, int k);
	Tree<T>* findElement(T);
	Tree<T>* next();
	Tree<T>* findMin();

private:
	T data;
	Tree* left;
	Tree* right;
	Tree* parent;
};


template<class T>
Tree<T>::Tree(T dt)
{ 
	data = dt; 
	left = NULL; 
	right = NULL;
	parent = NULL;
}

template<class T>
Tree<T>::~Tree() 
{ 
	delete this->left;
	delete this->right;
}

template<class T>
void Tree<T>::preOrder(Tree<T>* node)
{
	if (node != NULL)
	{
		if (node->getData() % 2 == 0)
		{
			node->deleteNode();
		}
		preOrder(node->left);
		preOrder(node->right);
	}
}

template<class T>
void Tree<T>::inOrder(Tree<T>* node,int dt) 
{
	if (node != NULL) {
		inOrder(node->left,dt);
		if (node->getData() == dt)
		{
			node->deleteNode();
		}
		inOrder(node->right,dt);
	}
}






template<class T>
void Tree<T>::printTree(int level) 
{
	if (this != NULL) {
		this->left->printTree(level + 1);
		for (int i = 1; i < level; i++) cout << " ";
		cout << this->getData() << endl;
		this->right->printTree(level + 1);
	}
}

template<class T>
Tree<T>* Tree<T>::copyTree()
{
	Tree<T>* tree = new Tree<T>(this->data);
	if (this->parent != NULL)
		tree->parent = this->parent;
	if (this->left != NULL)
		tree->left = this->left->copyTree();
	if (this->right != NULL)
		tree->right = this->right->copyTree();
	return tree;
}

template <class T>
void Tree<T>::insertLeft(T dt) 
{
	Tree<T>* node = new Tree(dt);
	if (this->left != NULL) this->left->parent = node;		
	node->left = this->left; 
	this->left = node; 
	node->parent = this; 
}

template<class T>
void Tree<T>::insertRight(T dt) 
{
	Tree<T>* node = new Tree(dt);
	if (this->right != NULL)
		this->right->parent = node;
	node->right = this->right;
	this->right = node;
	node->parent = this;
}

template <class T>
Tree<T>* Tree<T>::balancedTree(int n)
{
	if (n == 0) return NULL;
	cout << "data=";
	T dt;
	cin >> dt;
	Tree<T>* tree = new Tree<T>(dt);
	tree->addLeftTree(balancedTree(n / 2));
	tree->addRightTree(balancedTree(n - n / 2 - 1));
	return tree;
}

template <class T>
void Tree<T>::findElement_insertLeft(Tree<T>* node, T dt1, T dt2)
{
	if (node != NULL) {
		findElement_insertLeft(node->getLeft(), dt1, dt2);
		if (dt1 == node->getData()) node->insertLeft(dt2);
		findElement_insertLeft(node->getRight(), dt1, dt2);
	}
}

template <class T>
void Tree<T>::findElement_insertRight(Tree<T>* node, T dt1, T dt2) 
{
	if (node != NULL) {
		findElement_insertRight(node->getLeft(), dt1, dt2);
		if (dt1 == node->getData()) node->insertRight(dt2);
		findElement_insertRight(node->getRight(), dt1, dt2);
	}
}



template <class T>
int Tree<T>::getHeight()
{
	int h1 = 0, h2 = 0, hadd = 0;
	if (this == NULL)return 0;
	if (this->left != NULL) h1 = this->left->getHeight();
	if (this->right != NULL) h2 = this->right->getHeight();
	if (h1 >= h2) return h1 + 1;
	else return h2 + 1;
}

template<class T>
int Tree<T>::getAmountOfNodes() 
{
	if (this == NULL)return 0;
	if ((this->left == NULL) && (this->right == NULL)) return 1;
	int l = 0;
	int r = 0;
	if (this->left != NULL) l = this->left->getAmountOfNodes();
	if (this->right != NULL) r = this->right->getAmountOfNodes();
	return (l + r + 1);
}


template <class T>
Tree<T>* Tree<T>::replaceNULLforEmpty()
{
	Tree<T>* node = this->copyTree();
	int h = node->getHeight();
	node = replace_help(node, h);
	return node;
}

template <class T>
Tree<T>* replace_help(Tree<T>* node, int h)
{
	int curLevel = getLevel(node);
	if ((node->getLeft() == NULL) && (curLevel != h - 1))
	{
		node->insertLeft(NULL);
	}
	if ((node->getRight() == NULL) && (curLevel != h - 1))
	{
		node->insertRight(NULL);
	}
	if (node->getLeft() != NULL) node->addLeftTree(replace_help(node->getLeft(), h));
	if (node->getRight() != NULL) node->addRightTree(replace_help(node->getRight(), h));
	return node;
}

template <class T>
void Tree<T>::insertNode(T dt) {
	Tree<T>* tree = this;
	while (tree != NULL) {
		if (dt >= tree->data)
		{
			if (tree->right != NULL) 
			{
				tree = tree->right;
			}
			else
			{
				Tree<T>* t = new Tree<T>(dt);
				t->parent = tree;
				tree->right = t;
				break;
			}
		}
		else if (dt < tree->data)
		{
			if (tree->left != NULL)
			{
				tree = tree->left;
			}
			else 
			{
				Tree<T>* t = new Tree<T>(dt);
				t->parent = tree;
				tree->left = t;
				break;
			}
		}
	}
}

template<class T>
void Tree<T>::deleteNode() {
	Tree<T>* e = this;
	Tree<T>* p = e->parent;
	if ((e->left == NULL) && (e->right == NULL))
	{
		if (p->left == e) p->left = NULL;
		if (p->right == e) p->right = NULL;
	}
	else if ((e->left == NULL) || (e->right == NULL))
	{
		if (e->left == NULL) 
		{
			if (p->left == e) p->left = e->right;
			else p->right = e->right;
			e->right->parent = p;
		}
		else 
		{
			if (p->left == e) p->left = e->left;
			else p->right = e->left;
			e->left->parent = p;
		}
	}
	else {
		Tree<T>* s = e->next(); 
		e->data = s->data;
		if (s->parent->left == s) 
		{
			s->parent->left = s->right;
			if (s->right != NULL) s->right->parent = s->parent;
				
		}
		else 
		{
			s->parent->right = s->right;
			if (s->right != NULL) s->right->parent = s->parent;
				
		}
	}

}

template <class T>
Tree<T>* Tree<T>::findElement(T dt) 
{
	if ((this == NULL) || (dt == this->data)) return this;	
	if (dt < this->data) return this->left->findElement(dt);
	else return this->right->findElement(dt);
}

template <class T>
Tree<T>* Tree<T>::next() 
{
	Tree<T>* tree = this;
	if (tree->right != NULL) return tree->right->findMin();
	Tree<T>* t = tree->parent;
	while ((t != NULL) && (tree == t->right)) 
	{
		tree = t;
		t = t->parent;
	}
	return t;
}

template <class T>
Tree<T>* Tree<T>::findMin()
{
	if (this->left == NULL) return this;
	return this->left->findMin();
}


template<class T>
int getLevel(Tree<T>* tree) 
{
	if (tree->getParent() == NULL) return 0;
		
	else return getLevel(tree->getParent()) + 1;
}

template <class T>
void Tree<T>::setCoordsForNode(int window_width, int window_height,
	int shift, int tree_width, int tree_height, int x, int y, int R)
{
	//это условие не выполняется, когда дерево состоит из одного элемента
	if (tree_width != tree_height)
	{
		//коэффициент пропорциональности по оси Ох
		int k_x = (window_width - 2 * (shift + R)) / (tree_width - 1);
		//коэффициент пропорциональности по оси Оy
		int k_y = (window_height - 2 * (shift + R)) / (tree_height - 1);
		//x-координата узла
		node_x = node_x = k_x * x + shift + R;
		//у-координата узла
		node_y = window_height - k_y * y - shift - R;
	}
	else
	{
		//x-координата узла
		node_x = window_width / 2;
		//у-координата узла
		node_y = window_height / 2;
	}
}

template<class T>
void Tree<T>::setCoordsForText(int k, int R)
{
	//х-координата первого символа текста
	text_x = node_x - 3 * R / 4;
	//у-координата первого символа текста
	text_y = node_y - 3 * R / (4 * k);
}

template<class T>
Tree<T>* Tree<T>::getNodeByCoords(int x, int y, int R)
{
	Tree<T>* node = this;
	node = get_help(node, x, y, R);
	return node;
}

template<class T>
Tree<T>* get_help(Tree<T>* node, int x, int y, int R)
{
	if (pow(x - node->node_x, 2) + pow(y - node->node_y, 2) <= pow(R, 2))
		return node;
	Tree<T>* temp = NULL;
	if (node->getLeft() != NULL)
		temp = get_help(node->getLeft(), x, y, R);
	if (temp != NULL)
		return temp;
	if (node->getRight() != NULL)
		temp = get_help(node->getRight(), x, y, R);
	return temp;
}

struct pos 
{
	int col; 
	int str; 
};


template<class T>
void Tree<T>::drawTree(int argc, char** argv, int window_width, int window_height, int shift, int k) 
{
	Tree<T>* temp = this->copyTree();
	glutContext.tree = temp;
	glutContext.window_width = window_width;
	glutContext.window_height = window_height;
	glutContext.shift = shift;
	glutContext.k = k;
	initWindow<T>(argc, argv);
}

template<class T>
static void drawText(T text, void* font, int text_x, int text_y, int R, int k)
{
	glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(text_x, text_y, 0.0);
	string s = to_string(text);
	char* s1 = new char[s.size() + 1];
	for (int i = 0; i < s.size(); i++) 
	{
		s1[i] = s.at(i);
	}
	s1[s.size()] = 0;
	char* c;
	int max_char_width = 0;
	int char_width = 0;
	for (c = s1; *c != '\0'; c++) 
	{
		char_width = glutStrokeWidth(font, *c);
		if (max_char_width < char_width) max_char_width = char_width;
	}
	float expand_x = (float)1.5 * R / (float)(k * max_char_width);
	float expand_y = (float)1.5 * R / (float)(k * 100);
	glScalef(expand_x, expand_y, 1.0);
	for (c = s1; *c != '\0'; c++)
	glutStrokeCharacter(font, *c);
	glPopMatrix();
}

template <class T>
void display(void) 
{
	Tree<T>* tree = ((Tree<T>*)glutContext.tree)->copyTree();
	tree = tree->replaceNULLforEmpty();
	int k = glutContext.k;
	int window_width = glutContext.window_width;
	int window_height = glutContext.window_height;
	int shift = glutContext.shift;
	int height = tree->getHeight();
	int maxLeafs = pow(2, height - 1); //максимальное число листов на нижнем уровне (нумерация с нуля)
	int width = 2 * maxLeafs - 1; //минимальная ширина дерева для печати (не конечная, но необходимая)
	int curLevel = 0; //номер строки (на выводе)
	int index = 0; //номер элемента в строке (нумерация с нуля)
	int factSpaces = getPoss(index, width, curLevel, height - 1); //позиция корня (число пробелов перед ним)
	pos node;
	vector<Tree<T>*> V;
	vector<pos> Vi;
	int R; //радиускруга
	R = (window_width - 2 * shift) / (2 * width - 1);
	if (2 * R * height > (window_height - 2 * shift)) 
	{
		R = (window_height - 2 * shift) / (2 * height - 1);
	}
	glutContext.R = R;
	tree->setCoordsForNode(window_width, window_height, shift, width, height, factSpaces, curLevel, R); //установили координаты корня при рисовании
	V.push_back(tree);
	node.col = factSpaces;
	node.str = curLevel;
	Vi.push_back(node);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(2);
	glEnable(GL_POINT_SMOOTH);
	for (int i = 0; i < tree->getAmountOfNodes(); i++) {
		if (pow(2, curLevel) <= index + 1)
		{
			index = 0;
			curLevel++;
		}
		if (V.at(i)->getLeft() != NULL)
		{
			V.push_back(V.at(i)->getLeft());
			factSpaces = getPoss(index, width, curLevel, height - 1);
			node.col = factSpaces;
			node.str = curLevel;
			Vi.push_back(node);
			index++;
			V.at(i)->getLeft()->setCoordsForNode(window_width, window_height, shift, width, height, factSpaces, curLevel, R);
			if (V.at(i)->getLeft()->getData() != NULL) {
				int x1 = V.at(i)->node_x;
				int y1 = V.at(i)->node_y;
				int x2 = V.at(i)->getLeft()->node_x;
				int y2 = V.at(i)->getLeft()->node_y;
				drawLine(x1, y1, x2, y2);
			}
		}
		if (V.at(i)->getRight() != NULL) {
			V.push_back(V.at(i)->getRight());
			factSpaces = getPoss(index, width, curLevel, height - 1);
			node.col = factSpaces;
			node.str = curLevel;
			Vi.push_back(node);
			index++;
			V.at(i)->getRight()->setCoordsForNode(window_width, window_height, shift, width, height, factSpaces, curLevel, R);
			if (V.at(i)->getRight()->getData() != NULL) 
			{
				int x1 = V.at(i)->node_x;
				int y1 = V.at(i)->node_y;
				int x2 = V.at(i)->getRight()->node_x;
				int y2 = V.at(i)->getRight()->node_y;
				drawLine(x1, y1, x2, y2);
			}
		}
		if (V.at(i)->getData() != NULL) 
		{
			if (glutContext.state == 0)
			{
				drawFillCircle(V.at(i)->node_x, V.at(i)->node_y, R);
			}
			else
			{
				glClear(GL_COLOR_BUFFER_BIT);
				drawFillCircle(V.at(i)->node_x, V.at(i)->node_y, R);
				if ((tree->getNodeByCoords(glutContext.x, glutContext.y, R)->node_x == V.at(i)->node_x)
					& (tree->getNodeByCoords(glutContext.x, glutContext.y, R)->node_y == V.at(i)->node_y))
					drawBlueCircle(V.at(i)->node_x, V.at(i)->node_y, R);
			}
			V.at(i)->setCoordsForText(k, R);
			drawText(V.at(i)->getData(), GLUT_STROKE_ROMAN, V.at(i)->text_x, V.at(i)->text_y, R, k);
		}
	}
	drawButtons();
	glutSwapBuffers();
	glDisable(GL_POINT_SMOOTH);

}

template<class T>
void initWindow(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(glutContext.window_width, glutContext.window_height);
	glutSetWindow(glutCreateWindow("Дерево"));
	glutDisplayFunc(display<T>);
	glutReshapeFunc(reshape);
	glutPassiveMotionFunc(mouseMove<T>);
	glutMouseFunc(mouseClick<T>);
	glutMainLoop();
}

static void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, (GLsizei)w, 0, (GLsizei)h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glutContext.window_width = w;
	glutContext.window_height = h;
	glutPostRedisplay();
}

template <class T>
static void mouseMove(int x, int y) 
{
	Tree<T>* tree = (Tree<T>*)glutContext.tree;
	int R = glutContext.R;
	Tree<T>* node = tree->getNodeByCoords(x, glutContext.window_height - y, R);
	if (node != NULL)
	{
		glutContext.x = x;
		glutContext.y = glutContext.window_height - y;
		glutContext.state = 1;
		glutPostRedisplay();
	}
	else
	{
		glutContext.state = 0;
		glutPostRedisplay();
	}

}

template <class T>
static void mouseClick(int btn, int stat, int x, int y) 
{
	Tree<T>* temp = ((Tree<T>*)glutContext.tree);
	if (stat == GLUT_DOWN) 
	{
		int k;
		if (x > SHIFT && x < 100 && y > SHIFT && y < 40) {
			cout << "Значение: ";
			cin >> k;
			temp->insertNode(k);
			glutPostRedisplay();
		}
		if (x > SHIFT && x < 100 && y > SHIFT + 50 && y < SHIFT + 90) {
			
			cout << "Удалить новое значение: ";
			cin >> k;
			temp->inOrder(temp,k);
			glutPostRedisplay();
		}	
	}
}






