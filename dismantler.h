#ifndef DISMANTLER_H_INCLUDED
#define DISMANTLER_H_INCLUDED

#include<map>
#include<iostream>
#include<fstream>
#include<sstream>

class dismatler {
public:
    void dism( uint64_t );
    void un_dism();
    void d_print();
    void un_print();
    void get_files_name();
    void init_file();
    void generate_str();
private:
    std::map< uint64_t, uint64_t > data;
    uint64_t return_;
    std::string file_name;
    std::string file_name_o;
    uint64_t inp;
    std::string str_print;
};

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

#endif // DISMANTLER_H_INCLUDED
