
add_library(external INTERFACE)

add_subdirectory(SDL)
target_link_libraries(external INTERFACE SDL3::SDL3)

add_subdirectory(glm)
target_link_libraries(external INTERFACE glm::glm)