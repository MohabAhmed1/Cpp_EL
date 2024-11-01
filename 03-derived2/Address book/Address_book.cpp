#include "Address_book.hpp"
#include <iostream>
#include "OpenXLSX/OpenXLSX.hpp"
#include <filesystem>

    Address_book::Address_book()
    {

        if (std::filesystem::exists(filepath))
        {
            
            doc.open(filepath);
            wks = doc.workbook().worksheet("Sheet1");
            doc.save();
            
        }    
        else
        {
            doc.create(filepath); 
            wks = doc.workbook().worksheet("Sheet1");
            doc.save();

        }
        Global_cell_counter = 1;
    }

    Address_book::~Address_book()
    {
        if (doc.isOpen()) 
        {
            doc.save();
            doc.close();
        }
    }


    void Address_book::Menu()
    {
        while (true)
        {
            std::cout<<"---------------------------------"<<std::endl;
            std::cout<<"Welcome to Address book database:"<<std::endl;
            std::cout<<"1.List"<<std::endl;
            std::cout<<"2.Add"<<std::endl;
            std::cout<<"3.Update"<<std::endl;
            std::cout<<"4.Delete"<<std::endl;
            std::cout<<"5.Delete All"<<std::endl;
            std::cout<<"6.Search"<<std::endl;
            std::cout<<"7.Close"<<std::endl;
            std::cout<<"---------------------------------"<<std::endl;
            std::cin>>choice ;

            switch (choice)
            {
            case 1:
                List();
                break;
            case 2:
                Add();
                break;
            case 3:
                Update();
                break;
            case 4:
                Delete();
                break;
            case 5:
                Delete_all();
                break;
            case 6:
                Search();
                break;
            case 7:
                std::cout<<"Thank you , Have a good day "<<std::endl;
                return;
                break;    
            default:
                std::cout<<"Wrong Entry"<<std::endl;
               break;
               
            }
        }
        

    }

    void Address_book::List()
    {
        int Local_cell_counter = 1 ;
        while (wks.cell(OpenXLSX::XLCellReference("A" + std::to_string(Local_cell_counter))).value().type() != OpenXLSX::XLValueType::Empty) 
        {  
            col1 = "A" + std::to_string(Local_cell_counter) ;
            col2 = "B" + std::to_string(Local_cell_counter) ;
            col3 = "C" + std::to_string(Local_cell_counter) ;
            std::cout<<wks.cell(col1)<<" | "<< wks.cell(col2)<<" | "<< wks.cell(col3)<<std::endl;
            Local_cell_counter++;
        }
    }
    void Address_book::Add()
    {
        std::cout<<"Enter the Name:";
        std::cin>>name;
        name = capitalize_first_letter(name);
        std::cout<<"Enter the Number:";
        std::cin>>num;
        std::cout<<"Enter the Address:";
        std::cin>>address;
        address = capitalize_first_letter(address);        
        while (wks.cell(OpenXLSX::XLCellReference("A" + std::to_string(Global_cell_counter))).value().type() != OpenXLSX::XLValueType::Empty) 
        {  
            Global_cell_counter++;
        }
        col1 = "A" + std::to_string(Global_cell_counter) ;
        col2 = "B" + std::to_string(Global_cell_counter) ;
        col3 = "C" + std::to_string(Global_cell_counter) ;
        wks.cell(col1).value() = name;
        wks.cell(col2).value() = num;
        wks.cell(col3).value() = address;
    }
    int Address_book::get_empty_index()
    {
        while (wks.cell(OpenXLSX::XLCellReference("A" + std::to_string(Global_cell_counter))).value().type() != OpenXLSX::XLValueType::Empty) 
        {  
            Global_cell_counter++;
        }
        return Global_cell_counter;
    }
    void Address_book::Update()
    {
        int Local_cell_counter = 1 ;
        std::cout<<"Enter the Name to be updated :";
        std::cin>>name;
        name = capitalize_first_letter(name);
        while((wks.cell("A" + std::to_string(Local_cell_counter)).value()!=name)&&(Local_cell_counter<get_empty_index()))
        {
            Local_cell_counter++;
        }
        if (Local_cell_counter == get_empty_index())
        {
            std::cout<<"The Name not found!!, Try again"<<std::endl;
        }
        else
        {
        std::cout<<"Enter the number to be updated :";
        std::cin>>num;
        std::cout<<"Enter the address to be updated :";
        std::cin>>address;
        address = capitalize_first_letter(address);        
        while(wks.cell("A" + std::to_string(Local_cell_counter)).value()!=name)
        {
            Local_cell_counter++;
        }
        wks.cell("B" + std::to_string(Local_cell_counter))=num;
        wks.cell("C" + std::to_string(Local_cell_counter))=address;
        std::cout<<name<<"is updated sucessfully"<<std::endl;
        }
        
    }
    void Address_book::Search()
    {
        int Local_cell_counter = 1 ;
        int last_cell_num ;
        std::cout<<"Enter the name to search for :";
        std::cin>>name;
        name = capitalize_first_letter(name);
        while((wks.cell("A" + std::to_string(Local_cell_counter)).value()!=name)&&(Local_cell_counter<get_empty_index()))
        {
            Local_cell_counter++;
        }
        if (Local_cell_counter == get_empty_index())
        {
            std::cout<<"The Name not found!!, Try again"<<std::endl;
        }
        else
        {
            std::cout<<"The name is found"<<std::endl;
            std::cout<<wks.cell("A" + std::to_string(Local_cell_counter))<<" | "<< wks.cell("B" + std::to_string(Local_cell_counter))<<" | "<< wks.cell("C" + std::to_string(Local_cell_counter))<<std::endl;
        }
    }
    std::string Address_book::capitalize_first_letter(std::string name)
    {
        name[0] = std::toupper(name[0]);

        for(size_t i = 1 ; i < name.length() ; i++ )
        {
            name[i] =std::tolower(name[i]);
        }


        return name;
    }
    void Address_book::Delete()
    {
        int Local_cell_counter =1;
        std::cout<<"Enter the name to be deleted :";
        std::cin >> name;
        name = capitalize_first_letter(name);
        while((wks.cell("A" + std::to_string(Local_cell_counter)).value()!=name)&&(Local_cell_counter<get_empty_index()))
        {
            Local_cell_counter++;
        }
        if (Local_cell_counter == get_empty_index())
        {
            std::cout<<"The Name not found!!, Try again"<<std::endl;
        }
        else
        {                  
           for(int i = Local_cell_counter ; i < Global_cell_counter ; i++ )
           {
            clearAndshift_rows_up(i);
           }

           std::cout<<name<<" is deleted successfully"<<std::endl;
        }
        
    }
    void Address_book::clearAndshift_rows_up(int deleted_row_num)
    {
        
        wks.cell("A"+std::to_string(deleted_row_num)).clear(1);
        wks.cell("B"+std::to_string(deleted_row_num)).clear(1);
        wks.cell("C"+std::to_string(deleted_row_num)).clear(1);

        wks.cell("A"+std::to_string(deleted_row_num)) = wks.cell("A"+std::to_string(deleted_row_num+1));
        wks.cell("B"+std::to_string(deleted_row_num)) = wks.cell("B"+std::to_string(deleted_row_num+1));
        wks.cell("C"+std::to_string(deleted_row_num)) = wks.cell("C"+std::to_string(deleted_row_num+1));

        wks.cell("A"+std::to_string(deleted_row_num+1)).clear(1);
        wks.cell("B"+std::to_string(deleted_row_num+1)).clear(1);
        wks.cell("C"+std::to_string(deleted_row_num+1)).clear(1);

    }
    void Address_book::Delete_all()
    {
        for (int i = 1 ; i < get_empty_index() ; i++)
        {
            wks.cell("A"+std::to_string(i)).clear(1);
            wks.cell("B"+std::to_string(i)).clear(1);
            wks.cell("C"+std::to_string(i)).clear(1);
        }
    }