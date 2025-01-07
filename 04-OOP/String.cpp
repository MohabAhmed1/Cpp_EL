#include <iostream>
#include <cstring>
#include "String.hpp"

    // Paramatized Constructor
    String::String(const char *s)
    {
        length = std::strlen(s);
        str = new char[length+1];
        std::strcpy(str,s);

    }
    // Copy Constructor
    String::String (const String &obj)
    {
        this -> str = new char [obj.length + 1 ];
        this -> str = strcpy(this->str ,  obj.str);
    }
    int String::Length()
    {
        return this -> length ; 
    }
    void String::Clear()
    {
        delete[] this -> str ;
        this -> str = nullptr;
        this -> length = 0;
    }   

    
    // Concatenate operator overloading 
    String String::operator+=(const String &s)
    {
        std::size_t new_length = this -> length + strlen(s.str);
        
        char *new_str = new char[new_length + 1];
        strcpy(new_str , this -> str);

        strcat(new_str , s.str);

        delete[] this -> str;

        this->str = new_str;
        this -> length = new_length;

        return *this ;
    }
    // Equality operator overloading 
    bool String::operator==(const String &s)
    {
        return strcmp(this->str ,s.str) == 0 ;
    }
    // Assignment operator overloading
    String String::operator= (const String &s)
    {
        if(this -> str == s.str)
        {
            return *this;
        }
        delete this -> str;
        this -> str = new char [s.length + 1];
        strcpy(this -> str , s.str); 
        return *this;
    }
    //Destructor
    String::~String()
    {
        delete[] str ;
        str = nullptr;
    }
    // operator overloading for cout<<
    std::ostream& operator<<(std::ostream &os , const String &s)    
    {
    return os << s.str ;
    }
