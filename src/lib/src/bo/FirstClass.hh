#pragma once

#include <nael_utils/model/model_desc.hh>

namespace bo
{

class FirstClass
{

public:
    FirstClass(std::string const &id, unsigned value);

//Basic attributes
    MAKE_CLASS_ATT(
        ( ( std::string)(id) ),
        ( ( unsigned)(value)(0) )
    )
};

}
