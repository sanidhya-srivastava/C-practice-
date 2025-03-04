#include <stdio.h>
#include <stdlib.h>
#define MAX_PAGES 256

int main() {
   int n, m;
   printf("Enter the number of page references: ");
   scanf("%d", &n);
   printf("Enter the number of page frames: ");
   scanf("%d", &m);
   int pages[MAX_PAGES];
   int frames[MAX_PAGES];
   printf("Enter the page reference string: ");
   for (int i = 0; i < n; i++) {
       scanf("%d", &pages[i]);
   }
   for (int i = 0; i < m; i++) {
       frames[i] = -1;
   }
   int page_faults = 0;
   int front = 0;
   for (int i = 0; i < n; i++) {
       int page = pages[i];
       int found = 0;
       for (int j = 0; j < m; j++) {
           if (frames[j] == page) {
               found = 1;
               break;
           }
       }
       if (!found) {
           page_faults++;
           frames[front] = page;
           front = (front + 1) % m;
       }
   }
   printf("Total Page Faults: %d\n", page_faults);
   return 0;
}