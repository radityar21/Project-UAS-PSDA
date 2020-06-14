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
	//mendeskripsikan root terlebih dahulu
	struct node *parent = NULL;
	int x, pilihan, input;
	//input parent atau root di BST
	cout << "\nMasukkan nilai parent atau root pada tree: ";
	cin >> x;
	parent = insert(parent,x);
	//loop untuk menu yang berulang
	while(true){
	cout << "\nTampilan menu BST NIM 1910512014";
	cout << "\n1) Tambahkan node baru";
	cout << "\n2) Cetak preOrder";
	cout << "\n3) Cetak postOrder";
	cout << "\n4) Cetak inOrder";
	cout << "\n5) Pencarian bilangan";
	cout << "\n6) hapus bilangan";
	cout << "\n7) reset BST";
	cout << "\n8) Cetak bilangan terbesar";
	cout <<"\n9) Cetak bilangan terkecil";
	cout << "\n10) Exit menu";
	cout << "\nPilihan Menu: ";
	cin>> pilihan;		
			switch(pilihan)
	{
		//jika yang dipilih adalah nomor 1
		case 1:
			{
			cout<<"\nBilangan yang ingin ditambahkan: ";
			cin >> input;
			insert(parent,input);
			}
			break;
		//jika yang dipiilih adalah nomor 2
		case 2:
			{
			cout << "\nIsi BST secara pre Order adalah : " ; 
			preOrder(parent);
			}
			break;
		//jika yang dipiilih adalah nomor 3
		case 3:
			{
			cout << "\nIsi BST secara post Order adalah : "; 
			postOrder(parent);
			}break;
		//jika yang dipiilih adalah nomor 4
		case 4:
			{
			cout << "\nIsi BST secara in Order adalah : "; 
			inOrder(parent);
			}break;
		//jika yang dipiilih adalah nomor 5
		case 5:
			{
			cout << "\nBilangan yang ingin dicari: ";
			cin >> input;
			search(parent,input);
			}break;
		//jika yang dipiilih adalah nomor 6
		case 6: 
			{
			cout << "Bilangan yang ingin dihapus : ";
			cin >> input;
			deleteNode(parent,input);
			}break;
		//jika yang dipiilih adalah nomor 7
		case 7:
			{
			cout << "\nBST direset";
			reset (parent);
			}break;
		//jika yang dipiilih adalah nomor 8
		case 8:
			{
			cout << "\nBilangan terbesar di BST adalah : "<<nilaiMax(parent);
			}break;
		//jika yang dipiilih adalah nomor 9
		case 9:
			{
			cout << "\nBilangan terkecil di BST adalah : "<<nilaiMin(parent);
			}break;
		//jika yang dipiilih adalah nomor 10
		case 10:
			{
			false;
			}break;	
	}
	}
}
