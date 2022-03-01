#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int coeff;
	int pow;
	struct Node *next;
}node;

void readPolynomial(node** poly);
void addPolynomials(node** result, node* first, node* second);
void display(node* poly);

	
int main(){
	node* first = NULL;
	node* second = NULL;
	node* result = NULL;
	printf("\nEnter the corresponding data:-\n");
	printf("\nFirst polynomial: ");
	readPolynomial(&first);
	display(first);
	printf("\nSecond polynomial: ");
	readPolynomial(&second);	
	display(second);
	addPolynomials(&result, first,second);
    printf("\nSum = ");
	display(result);
	return 0;
}

void readPolynomial(node** poly){
	int coeff, exp, cont;
	node* temp = (node*)malloc(sizeof(node));
	*poly = temp;
	do{
		printf("\nCoeffecient: ");
		scanf("%d", &coeff);
		printf("Exponent: ");
		scanf("%d", &exp);
		temp->coeff = coeff;
		temp->pow = exp;
		temp-> next = NULL;
		printf("\n1)Add terms\n2)Done\nEnter : ");
		scanf("%d", &cont);
		if(cont==1){
			temp->next = (node*)malloc(sizeof(node));
			temp = temp->next;
			temp->next = NULL;
		}
	}while(cont!=2);	
}

void addPolynomials(node** result, node* first, node* second){
 	node* temp = (node*)malloc(sizeof(node));
 	temp->next = NULL;
 	*result = temp;
 	while(first && second){
 		if(first->pow > second->pow){
 			temp->coeff = first->coeff;
 			temp->pow = first->pow;
 			first = first->next;
 		}
 		else if(first->pow < second->pow){
 			temp->coeff = second->coeff;
 			temp->pow = second->pow;
 			second = second->next;
 		}
 		else{
 			temp->coeff = first->coeff + second->coeff;
 			temp->pow = first->pow;
 			first = first->next;
 			second = second->next;
 		}

 		if(first && second){
 			temp->next = (node*)malloc(sizeof(node));
 			temp = temp->next;
 			temp->next = NULL;
 		}
 	}
 	while(first || second){
 		temp->next = (node*)malloc(sizeof(node));
 		temp = temp->next;
 		temp->next = NULL;
 			
 		if(first){
 			temp->coeff = first->coeff;
 			temp->pow = first->pow;
 			first = first->next;
 		}

 		else if(second){
 			temp->coeff = second->coeff;
 			temp->pow = second->pow;
 			second = second->next;
 		}
 	}
}

void display(node* poly){
	printf("Polynomial expression is: ");
	while(poly != NULL){
		printf("%dX^%d", poly->coeff, poly->pow);
		poly = poly->next;
		if(poly != NULL)
			printf("+");
	}
}
