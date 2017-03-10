
# -*- mode:cmake -*-
if(NOT UNIX)
  message(FATAL "Unsupported operating system")
endif()

set(CMAKE_CXX_STANDARD 11) 
set(CMAKE_CXX_STANDARD_REQUIRED ON) 
set(CMAKE_CXX_EXTENSIONS OFF) 

set(antlr4-demo-GENERATED_SRC
   ${CMAKE_CURRENT_SOURCE_DIR}/generated/TLexer.cpp 
   ${CMAKE_CURRENT_SOURCE_DIR}/generated/TParser.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/generated/TParserBaseListener.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/generated/TParserBaseVisitor.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/generated/TParserListener.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/generated/TParserVisitor.cpp
 )

foreach( src_file ${antlr4-demo-GENERATED_SRC} )
      set_source_files_properties(
          ${src_file}
          PROPERTIES
          GENERATED TRUE
          )
endforeach( src_file ${antlr4-demo-GENERATED_SRC} )

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/../run/usr/local/include/antlr4-runtime
  ${CMAKE_CURRENT_SOURCE_DIR}/generated
  )

set(antlr4-demo_SRC 
  ${CMAKE_CURRENT_SOURCE_DIR}/Linux/main.cpp
  ${antlr4-demo-GENERATED_SRC}
  )

foreach( src_file ${antlr4-demo_SRC} )
      set_source_files_properties(
          ${src_file}
          PROPERTIES
          COMPILE_FLAGS -Wno-overloaded-virtual
          )
endforeach( src_file ${antlr4-demo_SRC} )

add_executable(antlr4-demo
  ${antlr4-demo_SRC}
  )

target_link_libraries(antlr4-demo  ${CMAKE_CURRENT_SOURCE_DIR}/../dist/libantlr4-runtime.a)

install(TARGETS antlr4-demo 
        DESTINATION "share" 
        COMPONENT dev 
        )

