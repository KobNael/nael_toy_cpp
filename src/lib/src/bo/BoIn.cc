#include "BoIn.hh"

namespace bo
{

FirstClass &BoContext::addFirstClass(std::string const &id, unsigned value)
{
    auto [iter, inserted] = _firsts.try_emplace( id, FirstClass(id, value));
    if(!inserted)
    {
        throw std::logic_error("An item with the same id already exists");
    }
    return iter->second;
}
SecondClass &BoContext::addSecondClass(std::string const &id, std::string const &first_id, double value)
{
    auto first = _firsts.find(first_id);
    if(first == _firsts.end())
    {
        throw std::logic_error("Unknown first item " + first_id);
    }
    auto [iter, inserted] = _seconds.try_emplace(id, SecondClass(id, value, first->second));
    if(!inserted)
    {
        throw std::logic_error("An item with the same id already exists");
    }
    return iter->second;
}

}