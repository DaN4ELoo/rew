#include <iostream>

using std::cin;
using std::cout;



// ������
struct node {
	int field;// ����
	node* left;// ����
	node* right;// �����
	node(int elem)// ������ ����
	{
		field = elem;
		left = right = 0;
	}
};



// ���������� ����
node* add(node* tree, int field)
{
	if (!tree) return new node(field);// ���� ��� �����

	if (field < tree->field)// ������ �����
	{
		tree->left = add(tree->left, field);
	}
	else// ������ ������
	{
		tree->right = add(tree->right, field);
	}
	return tree;
}



// ��� ���� �������
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



// ����� �� ��������
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



// ����� ������������
node* findMinx(node* tree)
{
	if (!tree)// ���� ������ ������
	{
		cout << "������ ���\n\n";
		return(tree);
	}
	else// �����
	{
		while (tree->left != NULL)
		{
			tree = tree->left;
		}
		return tree;
	}
}



// ����� ���� � ����������� ���������
node* findMin(node* tree)
{
	return tree->left ? findMinx(tree->left) : tree;
}



// �������� ���� � ����������� ���������
node* removeMin(node* tree)
{
	if (tree->left == 0)// ���� �� ���������� ����� �����
		return tree->right;// ������� �� ������
	tree->left = removeMin(tree->left);
	return tree;
}



// ����� �������������
node* findMax(node* tree)
{
	if (!tree)// ���� ������ ���
	{
		cout << "������ ���\n\n";
		return(tree);
	}
	else// �����
	{
		while (tree->right != NULL)
		{
			tree = tree->right;
		}
		return tree;
	}
}



// �������� ��������
node* removeNode(node* tree, int field)
{
	if (!tree) return 0;// ���� ������ ������
	if (field < tree->field)// �� ����� �����
	{
		tree->left = removeNode(tree->left, field);
	}
	else if (field > tree->field)// �� ������ �����
	{
		tree->right = removeNode(tree->right, field);
	}
	else// ���� ����� �������
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



// �������
void menu()
{
	system("cls");
	cout
		<< "---------����----------\n"
		<< " 1.   �������� ����\n"
		<< " 2.   ������� ����\n"
		<< " 3.      �������\n"
		<< " 4. ����� ���. � ����.\n"
		<< " 5.   ����� �� ����.\n"
		<< " 6.       �����\n"
		<< "-----------------------\n";
}



int main() {
	setlocale(LC_ALL, "rus");// ������� ����
	int elem, answer = 0;
	cout << "������� ������ ����: ";
	cin >> elem;
	node* tree = new node(elem);// �������� ������

	int choise;// ����� � ����
	do {
		menu();// �������
		cin >> choise;// �����
		switch (choise)
		{
		case 1:// �������� �������
			cout << "������� �������: ";
			cin >> elem;
			add(tree, elem);
			cout << "������� ��������\n\n";
			system("pause");
			break;


		case 2:// ������� �������
			cout << "������� �������: ";
			cin >> elem;
			removeNode(tree, elem);
			cout << "������� ������\n\n";
			system("pause");
			break;


		case 3:// �����
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


		case 4:// ���. � ����.
			system("cls");
			cout << "\ninOrder: \n";
			inOrder(tree);

			cout << "\n\n���.: " << findMin(tree)->field << "\n";
			cout << "����.: " << findMax(tree)->field << "\n";
			system("pause");
			break;


		case 5:// ����� �� ��������
			system("cls");

			cout << "\ninOrder: \n";
			inOrder(tree);

			cout << "������� �������: ";
			cin >> elem;

			findElem(tree, elem, answer);
			if (answer == 1)
			{
				cout << "\n\n������ �������� ������ �������\n\n";
				answer = 0;
			}
			else cout << "\n\n������ �� �������� ������ �������\n\n";
			system("pause");
			break;


		case 6:// �����
			return 0;
			break;


		default:// �������� �����
			cout << "������ ������ ���\n\n";
			system("pause");
			break;
		}
	} while (choise != 6);// �������������� ����
}