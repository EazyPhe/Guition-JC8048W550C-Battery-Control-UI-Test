# This is a CMakeLists.txt file for ESP-IDF component
set(COMPONENT_SRCS "main.cpp")
set(COMPONENT_ADD_INCLUDEDIRS ".")

register_component()

# Ensure LVGL can find our lv_conf.h
target_compile_definitions(${COMPONENT_TARGET} PUBLIC
    -DLV_CONF_INCLUDE_SIMPLE
)
