#include <stdio.h>

int modularExponentiation(int base,int power,int mod) {
    int result=1;
    base=base%mod;

    while(power>0){
        if(power%2==1){
            result =(result*base)%mod;
        }
        power=power/2;
        base=(base*base)%mod;
    }

    return result;
}

int main() {
    int base, power, mod;

    printf("Enter the base\n");
    scanf("%d",&base);

    printf("Enter the power\n");
    scanf("%d",&power);
    if(power<0){
        printf("Power cannot be negative.\n");
        return 1;
    }

    printf("Enter the modulo\n");
    scanf("%d", &mod);
    if (mod <= 1) {
        printf("Modulo must be greater than 1.\n");
        return 1;
    }

    int answer = modularExponentiation(base, power, mod);
    printf("%d^%d %% %d = %d\n",base,power,mod,answer);

    return 0;
}
