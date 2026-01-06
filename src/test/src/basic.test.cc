#include <gtest/gtest.h>
#include <bo/BoIn.hh>
#include <dto/DtoIn.hh>
#include <dto_handler/dto_handler.hh>

TEST(dto_to_bo, test_conversion)
{
    bo::BoContext bo_context;
    dto::DtoContext dto_context;
    ASSERT_NO_THROW(dto_handler::dto_to_bo(dto_context, bo_context));
}

