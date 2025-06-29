cmake_minimum_required(VERSION 3.15)

# Configuração básica do projeto
project(AVL_Tree 
    VERSION 1.0.0
    DESCRIPTION "Implementação completa de Árvore AVL em C"
    LANGUAGES C
)

# Configurações do compilador C
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Configurações de compilação
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Configurações de build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_C_FLAGS_DEBUG "-g -O0")
set(CMAKE_C_FLAGS_RELEASE "-O3 -DNDEBUG")

# Definir diretórios
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Biblioteca da árvore AVL
add_library(avl_tree_lib STATIC
    avl_tree.c
    avl_tree.h
)

target_include_directories(avl_tree_lib PUBLIC .)

# Executável principal com menu interativo
add_executable(avl_tree
    main.c
)

target_link_libraries(avl_tree avl_tree_lib)

# Executável de demonstração dos casos específicos
add_executable(demo_casos
    demo_casos.c
)

target_link_libraries(demo_casos avl_tree_lib)

# Targets customizados para facilitar execução
add_custom_target(run_demo
    COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/demo_casos
    DEPENDS demo_casos
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Executando demonstração dos 4 casos específicos..."
)

add_custom_target(run_interactive
    COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/avl_tree
    DEPENDS avl_tree
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Executando menu interativo da árvore AVL..."
)

add_custom_target(run_all
    COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/demo_casos
    COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/avl_tree
    DEPENDS demo_casos avl_tree
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Executando primeiro a demonstração e depois o menu interativo..."
)

# Target para limpeza completa
add_custom_target(clean_all
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/bin
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/CMakeFiles
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/CMakeCache.txt
    COMMENT "Limpando todos os arquivos de build..."
)

# Informações do projeto
message(STATUS "==============================================")
message(STATUS "    ÁRVORE AVL - CONFIGURAÇÃO CMAKE")
message(STATUS "==============================================")
message(STATUS "Projeto: ${PROJECT_NAME} v${PROJECT_VERSION}")
message(STATUS "Descrição: ${PROJECT_DESCRIPTION}")
message(STATUS "Compilador C: ${CMAKE_C_COMPILER_ID}")
message(STATUS "Padrão C: C${CMAKE_C_STANDARD}")
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "==============================================")

# Exibir instruções de uso
message(STATUS "")
message(STATUS "COMO USAR:")
message(STATUS "  cmake -B build")
message(STATUS "  cmake --build build")
message(STATUS "")
message(Status "EXECUTAR:")
message(STATUS "  cmake --build build --target run_demo      # Demonstração dos casos")
message(STATUS "  cmake --build build --target run_interactive # Menu interativo")
message(STATUS "  cmake --build build --target run_all       # Executar ambos")
message(STATUS "")
message(STATUS "OU execute diretamente:")
message(STATUS "  ./build/bin/demo_casos")
message(STATUS "  ./build/bin/avl_tree")
message(STATUS "==============================================")

# Configurações adicionais para Windows
if(WIN32)
    set_target_properties(avl_tree PROPERTIES
        OUTPUT_NAME "avl_tree"
        SUFFIX ".exe"
    )
    set_target_properties(demo_casos PROPERTIES
        OUTPUT_NAME "demo_casos"
        SUFFIX ".exe"
    )
endif()

# Configurações de instalação (opcional)
install(TARGETS avl_tree demo_casos avl_tree_lib
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

install(FILES avl_tree.h
    DESTINATION include
)
