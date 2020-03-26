project (Argpass)

# Header only library, therefore INTERFACE
add_library(argpass INTERFACE)

# INTERFACE targets only have INTERFACE properties
target_include_directories(argpass INTERFACE include)


