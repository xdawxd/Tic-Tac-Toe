cmake_minimum_required(VERSION 3.27)
project(tic_tac_toe)

set(CMAKE_CXX_STANDARD 17)

add_executable(tic_tac_toe main.cpp
        headers/Engine.hpp
        headers/Board.hpp
        headers/Game.hpp
        headers/Action.hpp
        headers/Field.hpp
        headers/State.hpp
        headers/MenuState.hpp
        headers/StateFactory.hpp
        src/Engine.cpp
        src/Board.cpp
        src/Game.cpp
        src/Action.cpp
        src/Field.cpp
        src/State.cpp
        src/MenuState.cpp
        src/StateFactory.cpp
        headers/ExitState.hpp
        src/ExitState.cpp
        headers/LocalState.h
        src/LocalState.cpp
)

include_directories(headers /usr/include c:/SFML/include)

set(SFML_ROOT c:/SFML)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(tic_tac_toe ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()
#
#file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})  # The assets directory is for storing game levels, fonts, sprites, sounds etc.
# Refer to https://github.com/CaffeinatedTech/nibbles/blob/main/nibbles-01/assets/assets.md

# Copy dlls to build
if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB MINGW_DEP_DLLS "C:/mingw64/bin/*.dll")
    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()
