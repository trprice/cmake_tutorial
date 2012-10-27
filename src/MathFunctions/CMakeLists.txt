add_library(MathFunctions mysqrt.cpp)

# Add the install targets.
#       These are relative to CMAKE_INSTALL_PREFIX
install (TARGETS MathFunctions DESTINATION lib)
install (FILES include/MathFunctions.h DESTINATION include)
