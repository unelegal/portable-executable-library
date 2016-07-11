cmake_minimum_required(VERSION 2.8)

set(COMPONENTS address_convertions bound_import_reader entropy_calculator exports_reader import_adder pe_realigner pe_stripper resource_editor section_adder tls_reader basic_dotnet_viewer exception_dir_reader full_pe_rebuilder imports_reader pe_rebaser relocation_adder resource_viewer sections_and_addresses basic_info_viewer debug_info_reader export_adder image_config_editor pe_config_reader pe_sections_reader relocations_reader rich_overlay_stub_reader tls_editor)

foreach (COMPONENT ${COMPONENTS})
    add_subdirectory(${COMPONENT})
endforeach ()

