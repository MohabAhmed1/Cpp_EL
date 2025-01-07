#include <iostream>


    
int main() {


    auto square = [](int num)
    {
        return num*num;    
    };
    int num;
    std::cout<<"Enter the number to be squared :";
    std::cin>>num;
    std::cout<<square(num)<<std::endl;

    return 0;
}
