//nama : RADITYA RAHARDYANSYAH RIFAT
//NIM : 1910512014
//kelas : Kelas A PSDA
//Project UAS PSDA


//kriterianya:
// insert BST, tampilan seluruh BST (inorder,postorder,preorder)
// format jika pencarian ditemukan dan tidak ditemukan
// delete bst, menampilkan nilai terkecil dan terbesar dari BST
// reset bst

#include <iostream>
#include <stdlib.h>
#include<bits/stdc++.h> 
using namespace std;

//membuat binary tree

struct node
{
	int input;
	struct node* left;
	struct node* right;
	struct node* parent;
};


//fungsi create node
node* nodeBaru (int input)
{
	node *nodeBaru = new node;
	nodeBaru->input = input;
	nodeBaru->left = NULL;
	nodeBaru->right = NULL;
	
	return nodeBaru;
}

//membuat fungsi insert BST
node* insert(struct node* node, int input)
{
	//ketika tree tidak ada inputan atau data
	if (node == NULL)
	return nodeBaru(input);
	
	//ketika tree sudah ada isinya
	// insert node kiri dulu
	if (input < node->input)
		node->left = insert(node->left, input);
	//insert node kanan dulu
	else if (input > node->input)
		node->right = insert(node->right, input);
	
	return node;
}

//membuat fungsi fungsi tampilan inorder, postorder, preorder

//inOrder
void inOrder(struct node* parent)
{
	//jika tidak ada node di tree
	if (parent == NULL)
	return;
	
	//jika ada node di tree
	
	//pencarian dari subtree kiri
	inOrder(parent->left);
	//mencetak data node parent
	cout << parent->input << " ";
	//pencarian ke subtree kanan
	inOrder (parent->right);
}

//postOrder
void postOrder (struct node* parent)
{
	if ( parent == NULL)
	return;
	
	//mencari dari subtree kiri
	postOrder(parent->left);
	//mencari dari subtree kanan
	postOrder(parent->right);
	//mencetak parent
	cout << parent->input << " ";
}

//preOrder
void preOrder (struct node* parent)
{
	if ( parent == NULL)
	return;
	
	//cetak parent
	cout << parent->input << " ";
	//mencari dari subtree kiri
	preOrder (parent->left);
	//mencari dari subtree kanan
	preOrder (parent->right);
}

//fungsi search
node* search(struct node* parent, int input)
{
	//membuat ketinggian atau level
	int level = 0;
	node *temp = new node;
	temp = parent;
	while ( temp != NULL)
	{
		level++;
		if ( temp->input == input)
		{
			cout << "Data ditemukan pada level: " << level;
			return parent;
		}
		else if ( temp->input > input)
			temp = temp->left;
			else
			temp = temp->right;
	}
	cout << "\nData tidak ditemukan";
}

//fungsi untuk successor jika delete root
node * minValueNode(struct node* node)
{
	struct node* current = node;
	//mencari nilai terbesar di subtree sebelah kiri
	while (current && current->left != NULL)
		current = current->left;
		
	return current;
}

//fungsi untuk delete tree
struct node* deleteNode(struct node* parent, int input)
{
	if (parent == NULL)
	return parent;
	
	/* jika yang ingin didelete lebih kecil dari parent
	maka letak node yang ingin didelete ada di sebelah kiri*/
	if(input < parent->input)
		parent->left = deleteNode(parent->left, input);//salah pemanggilan nama fungsi
	
	/* jika yang didelete lebih besar dari parent, maka
	ada di subtree kanan*/
	
	else if (input > parent->input)
		parent->right = deleteNode(parent->right, input);//salah pemanggilan nama fungsi
		
	/* jika root yang di delete */
	else
	{
		if (parent->left == NULL)
		{
			struct node *temp = parent->right;
			free(parent);
			return temp;
		}
		else if (parent->right == NULL)
		{
			struct node *temp = parent->left;
			free(parent);
			return temp;
		}
		
		//menggantikan parent dengan node terkecil di subtree kiri
		struct node* temp = minValueNode(parent->right);
		//inorder successor content
		parent->input = temp->input;
		//delete inorder successsor
		parent->right = deleteNode(parent->right, temp->input);//salah pemanggilan nama fungsi sama kayak yang diatas
	}
}

//fungsi reset BST
void reset(node* node)
{
	if (node == NULL) return;
	
	// delete dari kedua subtree
	delete(node->left);
	delete(node->right);
	
	//lalu, hapus node yang ada
	cout << "\nDeleting node: " << node->input;
	delete node;
}

//fungsi pencarian node dengan nilai tertinggi di BST
int nilaiMax(struct node* node)
{
	/*karena nilai tertinggi sudah pasti ada di subtree kanan
	maka pencarian hanya dilakukan ke pojok kanan subtree kanan saja*/
	struct node* current = node;
	while(current->right != NULL)
		current = current->right;
	
	return (current->input);
}

//fungsi pencarian node dengan nilai terendah di BST
int nilaiMin (struct node* node)
{
	/* pencarian hanya dilakukan di subtree kiri karena
	nilai terkecil sudah pasti ada di pojok kiri subtree kiri */
	struct node* current = node;
	while (current->left != NULL)
		current = current->left;
	return (current->input);
}

int main ()
{
		/* Let us create following BST 
			50 
		/	 \ 
		30	 70 
		/ \ / \ 
	20 40 60 80 */
	struct node *parent = NULL; 
	parent = insert(parent, 50); 
	insert(parent, 30); 
	insert(parent, 20); 
	insert(parent, 40); 
	insert(parent, 70); 
	insert(parent, 60); 
	insert(parent, 80);
	
	cout << "\nCetak postOrder :" ;
	postOrder(parent);
	
	cout << "\nCetak preOrder";
	preOrder(parent);
	
	cout << "\nCetak inOrder";
	inOrder (parent);
	
	cout << "\nBilangan terbesar adalah :" << nilaiMax(parent);
	cout << "\nBilangan terkecil adalah : "<< nilaiMin(parent) << endl;
	cout <<"\n";
	cout << "\nSearch bilangan 20\n";
	search(parent,20);
	cout <<"\n";
	
	cout << "\n***********************************************************";
	cout << "\nBilangan di delete 80";
	deleteNode(parent,80);
	cout << "\nBilangan di delete 50";
	deleteNode(parent,50);
	cout << "\n***********************************************************";
	
	cout << "\nMaka perubahan setelah delete bilangan adalah:\n";
	
	cout << "\nCetak postOrder :" ;
	postOrder(parent);
	
	cout << "\nCetak preOrder";
	preOrder(parent);
	
	cout << "\nCetak inOrder";
	inOrder (parent);
	
	cout << "\nBilangan terbesar adalah :" << nilaiMax(parent);
	cout << "\nBilangan terkecil adalah : "<< nilaiMin(parent) << endl;
	cout <<"\n";
	cout << "\nSearch bilangan 20\n";
	search(parent,20);
	cout <<"\n";
	
	
	return 0;
}
