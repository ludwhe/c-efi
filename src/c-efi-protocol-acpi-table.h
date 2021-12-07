#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <c-efi-base.h>

#define C_EFI_ACPI_TABLE_PROTOCOL_GUID C_EFI_GUID(0xffe06bdd, 0x6107, 0x46a6, 0x7b, 0xb2, 0x5a, 0x9c, 0x7e, 0xc5, 0x27, 0x5c)

typedef struct CEfiAcpiTableProtocol {
    CEfiStatus (CEFICALL *install_acpi_table) (
        CEfiAcpiTableProtocol *this_,
        void *acpi_table_buffer,
        CEfiUSize acpi_table_buffer_size,
        CEfiUSize *table_key
    );
    CEfiStatus (CEFICALL *uninstall_acpi_table) (
        CEfiAcpiTableProtocol *this_,
        CEfiUSize table_key
    );
} CEfiAcpiTableProtocol;

#ifdef __cplusplus
}
#endif
