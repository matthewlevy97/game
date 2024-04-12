# Define IMGUI Settings
function (ADD_IMGUI target)

    set(IMGUI_DIR "${CMAKE_SOURCE_DIR}/deps/imgui")

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

    find_package(SDL2 REQUIRED)

    target_include_directories(${target}
        PRIVATE
            ${IMGUI_DIR}
            ${IMGUI_DIR}/backends

            ${SDL2_INCLUDE_DIRS}
    )

    target_link_libraries(${target}
        PRIVATE
            ${SDL2_LIBRARIES}
    )

endfunction()