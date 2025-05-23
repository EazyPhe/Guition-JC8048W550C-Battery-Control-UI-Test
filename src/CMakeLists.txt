# This file was automatically generated for projects
# without default 'CMakeLists.txt' file.

FILE(GLOB_RECURSE app_sources ${CMAKE_SOURCE_DIR}/src/*.cpp)

# Tell IDF to exclude assembler files from auto-including
idf_component_register(
    SRCS ${app_sources}
    INCLUDE_DIRS "."
)

# Add preprocessor defs directly to component library
target_compile_definitions(${COMPONENT_LIB} PUBLIC
    LV_CONF_INCLUDE_SIMPLE=1
    LV_USE_DRAW_SW_ASM=0
)
