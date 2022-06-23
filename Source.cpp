#include <iostream>

using std::cin;
using std::cout;



// дерево
struct node {
	int field;// поле
	node* left;// лево
	node* right;// право
	node(int elem)// первый узел
	{
		field = elem;
		left = right = 0;
	}
};



// добавление узла
node* add(node* tree, int field)
{
	if (!tree) return new node(field);// если нет узлов

	if (field < tree->field)// кидаем влево
	{
		tree->left = add(tree->left, field);
	}
	else// кидаем вправо
	{
		tree->right = add(tree->right, field);
	}
	return tree;
}



// три вида обходов
void inOrder(node* tree)
{
	if (tree)
	{
		inOrder(tree->left);
		cout << tree->field << "\t";
		inOrder(tree->right);
	}
}
void PreOrder(node* tree)
{
	if (tree)
	{
		cout << tree->field << "\t";
		PreOrder(tree->left);
		PreOrder(tree->right);
	}
}
void PostOrder(node* tree)
{
	if (tree)
	{
		PostOrder(tree->left);
		PostOrder(tree->right);
		cout << tree->field << "\t";
	}
}



// поиск по значению
void findElem(node* tree, int elem, int& answer)
{
	if (tree)
	{
		findElem(tree->left, elem, answer);
		if (elem == tree->field)
		{
			answer = 1;
		}
		findElem(tree->right, elem, answer);
	}
}



// поиск минимального
node* findMinx(node* tree)
{
	if (!tree)// если дерево пустое
	{
		cout << "Дерева нет\n\n";
		return(tree);
	}
	else// поиск
	{
		while (tree->left != NULL)
		{
			tree = tree->left;
		}
		return tree;
	}
}



// поиск узла с минимальным значением
node* findMin(node* tree)
{
	return tree->left ? findMinx(tree->left) : tree;
}



// удаление узла с минимальным значением
node* removeMin(node* tree)
{
	if (tree->left == 0)// пока не закончится левая часть
		return tree->right;// переход на правую
	tree->left = removeMin(tree->left);
	return tree;
}



// поиск максимального
node* findMax(node* tree)
{
	if (!tree)// если дерева нет
	{
		cout << "Дерева нет\n\n";
		return(tree);
	}
	else// поиск
	{
		while (tree->right != NULL)
		{
			tree = tree->right;
		}
		return tree;
	}
}



// удаление элемента
node* removeNode(node* tree, int field)
{
	if (!tree) return 0;// если дерево пустое
	if (field < tree->field)// по левой части
	{
		tree->left = removeNode(tree->left, field);
	}
	else if (field > tree->field)// по правой части
	{
		tree->right = removeNode(tree->right, field);
	}
	else// если нашли элемент
	{
		node* tree1 = tree->left;
		node* tree2 = tree->right;
		delete tree;
		if (!tree2) return tree1;
		node* min = findMin(tree2);
		min->right = removeMin(tree2);
		min->left = tree1;
		return min;
	}
	return tree;
}



// менюшка
void menu()
{
	system("cls");
	cout
		<< "---------МЕНЮ----------\n"
		<< " 1.   Добавить узел\n"
		<< " 2.   Удалить узел\n"
		<< " 3.      Вывести\n"
		<< " 4. Поиск мин. и макс.\n"
		<< " 5.   Поиск по знач.\n"
		<< " 6.       Выход\n"
		<< "-----------------------\n";
}



int main() {
	setlocale(LC_ALL, "rus");// русский язык
	int elem, answer = 0;
	cout << "Введите первый узел: ";
	cin >> elem;
	node* tree = new node(elem);// создание дерева

	int choise;// выбор в меню
	do {
		menu();// менюшка
		cin >> choise;// выбор
		switch (choise)
		{
		case 1:// добавить элемент
			cout << "Введите элемент: ";
			cin >> elem;
			add(tree, elem);
			cout << "Элемент добавлен\n\n";
			system("pause");
			break;


		case 2:// удалить элемент
			cout << "Введите элемент: ";
			cin >> elem;
			removeNode(tree, elem);
			cout << "Элемент удален\n\n";
			system("pause");
			break;


		case 3:// вывод
			system("cls");

			cout << "inOrder: \n";
			inOrder(tree);

			cout << "\nPostOrder: \n";
			PostOrder(tree);

			cout << "\nPreOrder: \n";
			PreOrder(tree);

			cout << "\n";
			system("pause");
			break;


		case 4:// мин. и макс.
			system("cls");
			cout << "\ninOrder: \n";
			inOrder(tree);

			cout << "\n\nМин.: " << findMin(tree)->field << "\n";
			cout << "Макс.: " << findMax(tree)->field << "\n";
			system("pause");
			break;


		case 5:// поиск по значению
			system("cls");

			cout << "\ninOrder: \n";
			inOrder(tree);

			cout << "Введите элемент: ";
			cin >> elem;

			findElem(tree, elem, answer);
			if (answer == 1)
			{
				cout << "\n\nДерево содержит данный элемент\n\n";
				answer = 0;
			}
			else cout << "\n\nДерево не содержит данный элемент\n\n";
			system("pause");
			break;


		case 6:// выход
			return 0;
			break;


		default:// неверный пункт
			cout << "Такого пункта нет\n\n";
			system("pause");
			break;
		}
	} while (choise != 6);// функциональное меню
}