template<typename T>
void shell_sort(T array[], int length){
    int h = 1;
    while(h < length / 3){
        h = h*3 +1;//初始增量
    }
    while(h >= 1){
        for(int i = h; i < length; i++){
            for(int j = i; j >= h && array[j]<array[j-h];j -= h){
                std::swap(array[j], array[j-h]);
            }
        }
        h = h/3;//缩小增量
    }
}