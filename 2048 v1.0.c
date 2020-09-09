#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void left(int* game,int* count,int* score);
int lefttest(int* game,int i,int j);
void right(int* game,int* count,int* score);
int righttest(int* game,int i,int j);
void up(int* game,int* count,int* score);
int uptest(int* game,int j);
void down(int* game,int* count,int* score);
int downtest(int* game,int j);
void show(int* game,int* score);

int main(int argc,char const *argv[])
{ 
	int game[16]={0};
	int i;
	int score=0;
	srand((unsigned)time(0));
	while (1) {
		int count=0;
		int zero[16]={0};
		int p=0;
		for (i=0;i<16;i++) {
			if (game[i]==0) {
				zero[p]=i;
				p++;
			}
		}
		if (p==1) {
			game[zero[0]]=2;
			break;
		}
        int a = rand()%p;
        game[zero[a]]=2;
		score+=2;

		show(game,&score);
		
		int pass;
error:
		pass=getch();
		if (pass!=224) goto error;
		int direction=getch();
		switch (direction) {
			case 75:left(game,&count,&score);break;
			case 77:right(game,&count,&score);break;
			case 72:up(game,&count,&score);break;
			case 80:down(game,&count,&score);break;
			default:goto error;
		}
		if (count==0) goto error;
		system("cls");
	}
	
	show(game,&score);
	printf("Game Over");

	return 0;
}

void left(int* game,int* count,int* score)
{
	int i;
	for (i=0;i<16;i+=4) {
		int j;
		for (j=i;j<i+4;j++) {
			while (lefttest(game,i,j)==0) {
				int p;
				for (p=j;p<i+3;p++) {
					game[p]=game[p+1];
				}
				game[p]=0;
				(*count)++;
			}
		}
		
		for (j=i;j<i+4;j++) {
			if (game[j]==game[j+1] && game[j]!=0) {
				game[j]*=2;
				game[j+1]=0;
				*score+=game[j];
				(*count)++;
				int p;
				for (p=j+1;p<i+3;p++) {
					game[p]=game[p+1];
				}
				game[p]=0;
			}
		}
	}
}

int lefttest(int* game,int i,int j)
{
	int result=0;
	if (game[j]!=0) result=1;
	int p=0;
	for (;j<i+4;j++) {
		p+=game[j];
	}
	if (p==0) result=1;
	return result;
}

void right(int* game,int* count,int* score)
{
	int i;
	for (i=3;i<16;i+=4) {
		int j;
		for (j=i;j>i-4;j--) {
			while (righttest(game,i,j)==0) {
				int p;
				for (p=j;p>i-3;p--) {
					game[p]=game[p-1];
				}
				game[p]=0;
				(*count)++;
			}
		}
		
		for (j=i;j>i-4;j--) {
			if (game[j]==game[j-1] && game[j]!=0) {
				game[j]*=2;
				game[j-1]=0;
				*score+=game[j];
				(*count)++;
				int p;
				for (p=j-1;p>i-3;p--) {
					game[p]=game[p-1];
				}
				game[p]=0;
			}
		}
	}
}

int righttest(int* game,int i,int j)
{
	int result=0;
	if (game[j]!=0) result=1;
	int p=0;
	for (;j>i-4;j--) {
		p+=game[j];
	}
	if (p==0) result=1;
	return result;
}

void up(int* game,int* count,int* score)
{
	int i;
	for (i=0;i<4;i++) {
		int j;
		for (j=i;j<16;j+=4) {
			while (uptest(game,j)==0) {
				int p;
				for (p=j;p<12;p+=4) {
					game[p]=game[p+4];
				}
				game[p]=0;
				(*count)++;
			}
		}
		
		for (j=i;j<16;j+=4) {
			if (game[j]==game[j+4] && game[j]!=0) {
				game[j]*=2;
				game[j+4]=0;
				*score+=game[j];
				(*count)++;
				int p;
				for (p=j+4;p<12;p+=4) {
					game[p]=game[p+4];
				}
				game[p]=0;
			}
		}
	}
}

int uptest(int* game,int j)
{
	int result=0;
	if (game[j]!=0) result=1;
	int p=0;
	for (;j<16;j+=4) {
		p+=game[j];
	}
	if (p==0) result=1;
	return result;
}

void down(int* game,int* count,int* score)
{
	int i;
	for (i=12;i<16;i++) {
		int j;
		for (j=i;j>=0;j-=4) {
			while (downtest(game,j)==0) {
				int p;
				for (p=j;p>=4;p-=4) {
					game[p]=game[p-4];
				}
				game[p]=0;
				(*count)++;
			}
		}
		
		for (j=i;j>=4;j-=4) {
			if (game[j]==game[j-4] && game[j]!=0) {
				game[j]*=2;
				game[j-4]=0;
				*score+=game[j];
				(*count)++;
				int p;
				for (p=j-4;p>=4;p-=4) {
					game[p]=game[p-4];
				}
				game[p]=0;
			}
		}
	}
}

int downtest(int* game,int j)
{
	int result=0;
	if (game[j]!=0) result=1;
	int p=0;
	for (;j>=0;j-=4) {
		p+=game[j];
	}
	if (p==0) result=1;
	return result;
}

void show(int* game,int* score)
{
	int i;
	for (i=0;i<16;i++){
		printf("%d\t",game[i]);
		if (i==3) printf("score\t%d",*score);
		if ((i+1)%4==0) printf("\n\n");
	}
}
