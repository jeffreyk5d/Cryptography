#include<stdlib.h>
#include<stdio.h>
int add(int a,int b){
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
int getDegree(int degree,int A[]){	
	while(A[degree]!=1){
		degree--;
	}
	return degree;
} 
void mult(int degree,int irr[],int A[],int B[],int ans[]){
	int degreeA=0;
	degreeA=getDegree(degree,A);
	int Compute[degreeA+1][degree+1]={0};		
	for(int i=0;i<=degree;i++){
		Compute[0][i]=B[i];	
	}	
 	for(int i=1;i<=degreeA;i++){ 		
		for(int j=degree;j>0;j--){
 			Compute[i][j]=Compute[i-1][j-1];
		}
		//mod irr
		if(Compute[i][degree]==1){
			addPolynomicly(degree,Compute[i],irr,Compute[i]);
		}	 
	}
	for(int i=0;i<=degreeA;i++)		{		
		if(A[i]!=0){
			addPolynomicly(degree,Compute[i],ans,ans);
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
	printf("\n\nPlease input the irreducible polynomial's coef:\n");
	int I[n+1]={0};
	input(n,I);	
	printf("\nI:");
	printPoly(n,I);
	int C[n+1]={0};	
	mult(n,I,A,B,C);
	printf("\n\nanswer: ");
	printPoly(n,C);
}
