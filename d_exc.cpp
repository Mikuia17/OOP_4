#include "d_exc.h"

d_exc::d_exc( const std::string &message ) noexcept : message( message ) {}
d_exc::~d_exc() noexcept {}
const char* d_exc::what() const noexcept {
    return message.c_str();
}
Data_Error::Data_Error( const std::string &message ) noexcept : d_exc( message ) {}
Io_Error::Io_Error( const std::string &message ) noexcept : d_exc( message ) {}
