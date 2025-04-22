#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "abb.h"
int mystrcmp(char* s1, char* s2);
Tree *initTree(char *value){
	Tree *ret = (Tree*)malloc(sizeof(Tree));
	if(ret == NULL){
		fprintf (stderr, "Out of memory!!! (initTree)\n");
        exit(1);
	}
	ret->left = NULL;
	ret->right = NULL;
	ret->val = (char *)malloc(strlen(value)+1);
	strcpy(ret->val, value);
	return ret;
}
Tree *insertValue(Tree *root, char *value){
	if(root == NULL)
		return initTree(value);
	int cmp = mystrcmp(value,root->val);
	if(cmp<=0)
		root->left = insertValue(root->left, value);
	else
		root->right = insertValue(root->right, value);
	return root;
}
void printTree(Tree *root){
	if(root == NULL)
		return;
	printTree(root->left);
	printf("%s\t",root->val);
	printTree(root->right);
}
char *maxValue(Tree *root){
	if(root == NULL)
		return "";
        if (root->right==NULL)
                return root->val;
        else
                return maxValue(root->right);
}
char *minValue(Tree *root){
	if(root == NULL)
		return "";
        if (root->left==NULL)
                return root->val;
        else
                return minValue(root->left);
}
char *find(Tree* root, char* value){
	if(root == NULL)
		return NULL;
	int cmp = mystrcmp(root->val, value);
	if(cmp==0)
		return value;
	if(cmp<0)// Si es que el que estoy comparando es menor al que busco
		return find(root->right, value);
	return find(root->left, value);
}
void destroyNode(Tree* node){
	if(node == NULL)
		return;
	free(node->val);
	free(node);
}

Tree *delVal(Tree *root, char *value){
	if(root == NULL)
		return root;
	int cmp = mystrcmp(value,root->val);
	if(cmp < 0)
		root->left = delVal(root->left, value);
	else if(cmp>0)
		root->right = delVal(root->right, value);
	else{//cmp == 0
		Tree *aux;
		if(root->left==NULL){
			aux = root->right;
			destroyNode(root);
			root = aux;
		}
		else if(root->right == NULL){
			aux = root->left;
			destroyNode(root);
			root = aux;
		}
		else{//tiene dos hijos
			free(root->val);
            aux = root->right;
            while(aux->left !=NULL){
                aux = aux->left;
            }
            root->val = malloc(strlen(aux->val)+1);
            strcpy(root->val, aux->val);
            root->right = delVal(root->right, aux->val);

		}

	}
	return root;
}
void freeTree(Tree *root){
	if(root == NULL)
		return;
	freeTree(root->left);
	freeTree(root->right);
	destroyNode(root);
}
int main(){
	Tree *r = initTree("hola");
	printf("%s\n",r->val);
	//r = insertValue(r, "a");
	r = insertValue(insertValue(insertValue(insertValue(insertValue(r,"hol"),"zi"),"aa"),"bh"),"hola");
	printTree(r);
	printf("\n");
	printf("max: %s\n", maxValue(r));
	printf("min: %s\n", minValue(r));
	printf("find chao:%s\t find aa:%s\t, find hola:%s\n", find(r,"chao"),find(r,"aa"),find(r,"hola"));
	printf("eliminando j (que no existe)...\n");
	r = delVal(r,"j");
	printTree(r);
	printf("\n");
	printf("eliminando hol...\n");
	r = delVal(r,"hol");
	printTree(r);
	printf("\n");
	freeTree(r);
}

int mystrcmp(char *s1, char *s2){
	while(*s1!='\0' &&  *s2==*s1){
		s1++; s2++;
	}
	return *s1-*s2;
}
