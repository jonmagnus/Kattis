#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000003

int t, n;
int l[MAX_N], r[MAX_N], v[MAX_N], size[MAX_N];

int compute_size(int c) {
    int lsize, rsize;
    lsize = (l[c] == -1 ? 0 : size[l[c]]);
    rsize = (r[c] == -1 ? 0 : size[r[c]]);
    return lsize + rsize + 1;
}

void rotate_left(int parent, int root) {
    int right = r[root];
    if (l[parent] == root) l[parent] = right;
    else r[parent] = right;
    r[root] = l[right];
    l[right] = root;
    size[root] = compute_size(root);
    size[right] = compute_size(right);
}

void rotate_right(int parent, int root) {
    int left = l[root];
    if (l[parent] == root) l[parent] = left;
    else r[parent] = left;
    l[root] = r[left];
    r[left] = root;
    size[root] = compute_size(root);
    size[left] = compute_size(left);
}

void balance(int parent, int c) {
    if (l[c] == -1 && r[c] == -1) return;
    if (l[c] == -1) {
        if (size[r[c]] > 2) rotate_left(parent, c);
    } else if (r[c] == -1) {
        if (size[l[c]] > 2) rotate_right(parent, c);
    } else {
        if (size[l[c]] > 2*size[r[c]]) rotate_right(parent, c);
        else if (size[r[c]] > 2*size[l[c]]) rotate_left(parent, c);
    }
}

void insert(int c, int i) {
    size[c]++;
    if (v[i] > v[c]) {
        if (r[c] == -1) {
            r[c] = i;
        } else {
            insert(r[c], i);
            balance(c, r[c]);
        }
    } else {
        if (l[c] == -1) {
            l[c] = i;
        } else {
            insert(l[c], i);
            balance(c, l[c]);
        }
    }
}

int get(int c, int i) {
    if (l[c] == -1 || i >= size[l[c]]) {
        if (i == 0 || i == size[l[c]]) return c;
        else return get(r[c], i + size[r[c]] - size[c]);
    } else return get(l[c], i);
}

int main() {
    scanf("%d ", &t);
    while (t--) {
        scanf("%d ", &n);
        memset(l, -1, n*sizeof(int));
        memset(r, -1, n*sizeof(int));
        memset(size, 0, n*sizeof(int));
        long long s = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d ", &v[i]);
            //fprintf(stderr, "%d %d\n", i, v[i]);
            size[i] = 1; if (i > 0) insert(0, i);
            int lo, hi;
            lo = i/2;
            hi = (i + 1)/2;
            if (hi != lo) {
                s += (v[get(0, lo)] + v[get(0, hi)])/2;
            } else {
                s += v[get(0, lo)];
            }
        }
        printf("%lld\n", s);
    }
    return 0;
}
