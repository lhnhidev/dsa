#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int giao[n], toiUu[n]; 
    for (int i = 0; i < n; i++) {
        scanf("%d", &giao[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &toiUu[i]);
    }
    
    int time = 0; 
    int start = 0;
    
    for (int i = 0; i < n; i++) {
        while (giao[start] != toiUu[i]) {
            int temp = giao[start];
            for (int j = 0; j < n - 1; j++) {
                giao[j] = giao[j + 1];
            }
            giao[n - 1] = temp;
            time++; 
        }
        start++; 
        time++; 
    }
    
    printf("%d\n", time);
    
    return 0;
}

