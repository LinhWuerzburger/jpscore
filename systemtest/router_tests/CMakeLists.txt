add_test(NAME router_test-10 COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_SOURCE_DIR}/systemtest/router_tests/test_router_10/runtest_router_10.py ${jpscore_exe})

set_tests_properties(
        router_test-10
        PROPERTIES LABELS "CI:FAST")

add_test(NAME router_test_corridor_close COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_SOURCE_DIR}/systemtest/router_tests/test_corridor_close/runtest_corridor_close.py ${jpscore_exe})

set_tests_properties(
        router_test_corridor_close
        PROPERTIES LABELS "CI:FAST")
