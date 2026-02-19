########### AGGREGATED COMPONENTS AND DEPENDENCIES FOR THE MULTI CONFIG #####################
#############################################################################################

set(mesa-glu_COMPONENT_NAMES "")
if(DEFINED mesa-glu_FIND_DEPENDENCY_NAMES)
  list(APPEND mesa-glu_FIND_DEPENDENCY_NAMES libglvnd)
  list(REMOVE_DUPLICATES mesa-glu_FIND_DEPENDENCY_NAMES)
else()
  set(mesa-glu_FIND_DEPENDENCY_NAMES libglvnd)
endif()
set(libglvnd_FIND_MODE "NO_MODULE")

########### VARIABLES #######################################################################
#############################################################################################
set(mesa-glu_PACKAGE_FOLDER_DEBUG "/home/sszynk/.conan2/p/b/mesa-c1b046ec30070/p")
set(mesa-glu_BUILD_MODULES_PATHS_DEBUG )


set(mesa-glu_INCLUDE_DIRS_DEBUG "${mesa-glu_PACKAGE_FOLDER_DEBUG}/include")
set(mesa-glu_RES_DIRS_DEBUG )
set(mesa-glu_DEFINITIONS_DEBUG )
set(mesa-glu_SHARED_LINK_FLAGS_DEBUG )
set(mesa-glu_EXE_LINK_FLAGS_DEBUG )
set(mesa-glu_OBJECTS_DEBUG )
set(mesa-glu_COMPILE_DEFINITIONS_DEBUG )
set(mesa-glu_COMPILE_OPTIONS_C_DEBUG )
set(mesa-glu_COMPILE_OPTIONS_CXX_DEBUG )
set(mesa-glu_LIB_DIRS_DEBUG "${mesa-glu_PACKAGE_FOLDER_DEBUG}/lib")
set(mesa-glu_BIN_DIRS_DEBUG )
set(mesa-glu_LIBRARY_TYPE_DEBUG STATIC)
set(mesa-glu_IS_HOST_WINDOWS_DEBUG 0)
set(mesa-glu_LIBS_DEBUG GLU)
set(mesa-glu_SYSTEM_LIBS_DEBUG )
set(mesa-glu_FRAMEWORK_DIRS_DEBUG )
set(mesa-glu_FRAMEWORKS_DEBUG )
set(mesa-glu_BUILD_DIRS_DEBUG )
set(mesa-glu_NO_SONAME_MODE_DEBUG FALSE)


# COMPOUND VARIABLES
set(mesa-glu_COMPILE_OPTIONS_DEBUG
    "$<$<COMPILE_LANGUAGE:CXX>:${mesa-glu_COMPILE_OPTIONS_CXX_DEBUG}>"
    "$<$<COMPILE_LANGUAGE:C>:${mesa-glu_COMPILE_OPTIONS_C_DEBUG}>")
set(mesa-glu_LINKER_FLAGS_DEBUG
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:${mesa-glu_SHARED_LINK_FLAGS_DEBUG}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:${mesa-glu_SHARED_LINK_FLAGS_DEBUG}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:${mesa-glu_EXE_LINK_FLAGS_DEBUG}>")


set(mesa-glu_COMPONENTS_DEBUG )