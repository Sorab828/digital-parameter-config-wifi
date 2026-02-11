# Digital Parameter Config - WiFi (SSD1306 OLED example)

Short README documenting how to open and build this PlatformIO project in CLion, the code behavior, libraries and hardware wiring (SSD1306 128x64 I2C OLED), and author/setup information.

---

## Checklist (what this README covers)
- Using CLion to open and build the project
- Where to find and record your IDE version
- Short description of the code in `src/main.cpp`
- Libraries used
- PlatformIO / project dependencies
- OLED components and wiring (I2C)
- Author info placeholders
- Software and hardware requirements

---

## Quick facts (inferred from project files)
- PlatformIO environment: `env:uno_r4_wifi` (see `platformio.ini`)
- Platform: `renesas-ra`
- Board: `uno_r4_wifi`
- Framework: `arduino`
- Libraries (declared in `platformio.ini`):
  - `adafruit/Adafruit SSD1306@^2.5.16`
  - `adafruit/Adafruit GFX Library@^1.12.4`
- I2C OLED address used in code: `0x3C`
- Serial monitor settings in `platformio.ini`: port `COM13`, baud `9600`

---

## Using CLion
1. Install CLion and the PlatformIO plugin (or use PlatformIO IDE in Visual Studio Code).
2. Open CLion, choose "Open" and select the project folder (this repository root).
3. If you haven't installed PlatformIO plugin in CLion:
   - Go to `File > Settings > Plugins` and search for "PlatformIO". Install and restart CLion.
4. PlatformIO will manage the toolchain. If the plugin asks to install PlatformIO Core, accept it.
5. Build and upload from the PlatformIO toolbar inside CLion or use the PlatformIO CLI (instructions below).

Notes:
- If the PlatformIO plugin is unavailable for your CLion version, use the PlatformIO Core CLI (`pip install platformio`) and run it from a terminal.

How to find your CLion version (fill this in):
- In CLion: `Help > About` (copy the version string here).

---

## Code (what `src/main.cpp` does)
- The sketch initializes Serial at 9600 baud.
- Initializes an Adafruit SSD1306 128x64 OLED via I2C (address `0x3C`). The instance is created with no dedicated RST pin.
- On setup it calls `display.begin(...)` and, on success, clears the display and prints three lines: `Arduino`, `oled`, `Hello`.
- `loop()` is empty - the sketch currently displays the static text only.

File to inspect: `src/main.cpp` (look for `Adafruit_SSD1306 display(...)` and `display.begin(...)`).

---

## Libraries
The project depends on the following Arduino libraries (declared in `platformio.ini`):
- Adafruit SSD1306 (OLED driver) — `adafruit/Adafruit SSD1306@^2.5.16`
- Adafruit GFX Library — `adafruit/Adafruit GFX Library@^1.12.4`

PlatformIO will download and install these automatically when building.

---

## Project dependencies (PlatformIO)
Relevant entries from `platformio.ini`:

- environment: `env:uno_r4_wifi`
- `platform = renesas-ra`
- `board = uno_r4_wifi`
- `framework = arduino`
- `lib_deps` contains the Adafruit libraries listed above
- `monitor_speed = 9600`
- `monitor_port = COM13`
- `upload_port = COM13`

If you need a different serial port or board, update `platformio.ini` accordingly.

---

## Hardware: OLED (SSD1306) and components
Typical components used in this project:
- SSD1306 I2C OLED module (128x64)
- Microcontroller board: Arduino UNO R4 WiFi (or compatible renamed board in PlatformIO)
- USB cable, jumper wires, breadboard (optional)

Wiring (I2C):
- OLED VCC -> 3.3V (or 5V if your module supports it)  
  *Check your module's labeling — many SSD1306 modules accept 3.3–5V, but verify before powering.*
- OLED GND -> GND
- OLED SDA -> SDA (on UNO R4 the SDA pin)
- OLED SCL -> SCL (on UNO R4 the SCL pin)
- OLED RST -> (optional) if your module has a reset pin and you want to use it. The code passes `rstpin: -1` (no reset pin).

ASCII wiring example:

Microcontroller            SSD1306 OLED
--------------             -------------
3.3V or 5V   ----------->  VCC
GND          ----------->  GND
SDA (I2C)    ----------->  SDA
SCL (I2C)    ----------->  SCL
RST (opt)    ----------->  RST (if used)

I2C address: typically `0x3C`. If your display doesn't appear, scan the bus with an I2C scanner sketch to confirm the address.

---

## Build & Upload (examples)
From a terminal with PlatformIO Core installed you can run:

- Build the default environment:

    pio run -e uno_r4_wifi

- Upload to the board (using the environment name):

    pio run -t upload -e uno_r4_wifi

- Monitor serial output (replace COM13 if different):

    pio device monitor -p COM13 -b 9600

Using CLion + PlatformIO plugin: use the PlatformIO toolbar (Build / Upload / Monitor) after opening the project.

---

## Software & hardware requirements
- OS: Windows, macOS, or Linux (this repo was prepared on Windows)
- CLion (add your version here)
- PlatformIO Core (CLI) or PlatformIO plugin for CLion (add your PlatformIO Core version here)
- Python (if using PlatformIO Core via pip)
- Arduino Board: Arduino UNO R4 WiFi (PlatformIO board id: `uno_r4_wifi`)
- SSD1306 I2C OLED module (128x64)
- USB cable, jumper wires, breadboard

---

## Troubleshooting
- SSD1306 allocation failed: check I2C wiring and address. Use an I2C scanner to find the device address.
- Blank screen but code uploads: try power (3.3V vs 5V) and contrast; consult module datasheet.
- PlatformIO can't find board: ensure PlatformIO has downloaded the `renesas-ra` platform and that `board = uno_r4_wifi` is valid.

---

## Author
- Name: Your Name Here
- Email: your.email@example.com
- GitHub: https://github.com/yourusername

Replace the placeholders above with your real author information.

---

## Next steps / Enhancements
- Add an I2C scanner utility to `tools/` or `examples/` to help debug address issues.
- Extend `loop()` to update the display dynamically (show WiFi status, parameters, etc.).
- Add a small wiring photo or schematic in `docs/` for visual reference.

---

## License
Specify a license for the project (e.g., MIT). Add a `LICENSE` file if you choose one.



*README generated automatically; edit to add your specific CLion and PlatformIO versions and author contact.*
