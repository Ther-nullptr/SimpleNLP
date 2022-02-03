cmake_minimum_required(VERSION 3.5)

project(simple_nlp)

add_library(simple_nlp STATIC
    src/simple_nlp.cpp
)

target_include_directories(simple_nlp
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/tclap/include
)

add_executable(nlp_tool
    src/main.cpp
)

target_link_libraries( nlp_tool
    PRIVATE 
    simple_nlp
)

install (TARGETS nlp_tool
    DESTINATION bin)

install (TARGETS simple_nlp
    LIBRARY DESTINATION lib)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ 
    DESTINATION include)