#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
//410706228 I3B54����� 
/*
�n�D:
1.�����Ů�->�r�����e�� 
2.�L����J�j�p�g->��ctype��tolower 
3.i�Mj�����P�@��->�w�]��i�A�ˬd��J�O�_��j�A�O�h��tag�}�C�аOi����}
4.����J���:�r�꦳�s��(�����[x)��Y�r����׬O�_��(�̫��x)-> 


*/
int main() {
	char alph[25]={'a','b','c','d','e','f','g','h','i','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	int tag[25]={0};
	char k[25]={0};
	
	
	printf("Please input a key:");
	gets(k);
	//�����令�p�g
	for(int i=0;i<strlen(k);i++) {
		k[i]=tolower(k[i]);
	}
	//�ˬd�åh���Ů� 
	for(int i=0;i<strlen(k);i++){
		if(k[i]==' '){
			for(int j=i;j<strlen(k);j++){//�������e���@�� 
				k[j]=k[j+1];
			}
			i--;//�i�঳�s��Ů�A�ҥH�n�����ˬd�P�Ӧ�} 
		}
	}
	//k��Jkey
	char key[25]={0};
	for(int i=0;i<strlen(k);i++) {
		key[i]=k[i];
		for(int a=0;a<25;a++){//��}�Calph����L���r����tag �令1 
			if(key[i]==alph[a]){
				tag[a]=1;
			}
			if(key[i]=='j'){//����j�Mi�����P�@��A�ҥH�n���ˬd�O�_��j 
				tag[8]=1;
			}
		}
	}
	//�ɨ���L�r�� 
	int count1=strlen(k);
	for(int i=0;i<25;i++){
		if(tag[i]==0){
			key[count1]=alph[i];
			count1++;			
		}
	}
	//�L�Xkey
	/*printf("\nKey:\n") ;
	for(int i=0;i<25;i++){	
		if(i%5==0){
			printf("\n");	
		}
		printf("%3c",key[i]);
	}
	
	*/
	
	
	//�_�ͩ�J5*5�x�} 
	printf("\n\n");
	int count=0;
	char fkey[5][5];
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			fkey[i][j]=key[count]	;
			count++;
		}
	}
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			printf("%3c",fkey[i][j]);
		}
		printf("\n");
	}
	
	
	
	
	
	
	//��J�r�� 
	char p[50]={0} ;
	char p1[50]={0};
	char ps[50][2];
	printf("Please input a string to encrypt:");
	gets(p);
	//�ˬd�åh���Ů� 
	for(int i=0;i<strlen(p);i++){
		if(p[i]==' '){
			for(int j=i;j<strlen(p);j++){//�������e���@�� 
				p[j]=p[j+1];
			}
			i--;//�i�঳�s��Ů�A�ҥH�n�����ˬd�P�Ӧ�} 
		}
	}
	//�����令�p�g 
	for(int i=0;i<strlen(p);i++) {
		p[i]=tolower(p[i]);
	}
	//�r���ܧ�
	int counter=0;
	for(int i=0;i<strlen(p);i++){//��j������i 
		if(p[i]=='j'){
			p[i]='i';
		}
	}
	for(int i=1;i<=strlen(p);i++){		
		if(p[i]!=p[i-1]){
			p1[counter]=p[i-1];
			counter++;
		}else{
			p1[counter]=p[i-1];
			counter++;
			p1[counter]='x';
			counter++;
		}
		
	}
	//printf("\n%d\n",strlen(p1));
	counter--;
	//printf("\n%d\n",strlen(p1));
	if(strlen(p1)%2!=0){
		counter++;
		p1[counter]='x';		
	}
	//printf("\n\n%s",p1);
	//��J�}�C
	int count2=0;
	for(int i=0;i<strlen(p1)/2;i++) {
		for(int j=0;j<2;j++){
			ps[i][j]=p1[count2];
			count2++;
		}
	}
	printf("\n");
	/*
	for(int i=0;i<strlen(p1)/2;i++) {
		for(int j=0;j<2;j++){
			printf("%3c",ps[i][j]);			
		}
		printf("\n");
	}
	*/
	//�M����r�� 
	char crypt[50]={0};
	int count4=0;
	for(int i=0;i<strlen(p1)/2;i++){//�@p1����/2��
		int a,b,c,d;		
		for(int j=0;j<5;j++){  //�M����key��� �ðO����} 
			for(int q=0;q<5;q++){
				if(ps[i][0]==fkey[j][q]){
					a=j;
					b=q;
				}			
			}
		}
		for(int j=0;j<5;j++){
			for(int q=0;q<5;q++){
				if(ps[i][1]==fkey[j][q]){
					c=j;
					d=q;
				}			
			}
		}
	//	printf("\n");
	//	printf("a=%3d	b=%3d\n",a,b);		
	//	printf("c=%3d	d=%3d\n",c,d);		
		if(a==c){
			crypt[count4]=fkey[a][(b+1)%5];
			count4++;
			crypt[count4]=fkey[c][(d+1)%5];
			count4++;
		}else if(b==d){
			crypt[count4]=fkey[(a+1)%5][b];
			count4++;
			crypt[count4]=fkey[(c+1)%5][d];
			count4++;
		}else{
			crypt[count4]=fkey[a][d];
			count4++;
			crypt[count4]=fkey[c][b];
			count4++;
		}
		//printf("%s",crypt);
	}
	
	char ctoupper[50]={0};
	for(int i=0;i<strlen(crypt);i++){
		ctoupper[i]=toupper(crypt[i]);
	}
	
	printf("Cryptext:  %s\n",ctoupper);
	
	
	//�ѱK
	int tagde[25]={0};
	char kde[25]={0};
	
	
	printf("\n\nPlease input a key:");
	gets(kde);
	
	//�����令�p�g
	for(int i=0;i<strlen(kde);i++) {
		kde[i]=tolower(kde[i]);
	}
	//�ˬd�åh���Ů� 
	for(int i=0;i<strlen(kde);i++){
		if(kde[i]==' '){
			for(int j=i;j<strlen(kde);j++){//�������e���@�� 
				kde[j]=kde[j+1];
			}
			i--;//�i�঳�s��Ů�A�ҥH�n�����ˬd�P�Ӧ�} 
		}
	}
	//k��Jkey
	char keyde[25]={0};
	for(int i=0;i<strlen(kde);i++) {
		keyde[i]=kde[i];
		for(int a=0;a<25;a++){//��}�Calph����L���r����tag �令1 
			if(keyde[i]==alph[a]){
				tagde[a]=1;
			}
			if(keyde[i]=='j'){//����j�Mi�����P�@��A�ҥH�n���ˬd�O�_��j 
				tagde[8]=1;
			}
		}
	}
	//�ɨ���L�r�� 
	int count1de=strlen(k);
	for(int i=0;i<25;i++){
		if(tagde[i]==0){
			keyde[count1de]=alph[i];
			count1de++;			
		}
	}
	//�_�ͩ�J5*5�x�} 
	printf("\n\n");
	int countde=0;
	char fkeyde[5][5];
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			fkeyde[i][j]=keyde[countde]	;
			countde++;
		}
	}
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			printf("%3c",fkeyde[i][j]);
		}
		printf("\n");
	}
	
	
	
	
	//��J�K�� (�K��@�w�����ơA��L�̭ǭǩ�}��J�}�C�A�ѱK)
	char c[50]={0};
	printf("Please input a crypted string to decrypt:") ;
	gets(c);
	//�����令�p�g
	for(int i=0;i<strlen(c);i++) {
		c[i]=tolower(c[i]);
	}
	//�ˬd�åh���Ů� 
	for(int i=0;i<strlen(c);i++){
		if(c[i]==' '){
			for(int j=i;j<strlen(c);j++){//�������e���@�� 
				c[j]=c[j+1];
			}
			i--;//�i�঳�s��Ů�A�ҥH�n�����ˬd�P�Ӧ�} 
		}
	}
	
	//��J�G���}�C 
	int count2de=0;
	char cs[strlen(c)/2][2]={0};
	for(int i=0;i<strlen(c)/2;i++){
		for(int j=0;j<2;j++){
			cs[i][j]=c[count2de];
			count2de++;
		}
	}
	//�L�X�}�C 
	/*
	for(int i=0;i<strlen(c)/2;i++){
		for(int j=0;j<2;j++){
			printf("%3c",cs[i][j]);
		}
		printf("\n");
	}
	*/
	//���_�͸ѱK 
	char plain[50]={0};
	int count4de=0;
	for(int i=0;i<strlen(p1)/2;i++){//�@p1����/2��
		int e,f,g,h;
		for(int j=0;j<5;j++){
			for(int q=0;q<5;q++){
				if(cs[i][0]==fkeyde[j][q]){
					e=j;
					f=q;
				}		
			}
		}
		for(int j=0;j<5;j++){
			for(int q=0;q<5;q++){
				if(cs[i][1]==fkeyde[j][q]){
					g=j;
					h=q;
				}			
			}
		}
		//printf("\n");
		//printf("e=%3d	f=%3d\n",e,f);		
		//printf("g=%3d	h=%3d\n",g,h);		
		if(e==g){
			plain[count4de]=fkey[e][(f-1+5)%5];
			count4de++;
			plain[count4de]=fkey[g][(h-1+5)%5];
			count4de++;
		}else if(f==h){
			plain[count4de]=fkey[(e-1+5)%5][f];
			count4de++;
			plain[count4de]=fkey[(g-1+5)%5][h];
			count4de++;
		}else{
			plain[count4de]=fkey[e][h];
			count4de++;
			plain[count4de]=fkey[g][f];
			count4de++;
		}
		
	}
	//�B�z��x
	char plainfixed[50]={0};
	int fixcount=0;
	for(int i=0;i<strlen(plain);i++) {
		if(plain[i]!='x'){
			plainfixed[fixcount]=plain[i];
			fixcount++;
		}else if(i!=(strlen(plain)-1)&&plain[i-1]!=plain[i+1]){
			plainfixed[fixcount]=plain[i];
			fixcount++;
		}
	}
	printf("\n\nPlaintext:  %s",plainfixed);
}
