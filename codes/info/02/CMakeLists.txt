cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

set ( PRJ_COMPILE_FEATURES )
set ( PRJ_COMPILE_DEFINITIONS )
set ( PRJ_LIBRARIES )
set ( PRJ_INCLUDE_DIRS )

find_package ( OpenCL )

include(CMakePrintHelpers)

cmake_print_variables( OpenCL_FOUND )
cmake_print_variables( OpenCL_INCLUDE_DIRS )
cmake_print_variables( OpenCL_LIBRARIES )
cmake_print_variables( OpenCL_VERSION_STRING )
cmake_print_variables( OpenCL_VERSION_MAJOR )
cmake_print_variables( OpenCL_VERSION_MINOR )

cmake_print_variables( OpenCL_INCLUDE_DIR )
cmake_print_variables( OpenCL_LIBRARY )

list ( APPEND PRJ_INCLUDE_DIRS ${OpenCL_INCLUDE_DIRS} )
list ( APPEND PRJ_LIBRARIES OpenCL::OpenCL )

get_directory_property( my_system_targets DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} BUILDSYSTEM_TARGETS )
get_directory_property( my_import_targets DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} IMPORTED_TARGETS )

message( STATUS "my_system_targets=${my_system_targets}" )
message( STATUS "my_import_targets=${my_import_targets}" )

if ( MSVC )
    set_property( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME} )
endif()

add_executable ( ${PROJECT_NAME}
    main.cpp
)

target_include_directories ( ${PROJECT_NAME}
    PRIVATE
        ${PRJ_INCLUDE_DIRS}
)

target_link_libraries( ${PROJECT_NAME} 
    PRIVATE 
        ${PRJ_LIBRARIES}
)

target_compile_features ( ${PROJECT_NAME} 
    PRIVATE 
        ${PRJ_COMPILE_FEATURES}
)

target_compile_definitions ( ${PROJECT_NAME}
    PRIVATE
       ${PRJ_COMPILE_DEFINITIONS} 
)


