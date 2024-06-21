#include <stdio.h>
void zap(int n) { if (n < 1) { return; } if (n <= 2) {
putchar('*'); zap(n-1); return; } if (n >= 2) {
putchar('<'); zap(n-2); putchar('>'); } } int main() {
printf("\n 1."); zap(1); printf("\n 2."); zap(2); printf("\n 3.");
zap(3); printf("\n 4."); zap(4); printf("\n 5."); zap(5);
printf("\n 6."); zap(6); printf("\n 7."); zap(7);
printf("\n 8."); zap(8);  return 0;  }
