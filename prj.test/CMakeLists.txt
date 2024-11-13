set(CMAKE_CXX_STANDARD 11)

add_executable(complex_test complex_test.cpp)
target_link_libraries(complex_test complex)

add_executable(complex_doctest complex_doctest.cpp)
target_link_libraries(complex_doctest complex)

add_executable(rational_doctest rational_doctest.cpp)
target_link_libraries(rational_doctest rational)

add_executable(arrayd_doctst arrayd_doctest.cpp)
target_link_libraries(arrayd_doctst arrayd)