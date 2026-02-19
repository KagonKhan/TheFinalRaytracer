########### AGGREGATED COMPONENTS AND DEPENDENCIES FOR THE MULTI CONFIG #####################
#############################################################################################

set(xorg-macros_COMPONENT_NAMES "")
if(DEFINED xorg-macros_FIND_DEPENDENCY_NAMES)
  list(APPEND xorg-macros_FIND_DEPENDENCY_NAMES )
  list(REMOVE_DUPLICATES xorg-macros_FIND_DEPENDENCY_NAMES)
else()
  set(xorg-macros_FIND_DEPENDENCY_NAMES )
endif()

########### VARIABLES #######################################################################
#############################################################################################
set(xorg-macros_PACKAGE_FOLDER_DEBUG "/home/sszynk/.conan2/p/xorg-a7814e7f591fa/p")
set(xorg-macros_BUILD_MODULES_PATHS_DEBUG )


set(xorg-macros_INCLUDE_DIRS_DEBUG )
set(xorg-macros_RES_DIRS_DEBUG )
set(xorg-macros_DEFINITIONS_DEBUG )
set(xorg-macros_SHARED_LINK_FLAGS_DEBUG )
set(xorg-macros_EXE_LINK_FLAGS_DEBUG )
set(xorg-macros_OBJECTS_DEBUG )
set(xorg-macros_COMPILE_DEFINITIONS_DEBUG )
set(xorg-macros_COMPILE_OPTIONS_C_DEBUG )
set(xorg-macros_COMPILE_OPTIONS_CXX_DEBUG )
set(xorg-macros_LIB_DIRS_DEBUG )
set(xorg-macros_BIN_DIRS_DEBUG )
set(xorg-macros_LIBRARY_TYPE_DEBUG UNKNOWN)
set(xorg-macros_IS_HOST_WINDOWS_DEBUG 0)
set(xorg-macros_LIBS_DEBUG )
set(xorg-macros_SYSTEM_LIBS_DEBUG )
set(xorg-macros_FRAMEWORK_DIRS_DEBUG )
set(xorg-macros_FRAMEWORKS_DEBUG )
set(xorg-macros_BUILD_DIRS_DEBUG )
set(xorg-macros_NO_SONAME_MODE_DEBUG FALSE)


# COMPOUND VARIABLES
set(xorg-macros_COMPILE_OPTIONS_DEBUG
    "$<$<COMPILE_LANGUAGE:CXX>:${xorg-macros_COMPILE_OPTIONS_CXX_DEBUG}>"
    "$<$<COMPILE_LANGUAGE:C>:${xorg-macros_COMPILE_OPTIONS_C_DEBUG}>")
set(xorg-macros_LINKER_FLAGS_DEBUG
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:${xorg-macros_SHARED_LINK_FLAGS_DEBUG}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:${xorg-macros_SHARED_LINK_FLAGS_DEBUG}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:${xorg-macros_EXE_LINK_FLAGS_DEBUG}>")


set(xorg-macros_COMPONENTS_DEBUG )