
# - Try to find XSD
# Once done this will define
#
# This module defines
# XSD_INCLUDE_DIR, where to find elements.hxx, etc.
# XSD_EXECUTABLE, the exe file
# XSD_FOUND, If false, don't try to use it.

FIND_PATH(XSD_INCLUDE_DIR xsd/cxx/parser/elements.hxx PATH_SUFFIXES ../Libraries/XSD/libxsd PATHS
        "./Libraries/XSD/libxsd"
        )

FIND_PROGRAM(XSD_EXECUTABLE
        NAMES
        xsd xsdcxx
        PATHS
        "./Libraries/XSD/bin"
        )

# if the include and the program are found then we have it
IF(XSD_INCLUDE_DIR)
    IF(XSD_EXECUTABLE)
        SET( XSD_FOUND "YES" )
    ENDIF(XSD_EXECUTABLE)
ENDIF(XSD_INCLUDE_DIR)

# MESSAGE(STATUS "XSD_INCLUDE_DIR=${XSD_INCLUDE_DIR}")
# MESSAGE(STATUS "XSD_EXECUTABLE=${XSD_EXECUTABLE}")

MARK_AS_ADVANCED(
        XSD_INCLUDE_DIR
        XSD_EXECUTABLE
)