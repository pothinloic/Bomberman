cmake_minimum_required(VERSION 3.10)

cmake_policy(SET CMP0054 NEW)

project(bomberman)

##################################################################################
###### PATH TO CHANGE TO MAKE THE CMakeLists.txt COMPLIENT WITH YOUR SYSTEM ######
######                            ONLY FOR WINDOWS                          ######
######                 (For linux only if not found automaticaly)           ######
##################################################################################

set(SFML_PATH "C:/EPITECH/SFML-2.4.2") #Set here the path to your SFML library
set(IRRLICHT_PATH "C:/EPITECH/irrlicht") #Set here the path to your Irrlicht library

##################################################################################
###### PATH TO CHANGE TO MAKE THE CMakeLists.txt COMPLIENT WITH YOUR SYSTEM ######
######                            ONLY FOR WINDOWS                          ######
######                 (For linux only if not found automaticaly)           ######
##################################################################################

set(SRCS
  src/main.cpp
  src/Menu.cpp
  src/Button.cpp
  src/Cube.cpp
  src/Explode.cpp
  src/Image.cpp
  src/Key.cpp
  src/Sleep.cpp
  src/Device.cpp
  src/Map.cpp
  src/Tile.cpp
  src/Character.cpp
  src/Fire.cpp
  src/Bomb.cpp
  src/Device.cpp
  )

set(HEADERS
  include/ISolid.hpp
  include/Explode.hpp 
  include/IEntities.hpp
  include/Menu.hpp
  include/Button.hpp
  include/Cube.hpp
  include/Image.hpp
  include/Key.hpp
  include/Sleep.hpp
  include/Device.hpp
  include/Map.hpp
  include/Tile.hpp
  include/ISolid.hpp
  include/Character.hpp
  include/Fire.hpp
  include/Bomb.hpp
  include/Device.hpp
  )

IF (NOT Irrlicht_INCLUDE_DIRS OR NOT Irrlicht_LIBRARIES)
  FIND_PATH(Irrlicht_INCLUDE_DIRS
    NAMES
      irrlicht.h
    PATHS
      ${IRRLICHT_PATH}/include/     # Path set by the user at the begining of the CMakeLists.txt
      /usr/include/irrlicht/        # Default Fedora28 system include path
      /usr/local/include/irrlicht/  # Default Fedora28 local include path
      ${CMAKE_MODULE_PATH}/include/ # Expected to contain the path to this file for Windows10
      ${Irrlicht_DIR}/include/      # Irrlicht root directory (if provided)
  )

  IF (MSVC)     # Windows
    SET(CMAKE_FIND_LIBRARY_PREFIXES "")
    SET(CMAKE_FIND_LIBRARY_SUFFIXES ".lib")
  ELSE (MSVC)   # Linux
    SET(CMAKE_FIND_LIBRARY_PREFIXES "lib")
    SET(CMAKE_FIND_LIBRARY_SUFFIXES ".so")
  ENDIF(MSVC)

  FIND_LIBRARY(Irrlicht_LIBRARIES
    NAMES
      Irrlicht
    PATHS
      ${IRRLICHT_PATH}/             # Path set by the user at the begining of the CMakeLists.txt
      /usr/lib64/                   # Default Fedora28 library path
      /usr/lib/                     # Some more Linux library path
      /usr/lib/x86_64-linux-gnu/    # Some more Linux library path
      /usr/local/lib/               # Some more Linux library path
      /usr/local/lib64/             # Some more Linux library Path
      ${CMAKE_MODULE_PATH}/         # Expected to contain the path to this file for Windows10
      ${Irrlicht_DIR}/              # Irrlicht root directory (if provided)
  )
ENDIF (NOT Irrlicht_INCLUDE_DIRS OR NOT Irrlicht_LIBRARIES)

IF (Irrlicht_INCLUDE_DIRS AND Irrlicht_LIBRARIES)
  SET(Irrlicht_FOUND TRUE)
ELSE (Irrlicht_INCLUDE_DIRS AND Irrlicht_LIBRARIES)
  SET(Irrlicht_FOUND FALSE)
ENDIF (Irrlicht_INCLUDE_DIRS AND Irrlicht_LIBRARIES)

IF (Irrlicht_FIND_REQUIRED AND NOT Irrlicht_FOUND)
  MESSAGE(FATAL_ERROR
    "  Irrlicht not found.\n"
    "      Windows: Fill CMake variable CMAKE_MODULE_PATH to the provided directory.\n"
    "      Linux: Install Irrlicht using your package manager ($> sudo dnf install irrlicht-devel).\n"
  )
