add_executable(simple simple.cpp)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")

target_link_libraries(simple PRIVATE lib_detours)