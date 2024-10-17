#include <iostream> 
using namespace std;

const int MAXINT = 10000;

void merge(int list[], int sorted[], int i, int m, int n){ // m=tail of first sublist; n=tail of second sublist
    int j, k, t;
    k = i;
    j = m + 1;
    while(i <= m && j <= n){
        if(list[i] <= list[j]){
            sorted[k++] = list[i++];
        }
        else 
            sorted[k++] = list[j++];
    }
    if(i > m){
        for(t = j; t <= n; t++)
            sorted[k+t-j] = list[t];
    }
    else{
        for(t = i; t <= m; t++)
            sorted[k+t-i] = list[t];
    }
}

void merge_pass(int list[], int sorted[], int n, int length){  // n = the number of elements in the list
    int i;
    for(i = 0; i <= n - 2*length; i += 2*length){  // merge two groups together
        merge(list, sorted, i, i+length-1, i+ 2*length - 1);
    }
    if(i < n - length) // merge the rest if there are more than one group but less than two group
        merge(list, sorted, i, i+length-1, n-1);
    while(++i < n){  // there just one group left
        sorted[i] = list[i];
    }
}

void merge_sort(int list[], int n){
    int length = 1;
    int sorted[MAXINT];
    while(length < n){
        merge_pass(list, sorted, n, length);
        length *= 2;
        merge_pass(sorted, list, n, length);
        length *= 2;
    }
}


// ---------------------------------------
// recursive version

int re_merge_sort(int list[], int sorted[], int lower, int upper){
    int middle;
    if(lower >= upper)
        return lower;
    else{
        middle = (lower + upper) / 2;
        return merge(list, sorted, )
    }
}