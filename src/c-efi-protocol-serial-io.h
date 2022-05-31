#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <c-efi-base.h>
#include <c-efi-system.h>

#define C_EFI_SERIAL_IO_PROTOCOL_GUID                                                               \
	C_EFI_GUID(0xbb25cf6f, 0xf1d4, 0x11d2, 0x9a, 0x0c, 0x00, 0x90, 0x27, 0x3f, 0xc1, 0xfd)

#define C_EFI_SERIAL_IO_PROTOCOL_REVISION C_EFI_U32_C(0x10000)
#define C_EFI_SERIAL_IO_PROTOCOL_REVISION1p1 C_EFI_U32_C(0x10001)

#define C_EFI_SERIAL_CLEAR_TO_SEND C_EFI_U32_C(0x0010)
#define C_EFI_SERIAL_DATA_SET_READY C_EFI_U32_C(0x0020)
#define C_EFI_SERIAL_RING_INDICATE C_EFI_U32_C(0x0040)
#define C_EFI_SERIAL_CARRIER_DETECT C_EFI_U32_C(0x0080)
#define C_EFI_SERIAL_REQUEST_TO_SEND C_EFI_U32_C(0x0002)
#define C_EFI_SERIAL_DATA_TERMINAL_READY C_EFI_U32_C(0x0001)
#define C_EFI_SERIAL_INPUT_BUFFER_EMPTY C_EFI_U32_C(0x0100)
#define C_EFI_SERIAL_OUTPUT_BUFFER_EMPTY C_EFI_U32_C(0x0200)
#define C_EFI_SERIAL_HARDWARE_LOOPBACK_ENABLE C_EFI_U32_C(0x1000)
#define C_EFI_SERIAL_SOFTWARE_LOOPBACK_ENABLE C_EFI_U32_C(0x2000)
#define C_EFI_SERIAL_HARDWARE_FLOW_CONTROL_ENABLE C_EFI_U32_C(0x4000)

#define C_EFI_SERIAL_TERMINAL_DEVICE_TYPE_GUID                                                      \
	C_EFI_GUID(0x6ad9a60f, 0x5815, 0x4c7c, 0x8a, 0x10, 0x50, 0x53, 0xd2, 0xbf, 0x7a, 0x1b)

typedef enum CEfiParityType {
	C_EFI_DEFAULT_PARITY,
	C_EFI_NO_PARITY,
	C_EFI_EVEN_PARITY,
	C_EFI_ODD_PARITY,
	C_EFI_MARK_PARITY,
	C_EFI_SPACE_PARITY
} CEfiParityType;

typedef enum CEfiStopBitsType {
	C_EFI_DEFAULT_STOP_BITS,
	C_EFI_ONE_STOP_BIT,
	C_EFI_ONE_FIVE_STOP_BITS,
	C_EFI_TWO_STOP_BITs
} CEfiStopBitsType;

typedef struct CEfiSerialIOMode {
	uint32_t control_mask;
	uint32_t timeout;
	uint64_t baud_rate;
	uint32_t receive_fifo_depth;
	uint32_t data_bits;
	uint32_t parity;
	uint32_t stop_bits;
} CEfiSerialIOMode;

typedef struct CEfiSerialIOProtocol CEfiSerialIOProtocol;

typedef struct CEfiSerialIOProtocol {
	uint32_t revision;
	CEfiStatus(C_EFICALL *reset)(CEfiSerialIOProtocol *this_);
	CEfiStatus(C_EFICALL *set_attributes)(CEfiSerialIOProtocol *this_, uint64_t baud_rate,
					     uint32_t receive_fifo_depth, uint32_t timeout,
					     CEfiParityType parity, uint8_t data_bits,
					     CEfiStopBitsType stop_bits);
	CEfiStatus(C_EFICALL *set_control)(CEfiSerialIOProtocol *this_, uint32_t control);
	CEfiStatus(C_EFICALL *get_control)(CEfiSerialIOProtocol *this_, uint32_t *control);
	CEfiStatus(C_EFICALL *write)(CEfiSerialIOProtocol *this_, C_EFIUSize *buffer_size,
				    void *buffer);
	CEfiStatus(C_EFICALL *read)(CEfiSerialIOProtocol *this_, C_EFIUSize *buffer_size,
				   void *buffer);
	CEfiSerialIOMode *mode;

	/* 1.1+ */

	CEfiGuid *device_type_guid;
} CEfiSerialIOProtocol;

#ifdef __cplusplus
}
#endif
