#ifndef D_EXC_H_INCLUDED
#define D_EXC_H_INCLUDED

#include <exception>
#include <stdexcept>

class d_exc : public std::exception {
public:
    d_exc( const std::string &message ) noexcept ;
    ~d_exc () noexcept ;
    const char* what() const noexcept override;
private:
    std::string message ;
};

class Data_Error : public d_exc {
public:
    Data_Error( const std::string &message ) noexcept ;
};
class Io_Error : public d_exc {
public:
    Io_Error( const std::string &message ) noexcept ;
};

#endif // D_EXC_H_INCLUDED
