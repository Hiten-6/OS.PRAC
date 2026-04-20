#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    int req[n];

    printf("Enter the disk request sequence:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }

    int head;
    printf("Enter initial head position: ");
    scanf("%d", &head);

    int seek_time = 0;

    printf("\nOrder of execution:\n");

    // Print initial head position
    printf("%d -> ", head);

    for(i = 0; i < n; i++) {
        printf("%d -> ", req[i]);
        seek_time += abs(head - req[i]);
        head = req[i];
    }

    printf("End");

    printf("\n\nTotal Seek Time = %d\n", seek_time);

    return 0;
}
