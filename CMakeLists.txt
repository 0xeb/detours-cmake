cmake_minimum_required(VERSION 3.8)

project(DetoursCMake)

add_subdirectory(3rdparty)
add_subdirectory(simple)
add_subdirectory(dllsample)

# On Windows and for release builds, statically link
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")

# Set the destination folder for all binaries in bin/configuration/*
foreach(cfg IN LISTS CMAKE_CONFIGURATION_TYPES)
    string(TOUPPER ${cfg} cfg)
	foreach (trgt simple dllsample dummy withdll)
		set_target_properties(${trgt} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_${cfg} ${CMAKE_CURRENT_BINARY_DIR}/bin/${cfg})
	endforeach()
endforeach()