ENDIF (Irrlicht_FIND_REQUIRED AND NOT Irrlicht_FOUND)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC") #SI IL S'AGIT D'UN SYSTEME WINDOWS
	find_path(IRRLICHT_INCLUDE_DIR irrlicht.h)
	find_library(IRRLICHT_LIBRARY Irrlicht.lib)

	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR})
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR})
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL ${CMAKE_BINARY_DIR})
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_BINARY_DIR})

	if (IRRLICHT_INCLUDE_DIR AND IRRLICHT_LIBRARY) #SI LA LIB IRRLICHT A ETE TROUVE
		include_directories(${IRRLICHT_INCLUDE_DIR})
		link_directories (${IRRLICHT_INCLUDE_DIR})
		set(YOUR_LIBRARIES ${IRRLICHT_LIBRARY})
	elseif (NOT IRRLICHT_INCLUDE_DIR AND NOT IRRLICHT_LIBRARY) #SI LA LIB IRRLICHT N'A PAS ETE TROUVE
		##	ATTENTION
		##	Modifiez ici le chemin vers les fichiers de votre librairie Irrlicht
		##	ATTENTION
		set(HEADER_PATH "C:/EPITECH/irrlicht/include/")	#Path du dossier "/include/" contenant le fichier "irrlicht.h"
		set(LIB_PATH "C:/EPITECH/irrlicht/lib/Win32/Irrlicht.lib") #Path du fichier "Irrlicht.lib" compatible
		set(DLL_PATH "C:/EPITECH/irrlicht/bin/Win32/Irrlicht.dll")	#Path du fichier "Irrlicht.dll" compatible
		## 
		## FIN DE MODIFICATION
		##
		include_directories(${HEADER_PATH})
		link_directories(${HEADER_PATH})
	endif()

	configure_file(${DLL_PATH} "./Irrlicht.dll" COPYONLY)
	set(IRRLICHT_INCLUDE_DIR ${HEADER_PATH} CACHE PATH "Path to the header file" FORCE)
	set(IRRLICHT_LIBRARY ${LIB_PATH} CACHE PATH "Path to the lib file" FORCE)
	set(YOUR_LIBRARIES ${LIB_PATH})

add_executable(bomberman ${SRCS} ${HEADERS})
target_link_libraries(bomberman ${YOUR_LIBRARIES})

elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")	#SI IL S'AGIT D'UN SYSTEME UNIX

	#############################################
	## SET AUTOMATICALY IRRLICHT LIBRARY FILES ##
	#############################################

	IF (NOT Sfml_INCLUDE_DIRS OR NOT Sfml_LIBRARIES)
	  FIND_PATH(Sfml_INCLUDE_DIRS
	    NAMES
	      Audio.hpp
	    PATHS
        ${SFML_PATH}/include          # Path set by the user at the begining of the CMakeLists.txt
	      /usr/include/SFML/            # Default Fedora28 system include path
	      /usr/local/include/SFML/      # Default Fedora28 system include path
	      ${CMAKE_SFML_PATH}/include/   # Expected to contain the path to this file for Windows10
	  )
	
	  IF (MSVC)     # Windows
	    SET(CMAKE_FIND_LIBRARY_PREFIXES "")
	    SET(CMAKE_FIND_LIBRARY_SUFFIXES ".lib")
	  ELSE (MSVC)   # Linux
	    SET(CMAKE_FIND_LIBRARY_PREFIXES "lib")
	    SET(CMAKE_FIND_LIBRARY_SUFFIXES ".so")
	  ENDIF(MSVC)
	
	  FIND_LIBRARY(Sfml_LIBRARIES
	    NAMES
	      sfml-audio
	    PATHS
      ${SFML_PATH}/          # Path set by the user at the begining of the CMakeLists.txt
      /usr/lib64/                   # Default Fedora28 library path
      /usr/lib/                     # Some more Linux library path
      /usr/lib/x86_64-linux-gnu/    # Some more Linux library path
      /usr/local/lib/               # Some more Linux library path
      /usr/local/lib64/             # Some more Linux library path
      ${CMAKE_SFML_PATH}/         # Expected to contain the path to this file for Windows10
      ${SFML_DIR}/              # Irrlicht root directory (if provided)
	)
	ENDIF (NOT Sfml_INCLUDE_DIRS OR NOT Sfml_LIBRARIES)

	IF (Sfml_INCLUDE_DIRS AND Sfml_LIBRARIES)
	  SET(Sfml_FOUND TRUE)
	ELSE (Sfml_INCLUDE_DIRS AND Sfml_LIBRARIES)
	  SET(Sfml_FOUND FALSE)
	ENDIF (Sfml_INCLUDE_DIRS AND Sfml_LIBRARIES)

	IF (Sfml_FIND_REQUIRED AND NOT Sfml_FOUND)
	  MESSAGE(FATAL_ERROR
	    "  SFML not found.\n"
	    "      Windows: Fill CMake variable CMAKE_SFML_PATH to the provided directory.\n"
	    "      Linux: Install SFML 2.4 using your package manager ($> sudo dnf install sfml-devel).\n"
	  )
	ENDIF (Sfml_FIND_REQUIRED AND NOT Sfml_FOUND)

	add_executable(bomberman ${SRCS} ${HEADERS})
	target_link_libraries(bomberman ${Irrlicht_LIBRARIES})
	target_link_libraries(bomberman ${Sfml_LIBRARIES})
	target_compile_options(bomberman PUBLIC -std=gnu++11 -g3 -I${Irrlicht_INCLUDE_DIRS} ${Sfml_LIBRARIES})
endif()