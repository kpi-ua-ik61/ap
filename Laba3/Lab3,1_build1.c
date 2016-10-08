#include <curses.h>
#include <stdio.h>
#include <math.h> // sqrt
#include <stdlib.h> // Я отсюда юзаю exit()

void error(char* errorMsg) {
	printf("\n %s \n ", errorMsg);
	exit(0);
}

float myFunc(float x, float k, float e) {
    float b = 1;
    float y = 1;

    while (fabsf(b) >= e) {
        b = ((1 / k) * ((x / pow(y, k-1) - y)));
        y = (y + b);
        printf("\n%f %f\n", y, b);
    }

    return y;
}
void resulter()
{
   sprintf(num, "%i", 7);
   strcpy(dest, "And the sum is: %.");
   strcat(dest, num);
   strcat(dest, "f");
}

int main(void) {
    float x = 4.5;
    float k = 2;
    float e = 0.001;
    float y;

    printf("\n x = %f \n k = %f \n e = %f\n", x, k , e);

    y = myFunc(x, k, e);

    printf("\n y = %.3f\n", y);
}