add_executable(${PROJECT_NAME})
set(SOURCES
    main.cpp
    core/window_manager.cpp
    core/event_manager.cpp
    core/database_manager.cpp
    models/customer.cpp
    models/invoice.cpp
    models/invoice_item.cpp
)
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

find_package(SQLite3 REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE external SQLite::SQLite3)