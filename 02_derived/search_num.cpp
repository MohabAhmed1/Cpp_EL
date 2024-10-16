#include <iostream>


bool search_num(int *arr,int arr_size, int &desired_num)
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
            return true;
        }

    }
    return false ;
}
int main() {

    int arr_size;
    int desired_element ;
    std::cout<<"Enter the size of the array : ";
    std::cin>>arr_size;
    int arr[arr_size];
    std::cout<<"Enter the elements of the array : "<<std::endl;
    for (int i = 0 ; i < arr_size ;i++)
    {
        std::cin>>arr[i];
    }
    std::cout<<"Enter the elements to search : ";
    std::cin>>desired_element;

    std::cout<<"The desired number "<<desired_element<<" is "<<((search_num(arr,arr_size,desired_element)) ? "Found" : "Not found ") <<std::endl;
    return 0;
}
