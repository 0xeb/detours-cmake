add_executable(simple simple.cpp)

target_link_libraries(simple PRIVATE lib_detours)

# Cross-compile: ensure .exe suffix on non-Windows hosts
if(NOT MSVC)
    set_target_properties(simple PROPERTIES SUFFIX ".exe")
endif()