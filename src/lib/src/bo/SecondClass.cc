#include "SecondClass.hh"

namespace bo
{

SecondClass::SecondClass(std::string const &id, double value, FirstClass &first)
    : _id(id)
    , _value(value)
    , _first(first)
    , _const_first(first)
{}

}