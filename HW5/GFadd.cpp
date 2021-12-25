#include<stdlib.h>
#include<stdio.h>
//¹Bºâ
int add(int a,int b) {
	return a^b;
}
void addPolynomicly(int degree,int A[],int B[],int C[]){
	for(int i=0;i<=degree;i++){
		*(C+i)=add(*(A+i),*(B+i));
	}	
}
void printPoly(int degree,int A[]) {
	printf("\n");
	for(int i=degree;i>=0;i--){
		if(A[i]!=0){
			printf(" %dX^%d ",A[i],i);			
		}
	}
}
void input(int degree,int A[]){
	for(int i=degree;i>=0;i--){
		printf(" X^%d=",i);		
		scanf("%d",&A[i]);
	}
}
int main(){
	int n;
	printf("Please enter the degree:");
	scanf("%d",&n);	
	int A[n+1]={0};
	int B[n+1]={0};
	printf("Please input the coef of each expo in arrayA:\n")	;
	input(n-1,A);
	printf("\nA:");
	printPoly(n,A);
	printf("\n\nPlease input the coef of each expo in arrayB:\n")	;
	input(n-1,B);	
	printf("\nB:");
	printPoly(n,B);
	printf("\n\nSum of A,B:");
	int C[n+1]={0};
	addPolynomicly(n,A,B,C);
	printPoly(n,C);
}
