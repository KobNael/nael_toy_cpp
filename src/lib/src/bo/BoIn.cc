#include "BoIn.hh"

namespace bo
{

FirstClass &BoContext::addFirstClass(std::string const &id, unsigned value)
{
    if(_firsts.find(id) != _firsts.end())
    {
        throw std::logic_error("An item with the same id already exists");
    }
    auto new_elem = _firsts.insert(
        std::make_pair(
            id, FirstClass(id, value)
        ));
    return new_elem.first->second;
}
SecondClass &BoContext::addSecondClass(std::string const &id, std::string const &first_id, double value)
{
    if(_seconds.find(id) != _seconds.end())
    {
        throw std::logic_error("An item with the same id already exists");
    }
    auto first = _firsts.find(first_id);
    if(first == _firsts.end())
    {
        throw std::logic_error("Unknown first item " + first_id);
    }
    auto new_elem = _seconds.insert(
        std::make_pair(
            id, SecondClass(id, value, first->second)
        ));
    return new_elem.first->second;
}

}