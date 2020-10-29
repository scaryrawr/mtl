add_executable(memory memory.cpp)
target_link_libraries(memory mtl)

add_executable(split split.cpp)
target_link_libraries(split mtl)

add_executable(insensitive insensitive.cpp)
target_link_libraries(insensitive mtl)