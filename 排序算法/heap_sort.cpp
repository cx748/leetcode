#include <iostream>
#include <algorithm>
using namespace std;

//构建大顶堆
void max_heapify(int arr[], int start, int end){
    //建立父节点与子节点关系调整
    int dad = start ;
    int son = dad * 2 + 1;
    while (son <= end){
        if(son + 1 <= end && arr[son]< arr[son+1])//比较兄弟节点大小
            son++;
        if(arr[dad] > arr[son]) //比较父节点与子节点的大小
            return;
        else{
            swap(arr[dad], arr[son]);
            dad = son;
            son = dad *2 +1;
        }
    }
}

void heap_sort(int arr[], int len){
    for(int i = len/2 -1; i>=0; i--)//i从最后一个父节点开始调整
        max_heapify(arr, i, len-1);
    for(int i = len -1; i > 0; i--){
        swap(arr[0],arr[i]);
        max_heapify(arr,0, i-1);
    }
}

int main(){
    int arr[]={2,3,5,7,8,2,1,62,3,5,2,7,88,3,6,7,7,3,5,9};
    int len = (int) sizeof(arr)/sizeof(*arr);
    heap_sort(arr,len);
    for(int i : arr)
        cout << i <<' ';
    cout<<endl;
    return 0;
}