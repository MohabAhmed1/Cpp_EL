#include <iostream>
int max_num(int *arr,int arr_size)
{
    int max = arr[0];

    for(int i = 0 ; i < arr_size ; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max ;
}

int main() {

    int arr_size;
    std::cout<<"Enter the size of the array : ";
    std::cin>>arr_size;
    int arr[arr_size];
    std::cout<<"Enter the elements of the array : "<<std::endl;
    for (int i = 0 ; i < arr_size ;i++)
    {
        std::cin>>arr[i];
    }
    std::cout<<"The Max number is "<<max_num(arr,arr_size)<<std::endl;
    return 0;
}
