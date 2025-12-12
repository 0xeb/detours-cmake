# The hook library
add_library(dllsample SHARED dllsample.cpp)
target_link_libraries(dllsample PRIVATE lib_detours)
if(MSVC)
    set_target_properties(dllsample PROPERTIES LINK_FLAGS /EXPORT:DetourFinishHelperProcess,@1,NONAME)
else()
    set_target_properties(dllsample PROPERTIES PREFIX "" SUFFIX ".dll")
    target_link_options(dllsample PRIVATE "-Wl,--export-all-symbols")
endif()

# Dummy executable
add_executable(dummy dummy.cpp)

# With dll that runs the dummy executable with the dllsample (hook) injected
add_executable(runwithdll runwithdll.cpp)
target_link_libraries(runwithdll lib_detours)

# Cross-compile: ensure .exe suffix on non-Windows hosts
if(NOT MSVC)
    set_target_properties(dummy PROPERTIES SUFFIX ".exe")
    set_target_properties(runwithdll PROPERTIES SUFFIX ".exe")
endif()
