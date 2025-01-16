#pragma once
#include "dto/DtoIn.hh"
#include "bo/BoIn.hh"

namespace dto_handler
{

    /**
     * @brief Fill a bo context
     * @param dto_context the dto to read from
     * @param[out] bo_context to fill
     */
    void dto_to_bo(dto::DtoContext const& dto_context , bo::BoContext &bo_context);

}
