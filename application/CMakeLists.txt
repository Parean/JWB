
# -*- mode:cmake -*-
if(NOT UNIX)
 	message(FATAL "Unsupported operating system")
endif()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(JWB-GENERATED_SRC
	${CMAKE_CURRENT_SOURCE_DIR}/antlr-for-java/JavaLexer.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/antlr-for-java/JavaParser.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/antlr-for-java/JavaBaseListener.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/antlr-for-java/JavaBaseVisitor.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/antlr-for-java/JavaListener.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/antlr-for-java/JavaVisitor.cpp
	)

foreach( src_file ${JWB-GENERATED_SRC} )
		set_source_files_properties(
			${src_file}
			PROPERTIES
			GENERATED TRUE
			)
endforeach( src_file ${JWB-GENERATED_SRC} )

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/../antlr4-cpp-runtime-4.6-source/run/usr/local/include/antlr4-runtime
	${CMAKE_CURRENT_SOURCE_DIR}/antlr-for-java
	${CMAKE_CURRENT_SOURCE_DIR}/inc
	)

set(JWB_SRC
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/metricsCalculator.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/customListener.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/classDescription.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/interfaceDescription.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/methodDescription.cpp
	${JWB-GENERATED_SRC}
	)

foreach( src_file ${JWB_SRC} )
		set_source_files_properties(
			${src_file}
			PROPERTIES
			COMPILE_FLAGS -Wno-overloaded-virtual
			)
endforeach( src_file ${JWB_SRC} )

add_executable(JWB
	${JWB_SRC}
	)

target_link_libraries(JWB  ${CMAKE_CURRENT_SOURCE_DIR}/../antlr4-cpp-runtime-4.6-source/dist/libantlr4-runtime.a)

install(TARGETS JWB
		DESTINATION "share"
		COMPONENT dev
		)
