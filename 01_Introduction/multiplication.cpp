#include <iostream>



int main ()
{
    int num;
    std::cout<<"Enter the number of the multiplication table : ";
    std::cin>>num;

    for (int i = 1 ; i <= 10 ; i++)
    {
        std::cout<<num <<'x'<< i << '=' <<num*i <<std::endl; 
    }
   
    return 0 ;
}

