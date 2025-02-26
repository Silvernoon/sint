# Define the variables that this module will set:
# - STEAMAPI_LIBRARIES: The Steam API library.
# - STEAMAPI_INCLUDE_DIRS: The location of Steam API headers.

include(FindPackageHandleStandardArgs)

find_library(STEAMAPI_LIBRARIES
  NAMES libsteam_api steam_api steam_api64
)
find_path(STEAMAPI_INCLUDE_DIRS
  steam/steam_api.h
)

mark_as_advanced(
    STEAMAPI_LIBRARIES
    STEAMAPI_INCLUDE_DIRS
)

find_package_handle_standard_args(STEAMAPI
  RERUIRED_VARS STEAMAPI_INCLUDE_DIRS STEAMAPI_LIBRARIES
)

