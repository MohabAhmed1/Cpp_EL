#include <iostream>
#include "OpenXLSX/OpenXLSX.hpp"
#include <filesystem>


class Address_book
{
private:
    OpenXLSX::XLDocument doc;
    std::string filepath = "address_book.xlsx";
    OpenXLSX::XLWorksheet wks;
    int choice ;
    int Global_cell_counter ;
    std::string name;
    std::string num;
    std::string address;
    std::string col1 ,col2,col3;

public:
    Address_book();
    ~Address_book();
    void Menu();
    void List();
    void Add();
    void Update();
    void Delete();
    void Delete_all();
    void Search();
    int get_empty_index();
    std::string capitalize_first_letter(std::string name);
    void clearAndshift_rows_up(int deleted_row_num);

};