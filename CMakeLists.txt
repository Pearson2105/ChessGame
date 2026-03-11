project(setup)
cmake_minimum_required(VERSION 3.11)
# Require modern C++
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#### Setup Directories ####
#Main output directory
SET(OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
# Ouput all DLLs from all libs into main build folder
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})

#### Add External Dependencies ####
add_subdirectory("lib/SFML")
set(SFML_INCS "lib/SFML/include")
link_directories("${CMAKE_BINARY_DIR}/lib/SFML/lib")

#### Chess /game ####
add_executable(Chess 
src/main.cpp
src/Game.cpp
src/Board.cpp
src/Piece.cpp
src/TurnManager.cpp
src/Timer.cpp
src/Promotion.cpp
src/MoveValidator.cpp
src/HighlightSystem.cpp)
target_include_directories(Chess PRIVATE ${SFML_INCS})
target_link_libraries(Chess sfml-graphics)