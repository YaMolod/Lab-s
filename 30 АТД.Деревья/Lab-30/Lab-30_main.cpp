#include "Tree.h"

int main(int argc, char** argv) {
	setlocale(LC_ALL, "ru");
	Tree<int>* tree1 = new Tree<int>(5);
	tree1->insertNode(4);
	tree1->insertNode(6);
	tree1->insertNode(7);
	tree1->drawTree(argc, argv, WIDTH, HEIGHT, SHIFT, 1);

	return 0;
}



