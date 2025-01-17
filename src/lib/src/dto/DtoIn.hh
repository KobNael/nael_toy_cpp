#pragma once

#include <boost/date_time/posix_time/posix_time_duration.hpp>
#include <boost/date_time/gregorian/gregorian_types.hpp>

#include <nael_utils/model/model_desc.hh>

namespace dto
{

MAKE_DTO_STRUCT(
    FirstClassDto,
    ((std::string)(id)) // identifier
    ((unsigned)(value)) // identifier
)

MAKE_DTO_STRUCT(
    SecondClassDto,
    ((std::string)(id)) // identifier
    ((std::string)(first_id)) // identifier
    ((double)(value)) // identifier
)

//Full context
MAKE_DTO_STRUCT(
    DtoContext,
    ((std::vector<FirstClassDto>)(first_collec))
    ((std::vector<SecondClassDto>)(second_collec))
)

}
