#include <iostream>


bool isVowel(char x);

int main ()
{
    char x ; 
    std::cout<<"Enter the character :";
    std::cin>>x;
    if(isVowel(x))
        std::cout<<"The character is Vowel"<<std::endl;
    else
        std::cout<<"The character is not Vowel"<<std::endl;
    return 0 ;
}

bool isVowel(char x)
{
    if (tolower(x)=='a' || tolower(x)=='e' || tolower(x)=='o' || tolower(x)=='i' || tolower(x)=='u')
        return true;
    else
        return false;
}
