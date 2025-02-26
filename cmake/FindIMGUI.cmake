# Define the variables that this module will set:
# - IMGUI_LIBRARIES: The Steam API library.
# - IMGUI_INCLUDE_DIRS: The location of Steam API headers.

include(FindPackageHandleStandardArgs)

find_library(IMGUI_LIBRARIES
  NAMES imgui libimgui
)
find_path(IMGUI_INCLUDE_DIRS
  imgui.h
)

mark_as_advanced(
    IMGUI_LIBRARIES
    IMGUI_INCLUDE_DIRS
)

find_package_handle_standard_args(IMGUI
  RERUIRED_VARS IMGUI_INCLUDE_DIRS IMGUI_LIBRARIES
)

