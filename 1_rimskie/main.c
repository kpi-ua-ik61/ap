#include <stdio.h>//fynkcia, kotoraa imeet komnd vvoda/vivoda // preprocessorna direktiva
#include <conio.h>// opis' fynkcii ypravlenie ekranom

    roman(int i, int j, char c)//vipolnaet'sa fynkcia roman 
{
    while(i>=j) //ispolnaet'sa do teh por, poka i=0, potom finish
    { 
        putchar(c); 
        i = i-j; 
    } 
return i; 
}


int main() 
{     
int a; 
    printf("ENTER YEAR\n");//vivod na ekran soobshenia
    scanf(" %d", &a);//schitaka vvedennogo chisla // %d - specifikator vvoda - beret adress iacheiki    
    if (a<=0)
    {
        printf("error:)");
    } 
    else
        {
            a=roman(a,1000 , 'M'); 
            a=roman(a, 500, 'D'); 
            a=roman(a, 100, 'C'); 
            a=roman(a, 50, 'L'); 
            a=roman(a, 10, 'X'); 
            a=roman(a, 5, 'V'); 
            a=roman(a, 1, 'I'); 
            getch(); //zaderzhka ekrana do napisania informacii 
        
            return 0;//vihod iz fynkcii // operator
        }
    getch();
}
