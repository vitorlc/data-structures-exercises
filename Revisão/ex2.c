#include <stdio.h>

int main(){


    int num1 = 0, num2 = 0, maior = 0, reverse = 0;

    scanf("%d %d", &num1, &num2 );

    if(num1%10 > num2%10) {
        maior = num1;
    } else if(num2%10 > num1%10){
        maior = num2;
    } else if (num1%10 == num2%10) {
        if(num1%100 > num2%100) {
            maior = num1;
        } else if(num2%100 > num1%100){
            maior = num2;
        } else if(num2%100 == num1%100){
            if(num1%1000 > num2%1000) {
                maior = num1;
            } else if(num2%1000 > num1%1000){
                maior = num2;
            }
        }
    }
    
    while(maior!= 0) {
        reverse = reverse * 10;
        reverse = reverse + maior%10;
        maior = maior/10;
    }
    printf("%d\n", reverse);
   
    return 0;
}