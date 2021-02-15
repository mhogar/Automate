add_library(automate-core Animation.cxx AnimationBuilder.cxx PreviewHandle.cxx)

target_link_libraries(automate-core PRIVATE actions graphics)
target_include_directories(automate-core PUBLIC "${PROJECT_SOURCE_DIR}")
