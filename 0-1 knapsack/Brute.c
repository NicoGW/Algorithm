#include <stdio.h>
#include <math.h>

int n, M;
int P[105];
int W[105];
int C[105] = {0};

void Brute(){
    int temp_p, temp_w, ptr, ans = 0;
    for(int i = 1; i <= pow(2, n); i++){
        ptr = n;
        temp_p = 0;
        temp_w = 0;
        while((C[ptr] != 0) && ptr > 0){
            C[ptr] = 0;
            ptr--;
        }
        C[ptr] = 1;
        for(int j = 1; j < n; j++)
            if(C[j] == 1){
                temp_p += P[j];
                temp_w += W[j];
            }
        if((temp_p > ans) && (temp_w <= M))
            ans = temp_p;
    }
    printf("%d\n", ans);
}

int main(){
    scanf("%d %d", &n, &M);
    for(int i = 1; i <= n; i++)
        scanf("%d %d", &P[i], &W[i]);
    
    Brute();
    
    return 0;
}
