# Avoid multiple calls to find_package to append duplicated properties to the targets
include_guard()########### VARIABLES #######################################################################
#############################################################################################
set(xorg-macros_FRAMEWORKS_FOUND_DEBUG "") # Will be filled later
conan_find_apple_frameworks(xorg-macros_FRAMEWORKS_FOUND_DEBUG "${xorg-macros_FRAMEWORKS_DEBUG}" "${xorg-macros_FRAMEWORK_DIRS_DEBUG}")

set(xorg-macros_LIBRARIES_TARGETS "") # Will be filled later


######## Create an interface target to contain all the dependencies (frameworks, system and conan deps)
if(NOT TARGET xorg-macros_DEPS_TARGET)
    add_library(xorg-macros_DEPS_TARGET INTERFACE IMPORTED)
endif()

set_property(TARGET xorg-macros_DEPS_TARGET
             APPEND PROPERTY INTERFACE_LINK_LIBRARIES
             $<$<CONFIG:Debug>:${xorg-macros_FRAMEWORKS_FOUND_DEBUG}>
             $<$<CONFIG:Debug>:${xorg-macros_SYSTEM_LIBS_DEBUG}>
             $<$<CONFIG:Debug>:>)

####### Find the libraries declared in cpp_info.libs, create an IMPORTED target for each one and link the
####### xorg-macros_DEPS_TARGET to all of them
conan_package_library_targets("${xorg-macros_LIBS_DEBUG}"    # libraries
                              "${xorg-macros_LIB_DIRS_DEBUG}" # package_libdir
                              "${xorg-macros_BIN_DIRS_DEBUG}" # package_bindir
                              "${xorg-macros_LIBRARY_TYPE_DEBUG}"
                              "${xorg-macros_IS_HOST_WINDOWS_DEBUG}"
                              xorg-macros_DEPS_TARGET
                              xorg-macros_LIBRARIES_TARGETS  # out_libraries_targets
                              "_DEBUG"
                              "xorg-macros"    # package_name
                              "${xorg-macros_NO_SONAME_MODE_DEBUG}")  # soname

# FIXME: What is the result of this for multi-config? All configs adding themselves to path?
set(CMAKE_MODULE_PATH ${xorg-macros_BUILD_DIRS_DEBUG} ${CMAKE_MODULE_PATH})

########## GLOBAL TARGET PROPERTIES Debug ########################################
    set_property(TARGET xorg-macros::xorg-macros
                 APPEND PROPERTY INTERFACE_LINK_LIBRARIES
                 $<$<CONFIG:Debug>:${xorg-macros_OBJECTS_DEBUG}>
                 $<$<CONFIG:Debug>:${xorg-macros_LIBRARIES_TARGETS}>
                 )

    if("${xorg-macros_LIBS_DEBUG}" STREQUAL "")
        # If the package is not declaring any "cpp_info.libs" the package deps, system libs,
        # frameworks etc are not linked to the imported targets and we need to do it to the
        # global target
        set_property(TARGET xorg-macros::xorg-macros
                     APPEND PROPERTY INTERFACE_LINK_LIBRARIES
                     xorg-macros_DEPS_TARGET)
    endif()

    set_property(TARGET xorg-macros::xorg-macros
                 APPEND PROPERTY INTERFACE_LINK_OPTIONS
                 $<$<CONFIG:Debug>:${xorg-macros_LINKER_FLAGS_DEBUG}>)
    set_property(TARGET xorg-macros::xorg-macros
                 APPEND PROPERTY INTERFACE_INCLUDE_DIRECTORIES
                 $<$<CONFIG:Debug>:${xorg-macros_INCLUDE_DIRS_DEBUG}>)
    # Necessary to find LINK shared libraries in Linux
    set_property(TARGET xorg-macros::xorg-macros
                 APPEND PROPERTY INTERFACE_LINK_DIRECTORIES
                 $<$<CONFIG:Debug>:${xorg-macros_LIB_DIRS_DEBUG}>)
    set_property(TARGET xorg-macros::xorg-macros
                 APPEND PROPERTY INTERFACE_COMPILE_DEFINITIONS
                 $<$<CONFIG:Debug>:${xorg-macros_COMPILE_DEFINITIONS_DEBUG}>)
    set_property(TARGET xorg-macros::xorg-macros
                 APPEND PROPERTY INTERFACE_COMPILE_OPTIONS
                 $<$<CONFIG:Debug>:${xorg-macros_COMPILE_OPTIONS_DEBUG}>)

########## For the modules (FindXXX)
set(xorg-macros_LIBRARIES_DEBUG xorg-macros::xorg-macros)
