#include <stdio.h>

int main() {
    int base[8] = {0, 1500, 4500, 9000, 35000, 55000, 80000, 10000000};
    int percent[7] = {3, 10, 20, 25, 30, 35, 45};
    
    int get;
    int wage = 0;
    scanf("%d", &get);
    if(get <= 3500) {
        printf("%d\n", get);
        return 0;
    }
    get -= 3500;
    wage += 3500;
    for(int l=0; l<7; l++) {
        int maxRemain = (base[l+1] - base[l]) * (100 - percent[l]) / 100;
        //printf("%d %d %d\n", maxRemain, get, wage);
        if(get <= maxRemain) {
            wage += 100 * get / (100 - percent[l]);
            get = 0;
            break;
        }
        else {
            wage += (base[l+1] - base[l]);
            get -= maxRemain;
        }
    }
    printf("%d\n", wage);
}
