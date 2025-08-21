

add_library(MyLogger SHARED)

target_sources(MyLogger PRIVATE myLogger.cpp myLogger.hpp myLogger_ifx.hpp )

target_include_directories(MyLogger PUBLIC  ${CMAKE_CURRENT_LIST_DIR})
target_include_directories(MyLogger PRIVATE  ${CMAKE_CURRENT_LIST_DIR}/SpdLog)

# set_target_properties(MyLogger PROPERTIES OUTPUT_NAME "test01")

set_target_properties(MyLogger PROPERTIES LIBRARY_OUTPUT_NAME MyLogger)
set_target_properties(MyLogger PROPERTIES OUTPUT_NAME         MyLogger)

target_compile_definitions(MyLogger PRIVATE MYLIBRARY_EXPORTS)


install(TARGETS MyLogger RUNTIME DESTINATION ${CMAKE_BINARY_DIR}/bin)
install(TARGETS MyLogger ARCHIVE DESTINATION ${CMAKE_BINARY_DIR}/arch)
install(FILES myLogger_ifx.hpp DESTINATION ${PROJECT_DIR}/include_libs)
link_directories(${CMAKE_BINARY_DIR}/arch)

get_target_property(testvar MyLogger OUTPUT_NAME)

# message(STATUS "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx")
# message(STATUS "${testvar}")
# message(STATUS "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx")

# list(APPEND EXTERNAL_LIBS_HEADER_PATHS "${CMAKE_CURRENT_LIST_DIR}")
# list(APPEND EXTERNAL_LIBS_HEADER_PATHS "${CMAKE_CURRENT_LIST_DIR}/SpdLog")
list(APPEND INTERNAL_LIBS "MyLogger")



# set(EXTERNAL_LIBS_HEADER_PATHS "${EXTERNAL_LIBS_HEADER_PATHS}" PARENT_SCOPE)
set(INTERNAL_LIBS "${INTERNAL_LIBS}" PARENT_SCOPE)
