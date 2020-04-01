template<typename T>
void select_sort(std::vevtor<T>& arr){
    for(int i = 0; i < arr.size()-1; i++){
        int min = i;
        for(int j = i+1; j < arr.size(); j++)
            if(arr[j]<arr[min])
                min = j;
            std::swap(arr[i], arr[min]);
    }
}