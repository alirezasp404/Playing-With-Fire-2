# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Playing_With_Fire_2_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Playing_With_Fire_2_autogen.dir\\ParseCache.txt"
  "Playing_With_Fire_2_autogen"
  )
endif()
