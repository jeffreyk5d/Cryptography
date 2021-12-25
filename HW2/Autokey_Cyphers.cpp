#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	/*
	加密
	用ASCII CODE所以要-97 
	*/ 
	int key;
	char p[50],c[50],cupper[50];
	printf("Please input a string to encrypt:");
	scanf("%s",p);
	printf("Please input a key:");
	scanf("%d",&key);
	int length=strlen(p);
	
	printf("The encrpted word is:\n");
	for(int i=0;i<length;i++){
		if(i==0){
			c[i]=(p[i]-97+key)%26+97;	
		}else{
			c[i]=(p[i]-97+p[i-1]-97)%26+97;		 
		}
		cupper[i]=toupper(c[i]);
	}
	
	printf("%s",cupper);
	
	
	/*
	解密
	*/ 
	char p2[50],c2[50],clower[50];
	printf("\nPlease input a string to decrypt:");
	scanf("%s",c2);
	int k,length2=strlen(c2);
	printf("Please input a key:");
	scanf("%d",&k);
	
	for(int i=0;i<length2;i++){
		clower[i]=tolower(c2[i]);
		if(i==0){
			p2[i]=(clower[i]-k-97)%26+97;
		}else{
			p2[i]=(clower[i]+(26-p2[i-1]))%26+97;
		}
		
	}
	printf("%s",p2);
}
