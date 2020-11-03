FIND_PATH(XSD_INCLUDE_DIR xsd/cxx/parser/elements.hxx
        "C:/Program Files/CodeSynthesis XSD 4.0/include"
        "C:/Program Files (x86)/CodeSynthesis XSD 4.0/include"
        $ENV{XSDDIR}/include
        $ENV{CODESYNTH}/include
        /usr/local/include /usr/include
        )

FIND_PATH(XSD_DLL_DIR
        "C:/Program Files/CodeSynthesis XSD 4.0/bin"
        "C:/Program Files (x86)/CodeSynthesis XSD 4.0/bin"
        $ENV{XSDDIR}/bin
        $ENV{CODESYNTH}/bin
        /usr/local/include /usr/bin
        )

IF (WIN32)
    SET(XSDCXX_FILENAME1 xsd.exe)
ELSE ()
    SET(XSDCXX_FILENAME1 xsdcxx)
    SET(XSDCXX_FILENAME2 xsd)
ENDIF ()


FIND_PROGRAM(XSDCXX_EXECUTABLE
        NAMES
        ${XSDCXX_FILENAME1} ${XSDCXX_FILENAME2}
        PATHS
        "C:/Program Files/CodeSynthesis XSD 4.0/bin"
        "C:/Program Files (x86)/CodeSynthesis XSD 4.0/bin"
        $ENV{XSDDIR}/bin
        /usr/local/bin
        /usr/bin
        )


MESSAGE(STATUS Include dir: ${XSD_INCLUDE_DIR})
MESSAGE(STATUS Bin dir: ${XSD_DLL_DIR})

# if the include and the program are found then we have it
IF (XSD_INCLUDE_DIR)
    IF (XSDCXX_EXECUTABLE)
        SET(XSD_FOUND "YES")
    ENDIF (XSDCXX_EXECUTABLE)
ENDIF (XSD_INCLUDE_DIR)

IF (NOT DEFINED XSD_FOUND)
    MESSAGE_ERROR(libxsd not found. Install it first, download from https://www.codesynthesis.com/products/xsd/download.xhtml)
ENDIF ()