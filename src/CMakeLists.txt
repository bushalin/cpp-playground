file(GLOB_RECURSE SOURCES "${SRC_DIR}/application/*.cpp*")
function(create_target TARGET_NAME SOURCE_FILE)
    add_executable(
        ${TARGET_NAME}
        ${SOURCE_FILE}
        ${SOURCES}
    )

    target_link_libraries(
        ${TARGET_NAME}
        "-Wl,--copy-dt-needed-entries,--no-as-needed"
        m dl stdc++fs
        uuid
        ${EXTERNAL_LIB_FILES}
        dl
    )
endfunction()

create_target(${APP_NAME} ${SRC_DIR}/main.cpp)
