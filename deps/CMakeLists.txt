set(BUILD_SHARED_LIBS ON CACHE BOOL "" FORCE)

# https://github.com/libsdl-org/SDL
set(SDL_LIBC ON CACHE BOOL "" FORCE)
set(SDL_TEST OFF CACHE BOOL "" FORCE)
add_subdirectory(SDL)

# https://github.com/libsdl-org/SDL_image/tree/SDL2
set(SDL2IMAGE_AVIF  OFF)
set(SDL2IMAGE_BMP ON)
set(SDL2IMAGE_GIF OFF)
set(SDL2IMAGE_JPG  ON)
set(SDL2IMAGE_JXL OFF)
set(SDL2IMAGE_LBM OFF)
set(SDL2IMAGE_PCX OFF)
set(SDL2IMAGE_PNG ON)
set(SDL2IMAGE_PNM OFF)
set(SDL2IMAGE_QOI OFF)
set(SDL2IMAGE_SVG OFF)
set(SDL2IMAGE_TGA OFF)
set(SDL2IMAGE_TIF  OFF)
set(SDL2IMAGE_WEBP  OFF)
set(SDL2IMAGE_XCF OFF)
set(SDL2IMAGE_XPM OFF)
set(SDL2IMAGE_XV OFF)
add_subdirectory(SDL_Image)

add_subdirectory(entt)

install(TARGETS
    SDL2
    SDL2_image
)

function (ADD_DEPS target)

    set(IMGUI_DIR "${CMAKE_SOURCE_DIR}/deps/imgui")
    set(SDL_DIR "${CMAKE_SOURCE_DIR}/deps/SDL")
    set(SDL_IMAGE_DIR "${CMAKE_SOURCE_DIR}/deps/SDL_Image")
    set(ENT_DIR "${CMAKE_SOURCE_DIR}/deps/entt")

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
            ${SDL_IMAGE_DIR}/include

            ${ENT_DIR}/single_include
    )

    target_link_libraries(${target}
        PRIVATE
            SDL2::SDL2
            SDL2::SDL2main

            SDL2_image::SDL2_image

            EnTT::EnTT
    )

endfunction()