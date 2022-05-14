cmake_minimum_required(VERSION 3.21.2)
project(lme_complexity)

set(SOURCES
    main.cpp
    impl/analyzer.cpp
)

set(INCLUDE_DIRECTORIES
    ${CONAN_INCLUDE_DIRS_CXXOPTS}
)

set(COMPILE_DEFINITIONS
    LME_PROJECT_NAME="${PROJECT_NAME}"
)

set(COMPILE_FEATURES
    cxx_std_20
)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIRECTORIES})
target_compile_definitions(${PROJECT_NAME} PRIVATE ${COMPILE_DEFINITIONS})
target_compile_features(${PROJECT_NAME} PRIVATE ${COMPILE_FEATURES})