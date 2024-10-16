#include <iostream>

void arr_creator (int *arr , int &arr_size)
{
    std::cout<<"Enter the elements of the array : ";
    for (int i = 0 ; i < arr_size ;i++)
    {
        std::cin>>arr[i];
    }
    for (int i = 0 ; i < arr_size;i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
  
}
void merge_arrays(int *arr1 , int *arr2, int arr1_size , int arr2_size)
{
    int merged_arr[arr1_size+arr2_size];
    for(int i=0 ; i< (arr1_size+arr2_size) ; i++)
    {
        if(i<arr1_size)
        {
            merged_arr[i]=arr1[i];
        }
        else 
        {
            merged_arr[i]=arr2[i-arr2_size];
        }
    }

    for (int i = 0 ; i < (arr1_size+arr2_size) ;i++)
    {
        std::cout<<merged_arr[i]<<" ";
    }
        std::cout<<std::endl;

}

    
int main() {

    int arr1_size,arr2_size;
    std::cout<<"The first array : ";
    std::cout<<"Enter the size of the  first array : ";
    std::cin>>arr1_size;
    int arr1[arr1_size];
    arr_creator(arr1,arr1_size);

    std::cout<<"The second array : ";
    std::cout<<"Enter the size of the second array : ";
    std::cin>>arr2_size;
    int arr2[arr2_size];
    arr_creator(arr2,arr2_size);
    merge_arrays(arr1,arr2,arr1_size,arr2_size);
  
    


    return 0;
}
