cmake_minimum_required(VERSION 3.20)

project(GameEngine)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(
	glm
	GIT_REPOSITORY	https://github.com/g-truc/glm.git
)
FetchContent_MakeAvailable(glm)

FetchContent_Declare(gflags
	GIT_REPOSITORY	https://github.com/gflags/gflags.git
)
FetchContent_GetProperties(gflags)

FetchContent_Declare(
	glog
	GIT_REPOSITORY	https://github.com/google/glog.git
)
FetchContent_MakeAvailable(glog)

add_subdirectory(deps)
add_subdirectory(engine)