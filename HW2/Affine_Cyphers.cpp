#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
/*
用gcdExtend找 乘法反元素t1
*/ 
int gcdExtend(int r1,int r2,int s1,int s2,int t1,int t2){
	int q;
	int r;
	int t;
	int s;
	if(r2==0){
		return t1;
	}
	q=r1/r2;
	s=s1-s2*q;
	t=t1-t2*q;
	r=r1%r2;
	return gcdExtend(r2,r1%r2,s2,s,t2,t);
}
int main(){
	/*
	加密
	用ASCII CODE所以要-97 
	*/ 
	int key1,key2;
	char p[50],c[50],cupper[50];
	printf("Please input a string to encrypt:");
	scanf("%s",p);
	printf("Please input a key1:");
	scanf("%d",&key1);
	printf("Please input a key2:");
	scanf("%d",&key2);
	int length=strlen(p);
	printf("The encrpted word is:\n");
	for(int i=0;i<length;i++){
		c[i]=((p[i]-97)*key1+key2)%26+97;
		cupper[i]=toupper(c[i]);
	}
	printf("%s",cupper);
	
	
	
	char p2[50],c2[50],clower[50];
	printf("\nPlease input a string to decrypt:");
	scanf("%s",c2);
	int k1,k2,length2=strlen(c2);
	printf("Please input a key1:");
	scanf("%d",&k1);
	printf("Please input a key2:");
	scanf("%d",&k2);
	int nk=gcdExtend(26,k1,1,0,0,1);
	if(nk<0){
		nk=nk+26;
	}	
	for(int i=0;i<length2;i++){
		clower[i]=tolower(c2[i]);
		p2[i]=((clower[i]-97+26-k2)*nk)%26+97;
	}
	printf("%s",p2);
}
