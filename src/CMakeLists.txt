add_executable(${PROJECT_NAME})

set(SOURCES
    main.cpp
    core/window_manager.cpp
    core/event_manager.cpp
)
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE external)