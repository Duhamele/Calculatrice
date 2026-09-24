
set(FILES_TEST_CAL_MATH add_number.cpp
                        equal_number.cpp)

foreach( FILE_TEST_CAL_MATH ${FILES_TEST_CAL_MATH})
    message(STATUS "test: ${FILE_TEST_CAL_MATH}")
    set(NAME_TEST "Test_${FILE_TEST_CAL_MATH}")
    add_executable(${NAME_TEST} ${FILE_TEST_CAL_MATH} )
    target_include_directories(${NAME_TEST} PUBLIC ${SRC_CALCULATOR})
    add_test(NAME ${NAME_TEST} COMMAND ${NAME_TEST})

endforeach()
