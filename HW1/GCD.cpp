#include<stdlib.h>
#include<stdio.h>
int gcd(int r1,int r2){
	int q;
	int r;
	if(r2==0){
		printf("	%d	%d	",r1,r2);
		printf("\n\ngcd=%d",r1);
		return r1;
	}
	q=r1/r2;
	r=r1%r2;
	printf("%d	%d	%d	%d\n",q,r1,r2,r);
	return gcd(r2,r);
}
int main(){
	printf("Please input two integers:");
	int a;
	int b;
	scanf("%d%d",&a,&b);
	printf("q	r1	r2	r\n");
	printf("------------------------------------------------\n");
	gcd(a,b);
}
