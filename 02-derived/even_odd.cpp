#include <iostream>
#include <vector>

void even_odd (std::vector<int>& arr)
{
    std::vector <int> even;
    std::vector <int> odd;
    for(int i = 0 ; i < arr.size(); i++ )
    {
        if(arr[i] % 2 == 0)
        {
            even.push_back(arr[i]);
        }
        else
        {
            odd.push_back(arr[i]);
        }
    }
    std::cout<<"Even array:"<<std::endl;
    for(int i = 0 ; i < even.size(); i++ )
    {   
        std::cout<<even[i]<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"Odd array:"<<std::endl;
    for(int i = 0 ; i < odd.size(); i++ )
    {   
        std::cout<<odd[i]<<" ";
    }
    std::cout<<std::endl;

}

    
int main() {

   std::vector <int > arr;
   int arr_size,input;
   std::cout<<"Enter the size of the array:";
   std::cin>>arr_size;
   for(int i = 0 ; i < arr_size ; i++)
   {
    std::cin>>input;
    arr.push_back(input);
   } 
    even_odd(arr);
    


    return 0;
}
