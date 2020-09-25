cmake_minimum_required(VERSION 3.18)

project(TelegramBot VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Отключить permissive и отображать все ошибки
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    message("-- Using MSVC compiler")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W3 /permissive-")
else ()
    message("-- Using another compiler")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fpermissive")
endif()

# нахождение boost
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost 1.74.0 REQUIRED COMPONENTS system date_time regex)

# нахождение openssl
find_package(OpenSSL REQUIRED)

file(GLOB SOURCES 
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/src/bot/http/*.cpp"
	"${CMAKE_SOURCE_DIR}/src/bot/*.cpp"
	"${CMAKE_SOURCE_DIR}/src/bot/types/*.cpp"	
)
add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC 
    ${Boost_INCLUDE_DIR} 
    ${CMAKE_SOURCE_DIR}/include
    ${OPENSSL_INCLUDE_DIR}
)
target_link_libraries(${PROJECT_NAME} 
    ${Boost_LIBRARIES} 
    ${OPENSSL_LIBRARIES}
)
target_compile_definitions(${PROJECT_NAME} PUBLIC -D_WIN32_WINNT=0x0601 -DBOOST_BIND_GLOBAL_PLACEHOLDERS)

# установить скомпилированный проект в bin/CONFIG
install(TARGETS ${PROJECT_NAME} 
        CONFIGURATIONS Debug 
        RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/bin/debug)
install(TARGETS ${PROJECT_NAME} 
        CONFIGURATIONS Release 
        RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/bin/release)