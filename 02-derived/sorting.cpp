#include <iostream>
#include <vector>
#include <algorithm>

 void sorting(std::vector <int>& arr,const bool order_type)
    { 
        std::sort(arr.begin(),arr.end(),[order_type](int a , int b){
            return order_type ? a<b : a>b ;
        }); 
        std::cout<<"The sorted Array:"<<std::endl;
        for(int i = 0 ; i < arr.size() ; i++)
        {
            std::cout<<arr[i]<<" ";
        }
        std::cout<<std::endl;
    }  
int main() {


    constexpr bool ascending = true;
    constexpr bool descending = false;
    bool order ;
    std::vector <int > arr;
   int arr_size,input;
   std::cout<<"Enter the size of the array:";
   std::cin>>arr_size;
   std::cout<<"Enter the elements of the array:"<<std::endl;
   for(int i = 0 ; i < arr_size ; i++)
   {
        std::cin>>input;
        arr.push_back(input);
   }
   std::cout<<"Choose the acending(1) or descending(0) :";
   std::cin>>order;
   if(order)
   {
       sorting(arr,ascending);

   }
   else
   {
       sorting(arr,descending);
   }

    return 0;
}
