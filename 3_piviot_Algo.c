void quicksort3PivotBasic(int A[], int lo, int hi) {
    int length = hi - lo + 1;
    int midpoint;
    int p,q,r;
    int a,b,c,d;
    int t;
    if(hi-lo < 1 || lo<0 || hi<0 )
        return;
    midpoint = (lo + hi) /2;
    if (A[midpoint] < A[lo])
    {
        t = A[midpoint];
        A[midpoint] = A[lo];
        A[lo] = t;
    }
    if (A[hi] < A[midpoint])
    {
        t = A[hi];
        A[hi] = A[midpoint];
        A[midpoint] = t;
        if (t < A[lo])
        {
            A[midpoint] = A[lo];
            A[lo] = t; }
    }
    p = A[lo];
    q = A[midpoint];
    r = A[hi];
    swap(A, lo+1, midpoint);
    a = lo + 2;
    b = lo + 2;
    c = hi - 1;
    d = hi - 1;
    while (b <= c)
    {
        //printf("\n--- WHILE START");
        //print(A,n);
        while (A[b] < p && b <= c)
        {
            if (A[b] < r) {
                swap(A, a, b);
                a++; }
            b++; }
        while (A[c] > q && b <= c)
        {
            if (A[c] > r) {
                swap(A, c, d);
                d--; }
            c--; }
        if (b <= c) {
            if (A[b] > r) {
                if (A[c] < p) {
                    swap(A, b, a); swap(A, a, c);
                    a++;
                } else {
                    swap(A, b, c);
                }
                swap(A, c, d);
                b++;
                c--;
                d--;
            } else {
                if (A[c] < p) {
                    swap(A, b, a); swap(A, a, c);
                    a++;
                } else {
                    swap(A, b, c);
                }
                b++; c--; }
        }
//  printf("\n--- WHILE END");
//  print(A,n);
    }
    a--; b--; c++; d++;
    swap(A, lo + 1, a); swap(A, a, b);
    a--;
    swap(A, lo, a);
    swap(A, hi, d);
    quicksort3PivotBasic(A, lo, a-1);
    quicksort3PivotBasic(A, a+1, b-1);
    quicksort3PivotBasic(A, b+1, d-1);
    quicksort3PivotBasic(A, d+1, hi);
}
