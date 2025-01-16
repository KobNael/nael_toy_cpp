#include "dto_handler.hh"

namespace bpt = boost::posix_time;
namespace
{

    void parse_first(dto::DtoContext const& dto_context , bo::BoContext &bo_context)
    {
        //Create Press
        for(dto::FirstClassDto const &first : dto_context.first_collec)
        {
            bo_context.addFirstClass(first.id, first.value);
        }
    }

    void parse_second(dto::DtoContext const& dto_context , bo::BoContext &bo_context)
    {
        //Create Second Class elements
        for(dto::SecondClassDto const &second : dto_context.second_collec)
        {
            bo_context.addSecondClass(second.id, second.first_id, second.value);
        }
    }
}

namespace dto_handler
{

    void dto_to_bo(dto::DtoContext const& dto_context , bo::BoContext &bo_context)
    {
        parse_first(dto_context, bo_context);
        parse_second(dto_context, bo_context);
    }

}
