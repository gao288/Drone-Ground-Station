cmake_minimum_required(VERSION 3.2)

project(camera)
find_package(Qt5 REQUIRED COMPONENTS Core Widgets Gui)
find_package(OpenCV REQUIRED)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)


include_directories(${OpenCV_INCLUDE_DIRS})

set(project_ui
	camera.ui)

set(project_headers 
		camera.h
		VideoFaceDetector.h
		VideoThread.h

)
set(project_sources main.cpp
					camera.cpp
					VideoFaceDetector.cpp
					VideoThread.cpp
)



add_executable(${PROJECT_NAME} ${project_headers} ${project_sources})

target_link_libraries(${PROJECT_NAME}
	PUBLIC
	Qt5::Core
	Qt5::Gui
	Qt5::Widgets
	
	${OpenCV_LIBS}

)
