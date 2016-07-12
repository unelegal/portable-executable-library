cmake_minimum_required(VERSION 2.8)

set(COMPONENTS test_bound_import test_dotnet test_exports test_imports test_resource_bitmap test_resource_message_table test_resource_version_info test_runner test_tls test_checksum test_entropy test_load_config test_resource_icon_cursor test_resources test_resource_viewer tests_basic test_debug test_exception_directory test_relocations test_resource_manager test_resource_string_table test_rich_data tests_utils)

foreach (COMPONENT ${COMPONENTS})
    add_subdirectory(${COMPONENT})
endforeach ()

