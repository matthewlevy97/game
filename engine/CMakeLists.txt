
add_executable(engine
    src/main.cpp
)
target_include_directories(engine
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include/
)

add_subdirectory(src/graphics)

ADD_IMGUI(engine)
target_link_libraries(engine
    PRIVATE
        glog::glog
)

install(TARGETS
    engine
    SDL2
)