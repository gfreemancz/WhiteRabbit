

add_library(Project_main OBJECT)


target_sources(Project_main PRIVATE 
                main.cpp
                wrWindow.cpp 
                wrWindow.hpp 
                )


target_include_directories(Project_main PUBLIC  ${CMAKE_CURRENT_LIST_DIR}/Logger)
target_include_directories(Project_main PUBLIC  ${CMAKE_CURRENT_LIST_DIR})
target_include_directories(Project_main PUBLIC  ${EXTERNAL_LIBS_HEADER_PATHS})




set(EXTERNAL_LIBS_HEADER_PATHS "${EXTERNAL_LIBS_HEADER_PATHS}" PARENT_SCOPE)
