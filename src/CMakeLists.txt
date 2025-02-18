add_executable(${PROJECT_NAME})

set(SOURCES
    gui/window.cpp
    main.cpp
    managers/database_manager.cpp
    managers/window_manager.cpp
    models/customer.cpp
    models/invoice.cpp
    models/invoice_item.cpp
    utils/profiler.cpp
)

target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

find_package(SQLite3 REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE external SQLite::SQLite3)