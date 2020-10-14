#include <stdio.h>
#include <stdlib.h>
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

void fastprint(int i) {
    int count = 0;
    char buffer[20];
    while (i) {
        buffer[count++] = '0' + (i % 10);
        i /= 10;
    }
    while (count--) putchar_unlocked(buffer[count]);
    putchar_unlocked('\n');
}

int main() {
    int n, v;
    char buffer[30];
    lstart = lend = rstart = rend = MAX_N;
    fgets(buffer, 30, stdin);
    n = atoi(buffer);
    while (n--) {
        buffer[5] = 0;
        fgets(buffer, 30, stdin);
        switch (buffer[5]) {
        case 'b':
                v = atoi(buffer + 10);
                push_back(v);
                break;
            case 'f':
                v = atoi(buffer + 11);
                push_front(v);
                break;
            case 'm':
                v = atoi(buffer + 12);
                push_middle(v);
                break;
            default:
                v = atoi(buffer + 3);
                fastprint(get_(v));
                break;
        }
    }
    return 0;
}
