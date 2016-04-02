#include "AVLTree.h"
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
	AVLTree avltree;
	srand(static_cast<unsigned>(time(nullptr)));
	for (int i = 100; i > 0; i--)
		avltree.insert(i);
	avltree.inOrderTraversal();

	while (!avltree.isEmpty())
		avltree.removeNode(avltree.getRootData());
	return 0;
}