#include <stdlib.h>
#include <stdio.h>
int add(int a,int b){
	return a^b;
}
void addPolynomicly(int degree,int A[],int B[],int C[]){
	for(int i=0;i<=degree;i++){
		*(C+i)=add(*(A+i),*(B+i));
	}	
}
void printPoly(int degree,int A[]) {	
	for(int i=degree-1;i>=0;i--){	
			printf(" %d",A[i]);			
	}
}
void clear(int degree,int A[]){
	for(int i=0;i<=degree;i++){
		A[i]=0;
	}
}
void swap(int degree,int A[],int B[]){
	int temp[degree]={0};
	for(int i=0;i<degree;i++){
		temp[i]=A[i];
		A[i]=B[i];
		B[i]=temp[i];
	}
}
void crypt(int degree,int L[],int R[],int K[],int fk[]){
	addPolynomicly(degree,R,K,fk);
	addPolynomicly(degree,L,fk,L);
	swap(degree,L,R);
	clear(degree,fk);
}
void decrypt(int degree,int L[],int R[],int K[],int fk[]){
	swap(degree,L,R);
	addPolynomicly(degree,R,K,fk);
	addPolynomicly(degree,L,fk,L);
	clear(degree,fk);
}
void input(int degree,int A[]){
	for(int i=degree-1;i>=0;i--){
		printf("%d=",i);		
		scanf("%d",&A[i]);
	}
}
int main(){
	int n;
	printf("Please enter the degree:");
	scanf("%d",&n);	
	int L1[n]={0};	
	int R1[n]={0};
	int K1[n]={0};
	int K2[n]={0};
	printf("\nPlease input the coef of each expo in L1:\n")	;
	input(n,L1);
	printf("\nPlease input the coef of each expo in R1:\n")	;
	input(n,R1);
	printf("\nPlease input the coef of each expo in K1:\n")	;
	input(n,K1);
	printf("\nPlease input the coef of each expo in K2:\n")	;
	input(n,K2);
	printf("\nL1:");
	printPoly(n,L1);
	printf("\nR1:");
	printPoly(n,R1);
	printf("\nK1=");
	printPoly(n,K1);
	printf("\nK2=");
	printPoly(n,K2);
	int fk[n]={0};	
	crypt(n,L1,R1,K1,fk);
	printf("\nL2=");
	printPoly(n,L1);
	printf("\nR2=");
	printPoly(n,R1);
	crypt(n,L1,R1,K2,fk);
	printf("\nL3=");
	printPoly(n,L1);
	printf("\nR3=");
	printPoly(n,R1);
	printf("\nL4=");
	printPoly(n,L1);
	printf("\nR4=");
	printPoly(n,R1);
	decrypt(n,L1,R1,K2,fk);	
	printf("\nL5=");
	printPoly(n,L1);
	printf("\nR5=");
	printPoly(n,R1);
	decrypt(n,L1,R1,K1,fk);
	printf("\nL6=");
	printPoly(n,L1);
	printf("\nR6=");
	printPoly(n,R1);
}
