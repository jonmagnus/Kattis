#include <stdio.h>
#define MAX_N 1000003

int left[2*MAX_N], right[2*MAX_N];
int lstart, lend, rstart, rend;

void push_front(int v) { left[--lstart] = v; }
void push_back(int v) { right[rend++] = v; }
void push_middle(int v) {
    while (lend - lstart < rend - rstart) left[lend++] = right[rstart++];
    while (lend - lstart > rend - rstart + 1) right[--rstart] = left[--lend];
    left[lend++] = v;
}
int get_(int i) {
    if (i < lend - lstart) return left[lstart + i];
    return right[rstart + i + lstart - lend];
}

void content() {
    int i;
    printf("left: ");
    for (i = lstart; i < lend; i++) printf("%d ", left[i]);
    printf("\nright: ");
    for (i = rstart; i < rend; i++) printf("%d ", right[i]);
    printf("\n");
}

int main() {
    lstart = lend = rstart = rend = MAX_N;
    int n;
    scanf("%d ", &n);
    while (n--) {
        char cmd[20];
        cmd[5] = 0;
        int v;
        scanf("%s %d ", cmd, &v);
        switch (cmd[5]) {
        case 'b':
                push_back(v);
                break;
            case 'f':
                push_front(v);
                break;
            case 'm':
                push_middle(v);
                break;
            case 0:
                printf("%d\n", get_(v));
                break;
        }
    }
    return 0;
}
