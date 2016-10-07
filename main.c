#include <stdio.h>
#include <stdlib.h>

	float x,y,del;
	int k,e;

int main(void)
{   
		
	del=1;
	y=1;
	char vop;
	do{	
		int o;
		system("cls");
		printf("\t*The app extracts the k-root of a number*\n\tEnter ESC to exit");
		enter_x();
		enter_k();
		enter_e();
		calculate(x,k,e);
  		getch();  
  		printf("\n\tDo u want to restart? If yes, click \"y\". If no, click \"n\"");
  		scanf("%c", vop);
  		((vop=='n')||(vop=='N'))?(exit(1)):(o = 0);
  		
	}
	while (getch()!=27);
}

enter_x (){
	char c;
	int i;
	do	{	
		printf("\nEnter number\n");
		scanf("%f%c", &x, &c);
		if (c!='\n')
		{
			printf("Enter only numbers\n");
			fflush(stdin);
		}
		else i=1;
	}
	while (i!=1);
	
}
enter_k (){
	char ch;
	int r;
	do	{	
		printf("\nEnter a root:\n");
		scanf("%d%c", &k, &ch);
		if ((ch!='\n')||(k==0))
		{
			printf("Enter only ineger numbers except 0\n");
			fflush(stdin);
			r=0;
		}
		else r=1;
			
		} 
	while (r!=1);	
}
enter_e(){
	char c; 
	int i;
	do{	
		printf("\nEnter a calculation accuracy in the range of 1 to 6:\n");
		scanf("%d%c", &e, &c);
		if ((e==1)||(e==2)||(e==3)||(e==4)||(e==5)||(e==6)&&(c=='\n')){
			i=1;
			printf("%d\n",e);}
		else {
			printf("Enter integer value of accuracy, please!");
			fflush(stdin);
			i=0;
			}
	}
	while (i!=1);
}

/*void exponent (void)
{
	int ke;
	ke=abs(k);
	yk=y;
	while (ke>2)
	{
		yk=yk*y;
		ke=ke-1;
	}
}
void root (void)
{
	int kr;
	kr=abs(k);
	d=(1.0/kr)*((x/yk)-y);
	y=y+d;
}
*/


calculate(void){
		if (x==0||x==1) printf("\n%d-root of %.3f is %f",k,x,x); 
		else if ((k==0)||((k>0)&&(k%2==0)&&(x<0))||((k<0)&&(k%2==0)&&(x<=0))||((k<0)&&(k%2==1)&&(x=0)))
					printf("\nIt\'s unreal to extract the k-root of a number. Wrong data!");
				else do{
		printf("\n%f   \n", y);
		del = (1.0/k) * ((x/pow(y,k-1)) - y);
		y += del;
		printf("\n%f   \n", y);
		printf("%f   >=   ", del);
		printf("%d   ", e);
	}
	while(fabs(del) >= e);
		printf("\n%d-root of %f is %.*f\n",k, x, e, y);
	
}
