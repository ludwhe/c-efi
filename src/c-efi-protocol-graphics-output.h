#pragma once

/**
 * UEFI Protocol - Graphics Output
 *
 * XXX
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <c-efi-base.h>

#define C_EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID C_EFI_GUID(0x9042a9de, 0x23dc, 0x4a38, 0x96, 0xfb, 0x7a, 0xde, 0xd0, 0x80, 0x51, 0x6a)

typedef struct CEfiPixelBitmask {
        CEfiU32 red_mask;
        CEfiU32 green_mask;
        CEfiU32 blue_mask;
        CEfiU32 reserved_mask;
} CEfiPixelBitmask;

typedef enum CEfiGraphicsPixelFormat {
        C_EFI_PIXEL_RED_GREEN_BLUE_RESERVED_8_BIT_PER_COLOR,
        C_EFI_PIXEL_BLUE_GREEN_RED_RESERVED_8_BIT_PER_COLOR,
        C_EFI_PIXEL_BIT_MASK,
        C_EFI_PIXEL_BLT_ONLY,
        C_EFI_PIXEL_FORMAT_MAX
} CEfiGraphicsPixelFormat;

typedef struct CEfiGraphicsOutputProtocolModeInformation {
        CEfiU32 version;
        CEfiU32 horizontal_resolution;
        CEfiU32 vertical_resolution;
        CEfiGraphicsPixelFormat pixel_format;
        CEfiPixelBitmask pixel_information;
        CEfiU32 pixels_per_scan_line;
} CEfiGraphicsOutputProtocolModeInformation;

typedef struct CEfiGraphicsOutputProtocolMode {
        CEfiU32 max_mode;
        CEfiU32 mode;
        CEfiGraphicsOutputProtocolModeInformation *info;
        CEfiUSize size_of_info;
        CEfiPhysicalAddress frame_buffer_base;
        CEfiUSize frame_buffer_size;
} CEfiGraphicsOutputProtocolMode;

typedef struct CEfiGraphicsOutputBltPixel {
        CEfiU8 blue;
        CEfiU8 green;
        CEfiU8 red;
        CEfiU8 reserved;
} CEfiGraphicsOutputBltPixel;

typedef enum CEfiGraphicsOutputBltOperation {
        C_EFI_BLT_VIDEO_FILL,
        C_EFI_BLT_VIDEO_TO_BLT_BUFFER,
        C_EFI_BLT_BUFFER_TO_VIDEO,
        C_EFI_BLT_VIDEO_TO_VIDEO,
        C_EFI_GRAPHICS_OUTPUT_BLT_OPERATION_MAX
} CEfiGraphicsOutputBltOperation;

typedef struct CEfiGraphicsOutputProtocol {
        CEfiStatus (CEFICALL *query_mode) (
                CEfiGraphicsOutputProtocol *this_,
                CEfiU32 mode_number,
                CEfiUSize *size_of_info,
                CEfiGraphicsOutputProtocolModeInformation **info
        );
        CEfiStatus (CEFICALL *set_mode) (
                CEfiGraphicsOutputProtocol *this_,
                CEfiU32 mode_number
        );
        CEfiStatus (CEFICALL *blt) (
                CEfiGraphicsOutputProtocol *this_,
                CEfiGraphicsOutputBltPixel *blt_buffer,
                CEfiGraphicsOutputBltOperation blt_operation,
                CEfiUSize source_x,
                CEfiUSize source_y,
                CEfiUSize destination_x,
                CEfiUSize destination_y,
                CEfiUSize width,
                CEfiUSize height,
                CEfiUSize delta
        );
        CEfiGraphicsOutputProtocolMode *mode;
} CEfiGraphicsOutputProtocol;

#ifdef __cplusplus
}
#endif
