add_executable(${PROJECT_NAME})

set(SOURCES
    main.cpp
    gui/window_manager.cpp
    gui/window.cpp
)
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE external)