#include <iostream>
#include <cstring>

class String
{
private:
    
    std::size_t length;
    char *str = nullptr;

public:

    String(const char *s);
    String (const String &obj);
    String operator+=(const String &s);
    bool operator==(const String &s);
    String operator= (const String &s);
    friend std::ostream& operator<<(std::ostream &os , const String &s);
    int Length();
    void Clear();
    ~String();

};