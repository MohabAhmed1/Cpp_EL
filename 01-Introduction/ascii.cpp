#include <iostream>
int main ()
{
    std::cout<<" ASCII Code Table "<<std::endl;
    std::cout<<"+-------+-------+"<<std::endl;
    std::cout<<"| Char | ASCII |"<<std::endl;
    std::cout<<"+-------+-------+"<<std::endl;
    for (char i = 0 ; i < 127 ; i++)
    {
        if(i>32)  
            printf("|  %d  |  %c  |\n", int(i), i);
        else
            printf("|  %d  |     |\n", int(i));
    }
    return 0 ;
}
