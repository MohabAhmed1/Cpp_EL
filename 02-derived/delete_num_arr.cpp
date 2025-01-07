#include <iostream>


int  search_num(int *arr,int &arr_size, int &desired_num)
{
    int mid,low = 0  ,high = arr_size - 1;

    while (low <= high)
    {
        mid = low + (high - low) /2 ;
        if (arr[mid] < desired_num)
        {
            low = mid + 1;
        }
        else if ( arr[mid] > desired_num)
        {
            high = mid - 1 ;
        }
        else
        {
            return mid;
        }

    }
    return -1 ;
}
void delete_num(int *arr,int &arr_size, int &deleted)
{
    // first finding the index of the number  
    int num_index = search_num(arr , arr_size , deleted);

    // refactor the array after deletion  
    if(num_index == -1)
    {
        std::cout<<"The number is not in the Array"<<std::endl;
    }
    else
    {
        for (int i = num_index  ; i < arr_size - 1 ; i++ )
        {
            arr[i] = arr[i+1];
        }
        arr_size --;
    }    
}

    
int main() {

    int arr_size;
    int deleted_element ;
    std::cout<<"Enter the size of the array : ";
    std::cin>>arr_size;
    int arr[arr_size];
    std::cout<<"Enter the elements of the array : "<<std::endl;
    for (int i = 0 ; i < arr_size ;i++)
    {
        std::cin>>arr[i];
    }
    std::cout<<"Enter the elements to delete : ";
    std::cin>>deleted_element;
    delete_num(arr,arr_size,deleted_element);
    for (int i = 0 ; i < arr_size;i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;


    return 0;
}
