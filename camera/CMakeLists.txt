cmake_minimum_required(VERSION 3.2)

project(camera)
find_package(Qt5 REQUIRED COMPONENTS Core Widgets Gui Multimedia)
find_package(OpenCV REQUIRED)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

include_directories(${OpenCV_INCLUDE_DIRS})


set(src_dir src inc ui)
message(STATUS ${src_dir})
foreach(dir ${src_dir})
	string(TOUPPER "${dir}" dir_u)
	file(GLOB ${dir_u}_UI_FILES     ${dir}/*.ui)
	file(GLOB ${dir_u}_H_FILES      ${dir}/*.h)
	file(GLOB ${dir_u}_CXX_FILES    ${dir}/*.cpp)
	list(APPEND UIS         ${${dir_u}_UI_FILES})
	list(APPEND SRCS        ${${dir_u}_H_FILES})
	list(APPEND HEADERS     ${${dir_u}_CXX_FILES})
endforeach(dir ${src_dir})

message(STATUS ${HEADERS})
message(STATUS ${SRCS})

qt5_wrap_ui(FORM_H ${UIS})

add_executable(${PROJECT_NAME} ${HEADERS} ${SRCS} ${FORM_H})

target_link_libraries(${PROJECT_NAME}
	PUBLIC
	Qt5::Core
	Qt5::Gui
	Qt5::Widgets
	Qt5::Multimedia
	${OpenCV_LIBS}
)
