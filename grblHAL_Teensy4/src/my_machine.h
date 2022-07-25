/*
  my_machine.h - configuration for IMXRT1062 processor (on Teensy 4.x board)

  Part of grblHAL

  Copyright (c) 2020-2022 Terje Io

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

// BOARD_T40X101 and BOARD_T41U5XBB by Phil Barrett: https://github.com/phil-barrett/grblHAL-teensy-4.x

// NOTE: Only one board may be enabled!
// If none is enabled pin mappings from generic_map.h will be used
//#define BOARD_T40X101
#define BOARD_T41U5XBB
//#define BOARD_T41U5XBB_SS // For a modified T41U5XBB board, allows spindle sync to be enabled.
//#define BOARD_T41BB5X_PRO
//#define BOARD_CNC_BOOSTERPACK
//#define BOARD_GRBLHAL2000
//#define BOARD_MY_MACHINE // Add my_machine_map.h before enabling this!
//#define BAUD_RATE 230400
// Configuration
// Uncomment to enable, for some a value > 1 may be assigned, if so the default value is shown.

/*
              Plugin: | ETHERNET  | SDCARD  | KEYPAD | EEPROM | N_AXIS |
----------------------|-----------|---------|--------|--------|--------|
BOARD_T40X101         | no        | no      | yes    | yes    | max 4  |
BOARD_T41U5XBB        | yes       | yes     | yes    | yes    | max 5  |
BOARD_T41BB5X_PRO     | yes       | yes     | yes    | yes    | max 5  |
BOARD_CNC_BOOSTERPACK | yes       | yes     | yes    | yes    | max 3  |
BOARD_GRBLHAL2000     | yes       | yes     | yes    | yes    | max 5  |

- Teensy 4.1 only
- External magjack.
- EEPROM is optional and must be added to the board.

N_AXIS has a default value of 3, edit grbl\config.h to increase.
*/

#define USB_SERIAL_CDC      2 // 1 for Arduino class library and 2 for PJRC C library. Comment out to use UART communication.
//#define SAFETY_DOOR_ENABLE  1 // Enable safety door input.
//#define USB_SERIAL_WAIT     1 // Wait for USB connection before starting grblHAL.
//#define BLUETOOTH_ENABLE    1 // Set to 1 for HC-05 module. Requires and claims one auxillary input pin.
//#define VFD_ENABLE          1 // Set to 1 or 2 for Huanyang VFD spindle. More here https://github.com/grblHAL/Plugins_spindle
//#define MODBUS_ENABLE       1 // Set to 1 for auto direction, 2 for direction signal on auxillary output pin.
//#define WEBUI_ENABLE        1 // Enable ESP3D-WEBUI plugin along with networking and SD card plugins.
//#define WEBUI_INFLASH       1 // Store WebUI files in flash instead of on SD card.
//#define ETHERNET_ENABLE     1 // Ethernet streaming. Enables networking plugin.
#define SDCARD_ENABLE       1   // Run gcode programs from SD card, enables sdcard plugin.
//#define QEI_ENABLE          1 // Enable quadrature encoder interfaces. Max value is 1. Requires encoder plugin.
//#define MPG_ENABLE          1 // Enable MPG interface. Requires serial port and one handshake pin unless
                                // KEYPAD_ENABLE is set to 2 when mode switching is done by the CMD_MPG_MODE_TOGGLE (0x8B)
                                // command character. Set both MPG_ENABLE and KEYPAD_ENABLE to 2 to use a handshake pin anyway.
//#define KEYPAD_ENABLE       1 // Set to 1 for I2C keypad, 2 for other input such as serial data. If KEYPAD_ENABLE is set to 2
                                // and MPG_ENABLE is uncommented then a serial stream is shared with the MPG.
//#define PLASMA_ENABLE       1 // Plasma/THC plugin. To be completed.
//#define MCP3221_ENABLE      1 // Enable analog input via MCP3221 ADC.
//#define PPI_ENABLE          1 // Laser PPI plugin. To be completed.
//#define ODOMETER_ENABLE     1 // Odometer plugin.
//#define OPENPNP_ENABLE      1 // OpenPNP plugin. To be completed.
//#define FANS_ENABLE         1 // Enable fan control via M106/M107. Enables fans plugin.
//#define EEPROM_ENABLE       1 // I2C EEPROM support. Set to 1 for 24LC16 (2K), 3 for 24C32 (4K - 32 byte page) and 2 for other sizes. Enables eeprom plugin.
//#define EEPROM_IS_FRAM      1 // Uncomment when EEPROM is enabled and chip is FRAM, this to remove write delay.
//#define SPINDLE_SYNC_ENABLE 1 // Enable spindle sync support (G33, G76). !! NOTE: Alpha quality - enable only for test or verification.
                                // Currently only available for BOARD_T41BB5X_PRO and BOARD_T41U5XBB_SS.
//#define ESTOP_ENABLE        0 // When enabled only real-time report requests will be executed when the reset pin is asserted.
                                // Note: if left commented out the default setting is determined from COMPATIBILITY_LEVEL.

// If the selected board map supports more than three motors ganging and/or auto-squaring of axes can be enabled here.
//#define X_GANGED            1
//#define X_AUTO_SQUARE       1
//#define Y_GANGED            1
//#define Y_AUTO_SQUARE       1
//#define Z_GANGED            1
//#define Z_AUTO_SQUARE       1

// For ganged axes the limit switch input (if available) can be configured to act as a max travel limit switch.
// NOTE: If board map already has max limit inputs defined this configuration will be ignored.
//#define X_GANGED_LIM_MAX    1
//#define Y_GANGED_LIM_MAX    1
//#define Z_GANGED_LIM_MAX    1
//

#if ETHERNET_ENABLE > 0
#define TELNET_ENABLE           1 // Telnet daemon - requires Ethernet streaming enabled.
#define WEBSOCKET_ENABLE        1 // Websocket daemon - requires Ethernet streaming enabled.
#ifdef SDCARD_ENABLE
//#define FTP_ENABLE              1 // Ftp daemon - requires SD card enabled
//#define HTTP_ENABLE             1 // http daemon - requires SD card enabled.
#endif
// The following symbols have the default values as shown, uncomment and change as needed.
//#define NETWORK_HOSTNAME        "GRBL"
//#define NETWORK_IPMODE          1 // 0 = static, 1 = DHCP, 2 = AutoIP
//#define NETWORK_IP              "192.168.5.1"
//#define NETWORK_GATEWAY         "192.168.5.1"
//#define NETWORK_MASK            "255.255.255.0"
//#define NETWORK_FTP_PORT        21
//#define NETWORK_TELNET_PORT     23
//#define NETWORK_HTTP_PORT       80
#if HTTP_ENABLE
//#define NETWORK_WEBSOCKET_PORT  81
#else
//#define NETWORK_WEBSOCKET_PORT  80
#endif
#endif

