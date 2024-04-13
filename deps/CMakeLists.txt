set(BUILD_SHARED_LIBS ON CACHE BOOL "" FORCE)

# https://github.com/libsdl-org/SDL
set(SDL_LIBC ON CACHE BOOL "" FORCE)
set(SDL_TEST OFF CACHE BOOL "" FORCE)
add_subdirectory(SDL)

# Define IMGUI Settings
function (ADD_IMGUI target)

    set(IMGUI_DIR "${CMAKE_SOURCE_DIR}/deps/imgui")
    set(SDL_DIR "${CMAKE_SOURCE_DIR}/deps/SDL")

    target_sources(${target}
        PRIVATE
            ${IMGUI_DIR}/imgui.cpp
            ${IMGUI_DIR}/imgui_demo.cpp
            ${IMGUI_DIR}/imgui_draw.cpp
            ${IMGUI_DIR}/imgui_tables.cpp
            ${IMGUI_DIR}/imgui_widgets.cpp

            ${IMGUI_DIR}/backends/imgui_impl_sdl2.cpp
            ${IMGUI_DIR}/backends/imgui_impl_sdlrenderer2.cpp
    )

    target_include_directories(${target}
        PRIVATE
            ${IMGUI_DIR}
            ${IMGUI_DIR}/backends

            ${SDL_DIR}/include
    )

    target_link_libraries(${target}
        PRIVATE
            SDL2::SDL2
            SDL2::SDL2main
    )

endfunction()