
add_executable(engine
    src/engine.cpp
    src/main.cpp
)
target_include_directories(engine
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include/
)

add_subdirectory(src/core)
add_subdirectory(src/graphics)

ADD_DEPS(engine)
target_link_libraries(engine
    PRIVATE
        glog::glog
)

install(TARGETS
    engine
)