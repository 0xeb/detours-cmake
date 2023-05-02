# Detours
set(TARGET lib_detours)
set(DETOURS_SOURCE Detours/src)

add_library(${TARGET} STATIC
    ${DETOURS_SOURCE}/creatwth.cpp
    ${DETOURS_SOURCE}/detours.cpp
    ${DETOURS_SOURCE}/detours.h
    ${DETOURS_SOURCE}/detver.h
    ${DETOURS_SOURCE}/disasm.cpp
    ${DETOURS_SOURCE}/disolarm.cpp
    ${DETOURS_SOURCE}/disolarm64.cpp
    ${DETOURS_SOURCE}/disolia64.cpp
    ${DETOURS_SOURCE}/disolx64.cpp
    ${DETOURS_SOURCE}/disolx86.cpp
    ${DETOURS_SOURCE}/image.cpp
    ${DETOURS_SOURCE}/modules.cpp
    ${DETOURS_SOURCE}/uimports.cpp)

# This file is included and not compiled on its own
set_property (
    SOURCE ${DETOURS_SOURCE}/uimports.cpp
    APPEND PROPERTY HEADER_FILE_ONLY true)

target_compile_options(${TARGET} PRIVATE /W4 /WX /Zi /MT /Gy /Gm- /Zl /Od)
target_include_directories(${TARGET} PUBLIC ${DETOURS_SOURCE})

# withdll
add_executable(withdll Detours/samples/withdll/withdll.cpp)
target_link_libraries(withdll lib_detours)

# Static library for the syelog components
add_library(syelog STATIC Detours/samples/syelog/syelog.cpp
                          Detours/samples/syelog/syelog.h)
target_include_directories(syelog PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Detours/samples/syelog)
target_link_libraries(syelog PUBLIC lib_detours ws2_32 secur32)


# syelogd
add_executable(syelogd Detours/samples/syelog/syelogd.cpp 
                       Detours/samples/syelog/syelog.h)
target_link_libraries(syelogd PRIVATE lib_detours)

# traceapi example
add_library(traceapi SHARED Detours/samples/traceapi/trcapi.cpp 
                            Detours/samples/traceapi/trcapi.rc)
target_link_libraries(traceapi PRIVATE syelog)
set_target_properties(traceapi PROPERTIES LINK_FLAGS /EXPORT:DetourFinishHelperProcess,@1,NONAME)

# tracessl example
add_library(tracessl SHARED Detours/samples/tracessl/trcssl.cpp Detours/samples/tracessl/trcssl.rc)
target_link_libraries(tracessl PRIVATE syelog)
set_target_properties(tracessl PROPERTIES LINK_FLAGS /EXPORT:DetourFinishHelperProcess,@1,NONAME)