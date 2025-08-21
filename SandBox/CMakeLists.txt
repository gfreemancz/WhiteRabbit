cmake_minimum_required(VERSION 3.30)
 
project(WhiteRabbitSandbox)

# set(PROJECT_NAME ProjectTemplateOGL)
set(PROJECT_DIR_SOURCE "src")
set(PROJECT_DIR_OPUTPUT "build")

set(COMPILER_DLL_PATH "c:/Development/mingw64/bin")


set(PROJECT_ROOT_DIR "C:/Development/Projects_root/WhiteRabbit")
set(PROJECT_EXT_LIBS_DIR "${PROJECT_ROOT_DIR}/Used_Libraries")

set(PROJECT_DIR "${PROJECT_ROOT_DIR}/SandBox")

set(EXTERNAL_LIBS)
set(EXTERNAL_LIBS_HEADER_PATHS)
set(INTERNAL_LIBS)

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")


list(APPEND EXTERNAL_LIBS_HEADER_PATHS "${CMAKE_CURRENT_LIST_DIR}/include_libs")


#for vs code nad ms c/c++ extension
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# externale libraries section BEGIN

# SDL2 library BEGIN
list(APPEND EXTERNAL_LIBS_HEADER_PATHS "${PROJECT_EXT_LIBS_DIR}/SDL2/include")

find_library(SDL2_MAIN_LIBRARY
    NAMES SDL2main    
    HINTS ${PROJECT_EXT_LIBS_DIR}/SDL2/lib
)

find_library(SDL2_LIBRARY
    NAMES SDL2 
    HINTS ${PROJECT_EXT_LIBS_DIR}/SDL2/lib
)

list(APPEND EXTERNAL_LIBS "${SDL2_MAIN_LIBRARY}")
list(APPEND EXTERNAL_LIBS "${SDL2_LIBRARY}")
install(FILES "${PROJECT_EXT_LIBS_DIR}/SDL2/bin/SDL2.dll" DESTINATION ${CMAKE_BINARY_DIR}/bin)
# SDL2 library END


# externale libraries section END

 



# add_subdirectory("src/Logger")
add_subdirectory("${PROJECT_ROOT_DIR}/Logger" ${PROJECT_DIR_OPUTPUT})


add_subdirectory("${PROJECT_DIR_SOURCE}")




set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_DIR_OPUTPUT}")


set(CMAKE_BINARY_DIR "${CMAKE_SOURCE_DIR}/build")


add_executable(${PROJECT_NAME})
target_link_libraries (${PROJECT_NAME} PRIVATE Project_main)

target_link_libraries(${PROJECT_NAME} PRIVATE MyLogger)

add_dependencies(${PROJECT_NAME} MyLogger)

get_target_property(testvar MyLogger OUTPUT_NAME)
message(STATUS "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx")
message(STATUS "${testvar}")
message(STATUS "${INTERNAL_LIBS}")
message(STATUS "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx")



target_include_directories(${PROJECT_NAME} PUBLIC  ${EXTERNAL_LIBS_HEADER_PATHS})

# target_link_libraries(${PROJECT_NAME} PRIVATE ${INTERNAL_LIBS})

target_link_libraries(${PROJECT_NAME} PRIVATE ${EXTERNAL_LIBS})


add_definitions(-DSDL_MAIN_HANDLED)


set_target_properties(${PROJECT_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "arch"
    LIBRARY_OUTPUT_DIRECTORY "lib"
    RUNTIME_OUTPUT_DIRECTORY "bin"
)



# install(TARGETS MyLogger RUNTIME DESTINATION ${CMAKE_BINARY_DIR}/bin)
# install(TARGETS MyLogger RUNTIME DESTINATION ${CMAKE_BINARY_DIR}/bin)

install(FILES "${COMPILER_DLL_PATH}/libstdc++-6.dll" DESTINATION ${CMAKE_BINARY_DIR}/bin)
install(FILES "${COMPILER_DLL_PATH}/libwinpthread-1.dll" DESTINATION ${CMAKE_BINARY_DIR}/bin)
install(FILES "${COMPILER_DLL_PATH}/libgcc_s_seh-1.dll" DESTINATION ${CMAKE_BINARY_DIR}/bin)

# install(TARGETS ${PROJECT_NAME} DESTINATION bin)

add_custom_command( 
    OUTPUT Run.bat    
    COMMAND ${CMAKE_COMMAND} -E echo "@set PATH=${MY_DLL_PATH};%PATH%" > ../Run.bat
    COMMAND ${CMAKE_COMMAND} -E echo "build\\bin\\${PROJECT_NAME}.exe" >> ../Run.bat
)

add_custom_command( 
    OUTPUT OpenVsCode.bat    
    COMMAND ${CMAKE_COMMAND} -E echo "@set GCC_BIN_DIRECTORY=${GCC_BIN_DIRECTORY}" > ../OpenVsCode.bat
    COMMAND ${CMAKE_COMMAND} -E echo "@set MY_DLL_PATH=${MY_DLL_PATH}" >> ../OpenVsCode.bat
    COMMAND ${CMAKE_COMMAND} -E echo "code --new-window ${PROJECT_NAME}.code-workspace" >> ../OpenVsCode.bat
)

add_custom_target(
  Run_Bat
  ALL
  DEPENDS Run.bat
  COMMENT "Create Run.bat to open the project in VS Code"
)

add_custom_target(
  make_vscode
  DEPENDS OpenVsCode.bat
  COMMENT "Create OpenVsCode.bat to open the project in VS Code"
)

