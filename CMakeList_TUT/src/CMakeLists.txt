add_library( DisplayImage SHARED
    DisplayImage.cpp
)

target_link_libraries( DisplayImage
    ${THIRD_PARTY_LIBS}
)
