#pragma once

#include <nael_utils/model/model_desc.hh>

#include "FirstClass.hh"
#include "SecondClass.hh"

namespace bo
{

class BoContext
{
public:
    virtual ~BoContext() = default;

    FirstClass &addFirstClass(std::string const &id, unsigned value);
    SecondClass &addSecondClass(std::string const &id, std::string const &first_id, double value);

//Attributes
    MAKE_UNORDERED_MAP(std::string, FirstClass, firsts)
    MAKE_MAP(std::string, SecondClass, seconds)
};


}