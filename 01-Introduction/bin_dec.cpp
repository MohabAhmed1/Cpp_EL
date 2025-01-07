#include <iostream>
#include <bitset>
#include <string>
int main ()
{
    int dec_num;
    std::string binary_num;
    std::cout << "Enter the Number to represent in binary: ";
    std::cin>>dec_num;
    std::bitset<8>binary(dec_num); 
    std::cout <<"The binary representation :" << binary <<std::endl;
    
    std::cout << "Enter the Number to represent in decimal:";
    std::cin>>binary_num;
    std::bitset<8>binaries(binary_num); 
    dec_num = binaries.to_ulong();
    std::cout <<"The decimal representation : " << dec_num <<std::endl;

    

    return 0 ;
}

