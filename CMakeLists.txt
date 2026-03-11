cmake_minimum_required(VERSION 3.11)
project(Chess)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Output directory

set(OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})

# SFML

add_subdirectory(lib/SFML)
set(SFML_INCS "lib/SFML/include")

# Executable

add_executable(Chess
src/main.cpp
src/Game.cpp
src/Board.cpp
src/Piece.cpp
src/TurnManager.cpp
src/Timer.cpp
src/Promotion.cpp
src/MoveValidator.cpp
src/HighlightSystem.cpp
)

# Include directories

target_include_directories(Chess PRIVATE include ${SFML_INCS})

# Link SFML

target_link_libraries(Chess
sfml-graphics
sfml-window
sfml-system
)

# Copy resources folder to build directory

file(COPY ${CMAKE_SOURCE_DIR}/resources/pieces
DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
