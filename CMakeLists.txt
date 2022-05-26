cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set the project name
project(CGFromScratch VERSION 0.1)

IF(WIN32)
add_library(SDL STATIC IMPORTED)
set_property(TARGET SDL PROPERTY 
	IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/SDL-1.2.15/lib64/libSDL.dll")
ENDIF()

# add the executable
add_executable(CGFromScratch main.cpp video_manager.cpp)
target_include_directories(CGFromScratch PUBLIC
			   "include"
			   IF(WIN32)
			     "SDL-1.2.15/include"
		           ENDIF()
			   )
target_link_libraries(CGFromScratch PUBLIC
	              SDL
		      )
