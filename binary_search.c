#include <stdio.h>
void binarySearch(int [], int, int, int); 

int main(){
    int size = 0; 
    printf("Size = "); 
    scanf("%d", &size); 
    int arr[size] ; 
    printf("Enter Elements:\n"); 
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]); 
    }
    printf("\nArray Entered:\n");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]); 

    } 

    int ele; printf("Search Element: "); 
    scanf("%d", &ele); 
    int left =  0, right = size-1; 
    binarySearch(arr,ele,left, right); 

}

void binarySearch(int a[], int ele , int l, int r){
    int flag = 0, mid = 0; 
    while(l<=r){
        mid = (l+r)/2; 
        if(a[mid] == ele){
            flag = 1; break; 
        }
        if(a[mid] > ele){
            r = mid - 1; 
        } else l = mid + 1; 
    }   
    if(flag == 1){
        printf("Element FOUND at index: %d", mid); 
    } else printf("Element NOT FOUND."); 
}
