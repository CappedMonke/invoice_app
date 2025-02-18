
add_library(external INTERFACE)

target_include_directories(external INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/clay)

add_subdirectory(glm)
target_link_libraries(external INTERFACE glm::glm)

add_subdirectory(SDL)
target_link_libraries(external INTERFACE SDL3::SDL3)

add_subdirectory(SDL_image)
target_link_libraries(external INTERFACE SDL3_image::SDL3_image)

add_subdirectory(SDL_ttf)
target_link_libraries(external INTERFACE SDL3_ttf::SDL3_ttf)