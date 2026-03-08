cmake_minimum_required(VERSION 3.20)
project(OSCRedesign LANGUAGES CXX OBJCXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(osc_redesign
    src/OscTypes.cpp
    src/VAOscSource.cpp
    src/WTOscSource.cpp
    src/SampleOscSource.cpp
    src/MultiSampleSource.cpp
    src/CombiOscVoice.cpp
    src/CombiOscEngine.cpp
)

target_include_directories(osc_redesign PUBLIC include)

add_executable(osc_smoke_test tests/smoke.cpp)
target_link_libraries(osc_smoke_test PRIVATE osc_redesign)

if(APPLE)
    add_executable(osc_standalone apps/standalone_audio.cpp)
    target_link_libraries(osc_standalone PRIVATE osc_redesign "-framework AudioToolbox" "-framework CoreFoundation")

    add_executable(osc_ui MACOSX_BUNDLE apps/osc_ui.mm)
    target_link_libraries(osc_ui PRIVATE osc_redesign "-framework AppKit" "-framework AudioToolbox" "-framework CoreFoundation")
    set_target_properties(osc_ui PROPERTIES
        XCODE_ATTRIBUTE_CLANG_ENABLE_OBJC_ARC YES
    )
endif()
