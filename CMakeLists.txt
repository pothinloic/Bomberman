cmake_minimum_required(VERSION 3.0)

cmake_policy(SET CMP0054 NEW)

project(bomberman)

set(SRCS
  src/main.cpp
  src/Menu.cpp
  src/Button.cpp
  )

set(HEADERS
  include/Menu.hpp
  include/Button.hpp
  )

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC") #SI IL S'AGIT D'UN SYSTEME WINDOWS
	find_path(IRRLICHT_INCLUDE_DIR irrlicht.h)
	find_library(IRRLICHT_LIBRARY Irrlicht.lib)

	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

	if (IRRLICHT_INCLUDE_DIR AND IRRLICHT_LIBRARY) #SI LA LIB IRRLICHT A ETE TROUVER
		include_directories(${IRRLICHT_INCLUDE_DIR})
		link_directories (${IRRLICHT_INCLUDE_DIR})
		set(YOUR_LIBRARIES ${IRRLICHT_LIBRARY})
	elseif (NOT IRRLICHT_INCLUDE_DIR AND NOT IRRLICHT_LIBRARY) #SI LA LIB IRRLICHT N'A PAS ETE TROUVER
		##	ATTENTION
		##	Modifiez ici le chemin vers les fichiers de votre librairie Irrlicht
		##	ATTENTION
		set(HEADER_PATH "D:/EPITECH/irrlicht/include/")	#Path du dossier "/include/" contenant le fichier "irrlicht.h"
		set(LIB_PATH "D:/EPITECH/irrlicht/lib/Win32/Irrlicht.lib") #Path du fichier "Irrlicht.lib" compatible
		set(DLL_PATH "D:/EPITECH/irrlicht/bin/Win32/Irrlicht.dll")	#Path du fichier "Irrlicht.dll" compatible
		include_directories(${HEADER_PATH})
		link_directories(${HEADER_PATH})
	endif()

	configure_file(${DLL_PATH} "./build/Debug/Irrlicht.dll" COPYONLY)
	set(IRRLICHT_INCLUDE_DIR ${HEADER_PATH} CACHE PATH "Path to the header file" FORCE)
	set(IRRLICHT_LIBRARY ${LIB_PATH} CACHE PATH "Path to the lib file" FORCE)
	set(YOUR_LIBRARIES ${LIB_PATH})

elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")	#SI IL S'AGIT D'UN SYSTEME UNIX
	target_compile_options(bomberman PUBLIC -std=gnu++11 -Wall -Wextra)
endif()

add_executable(bomberman ${SRCS} ${HEADERS})
target_link_libraries(bomberman ${YOUR_LIBRARIES})
