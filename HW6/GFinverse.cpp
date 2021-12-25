#include <stdlib.h>
#include <stdio.h>
void input(int degree,int A[]){
	for(int i=degree;i>=0;i--){
		printf(" X^%d=",i);		
		scanf("%d",&A[i]);
	}
}
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
void copy(int degree,int A[],int B[]){
	for(int i=0;i<=degree;i++){
		B[i]=A[i];
	}
}
int getDegree(int degree,int A[]){	
	while(A[degree]!=1){
		degree--;
	}
	return degree;
} 

void multSingle(int degree,int A[],int X[],int ans[]){	
	int p=getDegree(degree,X);
	for(int j=degree;j>=0;j--){
		if(A[j]==1){
			ans[j+p]=1;	
		}		
	}
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
void clear(int degree,int A[]){
	for(int i=0;i<=degree;i++){
		A[i]=0;
	}
}
void inverse(int degree,int irr[],int r1[],int r2[],int t1[],int t2[]){
	int flag=0;
	int flag1[degree+1]={0};
	flag1[0]=1;
	for(int i=degree;i>=0;i--){
		if(flag1[i]==r1[i]){
			flag=1;
		}else{
			flag=0;
			break;
		}
	}
	if(flag==1){		
		printf("\n\n\ninverse=");
		printPoly(degree,t1);
		return;
	}
	int degreeR1=getDegree(degree,r1);
	int degreeR2=getDegree(degree,r2);
	int tempQ[degree+1]={0};
	int tempR[degree+1]={0};
	int minus[degree+1]={0};
	int q[degree+1]={0};
	q[degreeR1-degreeR2]=1;
	tempQ[degreeR1-degreeR2]=1;
	multSingle(degree,r2,tempQ,minus);
	addPolynomicly(degree,r1,minus,tempR);
	int degreeTempR=getDegree(degree,tempR);
	if(degreeTempR>=degreeR2){
		clear(degree,tempQ);
		clear(degree,minus);
		tempQ[degreeTempR-degreeR2]=1;
		q[degreeTempR-degreeR2]=1;
		multSingle(degree,r2,tempQ,minus);
		addPolynomicly(degree,tempR,minus,tempR);
		degreeTempR=getDegree(degree,tempR);	
	}
	int r[degree+1]={0};
	int t2Q[degree+1]={0};
	int t[degree+1]={0};	
	mult(degree,irr,t2,q,t2Q);	
	addPolynomicly(degree,t1,t2Q,t);
	copy(degree,tempR,r);
	inverse(degree,irr,r2,r,t2,t);	
}
int main(){
	int n;
	printf("Please enter the degree:");
	scanf("%d",&n);	
	int A[n+1]={0};	
	int B[n+1]={0};
	printf("Please input the coef of each expo in arrayA:\n")	;
	input(n-1,A);
	printf("A:");
	printPoly(n,A);
	printf("\n\nPlease input the irreducible polynomial's coef:\n");
	int I[n+1]={0};
	input(n,I);	
	printf("I:");
	printPoly(n,I);
	int ans[n+1]={0};
	int t1[n+1]={0};
	int t2[n+1]={0};
	t2[0]=1;
	inverse(n,I,I,A,t1,t2);
}
