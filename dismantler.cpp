#include "dismantler.h"
#include "d_exc.h"

void dismatler::dism( uint64_t inp ) {
    data.clear();
    uint64_t i = 2;
    uint64_t count_ = 0;
    while ( i <= inp ) {
        if ( inp % i == 0 ) {
            count_++;
            inp /= i;
        } else {
            data [ i ] = count_;
            i++;
            count_ = 0;
        }
    }
    data [ i ] = count_;
}

void dismatler::generate_str() {
    str_print.clear();
    if ( data.empty() ) {
        throw Data_Error( "Data is empty" );
    }
    for ( const auto & it : data ) {
        if ( it.second != 0 ) {
            str_print += " * ";
            str_print += patch::to_string( it.first );
            if ( it.second != 1) {
                str_print += "^";
                str_print += patch::to_string( it.second );
            }
        }
    }
    str_print.erase(0,3);
}

void dismatler::d_print() {
    generate_str();
    std::cout << str_print << std::endl;
}

void dismatler::un_dism() {
    if ( data.empty() ) {
        throw Data_Error( "Data is empty" );
    }
    return_ = 1;
    for ( const auto & it : data ) {
        if ( it.second != 0 ) {
            for ( uint64_t i = 0; i < it.second; i++ ) {
                return_ *= it.first;
            }
        }
    }
}

void dismatler::un_print() {
    std::cout << return_ << std::endl;
}

void dismatler::get_files_name() {
    std::cin >> file_name >> file_name_o;
}

void dismatler::init_file() {
    get_files_name();
    std::string str;
    std::ifstream file;
    file.open( file_name, std::ifstream::in );
    if ( !file.is_open()) {
        file.close();
        throw Io_Error( "File is not opened" );
    }
    std::ofstream fout;
    fout.open( file_name_o, std::ofstream::app );
    while( file.good() ) {
        std::getline( file, str );
        if ( str != "" ) {
        std::istringstream stream ( str );
        stream >> inp;
        dism( inp );
        generate_str();
        fout << str_print << std::endl;
        }
    }
    file.close();
    fout.close();
}
