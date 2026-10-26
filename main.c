#include <stdio.h>
#define N 10

void quicksort(int arr[], int low, int high){
    int middle;
    int temp = arr[low];
    int start = low;
    int end = high;
    if(low >= high) return;

    while(low != high){
        while(arr[high] >= temp){
            if(low == high)
                break;
            high--;
        }
        if(low == high)
            break;
        arr[low] = arr[high];
        low++;
        while(arr[low] <= temp){
            if(low == high)
                break;
            low++;
        }
        if(low == high)
            break;
        arr[high] = arr[low];
        high--;
    }
    arr[low] = temp;
    middle = low;

    quicksort(arr, start, middle - 1);
    quicksort(arr, middle + 1, end);

}

int main(void){
    int arr[N];
    printf("Enter %d numbers: ", N);
    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    quicksort(arr, 0, N-1);

    for(int i = 0; i < N; i++)
        printf("%d ", arr[i]);

    return 0;

}
