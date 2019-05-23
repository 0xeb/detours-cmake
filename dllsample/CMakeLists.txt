cmake_minimum_required(VERSION 3.8)

# The hook library
project(dllsample)

add_library(dllsample SHARED dllsample.cpp)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
target_link_libraries(dllsample PRIVATE lib_detours)
set_target_properties(dllsample PROPERTIES LINK_FLAGS /EXPORT:DetourFinishHelperProcess,@1,NONAME)

# Dummy executable
project(dummy)
add_executable(dummy dummy.cpp)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")

# With dll that runs the dummy executable with the dllsample (hook) injected
project(withdll)
add_executable(withdll withdll.cpp)
target_link_libraries(withdll lib_detours)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")