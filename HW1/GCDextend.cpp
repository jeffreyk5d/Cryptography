#include<stdlib.h>
#include<stdio.h>
int gcdExtend(int r1,int r2,int s1,int s2,int t1,int t2){
	int q;
	int r;
	int t;
	int s;
	if(r2==0){
		printf("	%3d	%3d		%3d	%3d		%3d	%3d	",r1,r2,s1,s2,t1,t2);
		printf("\n\ngcd=%d	s=%d	t=%d",r1,s1,t1);
		return r1;
	}
	q=r1/r2;
	s=s1-s2*q;
	t=t1-t2*q;
	r=r1%r2;
	printf("%3d	%3d	%3d	%3d	%3d	%3d	%3d	%3d	%3d	%3d\n",q,r1,r2,r,s1,s2,s,t1,t2,t);
	return gcdExtend(r2,r1%r2,s2,s,t2,t);
}
int main(){
	printf("Please input two integers:");
	int a;
	int b;
	scanf("%d%d",&a,&b);
	printf("%3s	%3s	%3s	%3s	%3s	%3s	%3s	%3s	%3s	%3s\n","q","r1","r2","r","s1","s2","s","t1","t2","t");
	printf("-------------------------------------------------------------------------------------------\n");
	gcdExtend(a,b,1,0,0,1);
}
