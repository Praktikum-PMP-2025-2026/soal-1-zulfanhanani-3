/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 5 (Foundation of Algorithm)
 *   Hari dan Tanggal    : Selasa, 12 Mei 2026
 *   Nama (NIM)          : Zulfan Hanani (13224105)
 *   Nama File           : soal1selasa.c
 *   Deskripsi           : Silsilah Dinasti Langit
 *                         menampilkan ketiga urutan pembacaan dari representasi pohon yang diberikan.
                           Cetak preorder, inorder, dan postorder dari tree lengkap.
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    int angka;
    struct Node* kiri;
    struct Node* kanan;
    struct Node* parent;
}Node;

Node* createTree(int angka){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->angka = angka;
    newNode->kanan = NULL;
    newNode->kiri = NULL;
    newNode->parent = NULL;
    return newNode;
}

void addNode(Node* tree, int angka){
    if (tree == NULL){
        tree = createTree(angka);
    }else if (angka < tree->angka && tree->kiri == NULL){
        tree->kiri = createTree(angka);
        tree->kiri->parent = tree;
    }else if (angka > tree->angka && tree->kanan == NULL){
        tree->kanan = createTree(angka);
        tree->kanan->parent = tree;
    }else if (angka < tree->angka){
        addNode(tree->kiri, angka);
    }else{
        addNode(tree->kanan, angka);
    }
}

void preorder(Node* tree){
    if (tree == NULL){
        return;
    }
    printf("%d ", tree->angka);
    preorder(tree->kiri);
    preorder(tree->kanan);
}

void inorder(Node* tree){
    if (tree == NULL){
        printf("1");
        return;
    }
    inorder(tree->kiri);
    printf("%d ", tree->angka);
    inorder(tree->kanan);
}

void postorder(Node* tree){
    if (tree == NULL){
        return;
    }
    postorder(tree->kiri);
    postorder(tree->kanan);
    printf("%d ", tree->angka);
}

int main() {
    int n, angka;
    if (scanf("%d", &n) != 1){
        printf("Input n tidak valid");
    }
    Node* tree = NULL;

    for (int i = 0; i < n; i++){
        if (scanf("%d", &angka) != 1){
            printf("Input n tidak valid");
        }
        addNode(tree, angka);
    }
    
    printf("PRE ");
    preorder(tree);
    printf("\nIN ");
    inorder(tree);
    printf("\nPOST ");
    postorder(tree);

    return 0;
}
 
