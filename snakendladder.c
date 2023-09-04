#include<stdio.h>
#include<stdlib.h>
int n,f1=0,f2=0,f=0;

void play()
{	
	int i,j,d,k;
	int p1=1,p2=1;
	
	for(k=1;k<=n;k++)
	{
		if(f==0)
		{
			printf("\nplayer %d rolling the dice.\n",k);
			printf("This is what you got\n");
			printf(".......%d.........\n",dice(k));
		}
		else
			printf("\n player %d roll the damn dice.\n",k);
		printf("Enter the number on the dice to make your move. let<s GO...!\n");
		scanf("%d",&d);
		if(k==1)
			p1=p1+d;
		else
			p2=p2+d;
		
		if(d==6&&k==1)
			f1=1;
		if(d==6&&k==2)
			f2=1;
		
		if(f1==0&&k==1)
		{	
			printf("HE he he he...!Better luck next time. Need a 6 to step out\n\n");
			p1=1;
		}
		else if(f2==0&&k==2)
		{	printf("Kui kui...! Is that all you got ? Score 6 and you'll be freeeeeeee....!!\n\n'");
			p2=1;
		}
		
		if(k==1)
		{
			p1=snake(&p1);
			p1=ladder(&p1);
		}
		else
		{
			p2=snake(&p2);
			p2=ladder(&p2);
		} 
			
		printf("START ");
		for(j=2;j<=10;j++)
		{
			if(p1==j&&p2==j)
				printf(" P1P2 ");
			else if(p2==j)
				printf("  P2  ");
			else if(p1==j)
				printf("  P1  ");
			else
				printf("   %d  ",j);
		}
		printf("\n");

		for(i=2;i<=10;i++)
		{
			while(j<=10*i)
			{	
				if(j==100)
				{
					printf("HOME");
					break;
				}
				if(j==98||j==82||j==32||j==54)
					printf("SNAKE ");
				else if(j==57||j==39||j==11||j==70)
					printf("LADDER");
				else if(p1==j&&p2==j)
					printf(" P1P2 ");
				else if(p2==j)
					printf("  P2  ");
				else if(p1==j)
					printf("  P1  ");
				else
					printf("  %d  ",j);
					
				j++;		
			}
			printf("\n");
		}
		if(k==2)
			k=0;
		if(p1>=100 || p2>=100)
			break;
	}
if(p1<100)
	printf("Congratulations player P2...!\n You succesfully managed to waste your time..\n HE he he he....!!!");
else 
	printf("Congratulations player P1...!\n You succesfully managed to waste your time..\n HE he he he....!!!");
	

}
int snake(int *p)
{
	if(*p==98)
		return 5;
	if(*p==82)
		return 61;
	if(*p==54)
		return 31;
	if(*p==32)
		return 20;
return *p;
}

int ladder(int *p)
{
	if(*p==70)
		return 96;
	if(*p==57)
		return 75;
	if(*p==39)
		return 69;
	if(*p==11)
		return 51;
return *p;
}

int dice(int k)
{
	int d;
	d=rand()%10-3;

	//if(d==6&&k==1)
	//	f1=1;
//	if(d==6&&k==2)
//		f2=1;
		
	if(d==0)
		return d=6;
	if(d<0)
		return d=d*-1;
	return d;
	
}

int main()
{	
	printf("\n                                             SNAKE & LADDER               \n\n");
	printf("\nGuess what....The fun part is that you don't no where the hell the snake or the ladder is gonna take you\n");
	printf("\nSome important info. about the game\n");
	printf("\nThis is a multiplayer game. player1 {P1} and player2 {P2} pull your socks and get ready.\nAnd the most important part those snakes are NOT POISONOUS :-) :-)");
	printf("\nEnter 2 to start the game.\n");
	scanf("%d",&n);
	printf("Waaaaiiittttt...! Did you guys bring a dice? press 1 if yes and if no press 0 . \n");
	scanf("%d",&f);
	n=2;
	play();
	
return 0;	
}
