cmake_minimum_required(VERSION 3.31)

project(invoice_app LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(external INTERFACE)

target_include_directories(external INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/clay)

find_package(SQLite3 REQUIRED)
target_link_libraries(external INTERFACE SQLite::SQLite3)

add_subdirectory(external/glm)
target_link_libraries(external INTERFACE glm::glm)

add_subdirectory(external/SDL)
target_link_libraries(external INTERFACE SDL3::SDL3)

add_subdirectory(external/SDL_image)
target_link_libraries(external INTERFACE SDL3_image::SDL3_image)

add_subdirectory(external/SDL_ttf)
target_link_libraries(external INTERFACE SDL3_ttf::SDL3_ttf)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
add_executable(${PROJECT_NAME})

set(SOURCES
    src/gui/window.cpp
    src/main.cpp
    src/managers/database_manager.cpp
    src/managers/window_manager.cpp
    src/models/customer.cpp
    src/models/invoice.cpp
    src/models/invoice_item.cpp
    src/utils/profiler.cpp
)

target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(${PROJECT_NAME} PRIVATE external)

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/assets
        ${CMAKE_CURRENT_BINARY_DIR}/assets
)