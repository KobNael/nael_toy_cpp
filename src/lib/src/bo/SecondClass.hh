#pragma once

#include <nael_utils/model/model_desc.hh>

#include "FirstClass.hh"

namespace bo
{

class SecondClass
{
public:
    SecondClass(std::string const &id, double value, FirstClass &first);

private:
    SecondClass();
//Basic attributes
    MAKE_CLASS_ATT(
        ( (std::string)(id) ),
        ( (double)(value)(0.) )
    )
    MAKE_CLASS_REF_ATT(FirstClass, first)
    MAKE_CLASS_CONSTREF_ATT(FirstClass, const_first)
};

}
