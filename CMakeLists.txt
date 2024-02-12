cmake_minimum_required (VERSION 3.2)

project(Winapi)

# Add source to this project's executable.
add_executable (Winapi WIN32 "lesson_1.cpp")

target_compile_definitions(Winapi
  PRIVATE "UNICODE;_UNICODE"
)