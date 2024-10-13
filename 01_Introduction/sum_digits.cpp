#include <iostream>

int main ()
{
    int num,rem;
    int sum = 0;
    std::cout<<"Enter the number: ";
    std::cin>>num;

    while(num!=0)
    {
        rem = num % 10 ;
        sum += rem;
        num /= 10; 

    }

    std::cout <<"The sum of the digits: "<<sum<<std::endl;
   
    return 0 ;
}

