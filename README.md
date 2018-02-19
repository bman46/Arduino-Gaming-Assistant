# GPU-Temp-Monitor
A windows service application that communicates with an arduino and sends temperature information about GPU Temp, Arduino recives data through serial and displays it on a OLED screen.
## Setup:
  #### Arduino:
  - Verify that [MultiLCD Library](https://github.com/stanleyhuangyc/MultiLCD) in installed
  - Upload Arduino TempDisplay.ino file to arduino.
  - Connect I2C OLED display power to corresoponding power connections
  - Connect SCL to A5
  - Connect SDA to A4
  - When powered on/restarted, LCD Should dislay: Starting..
    - if it doesnt, comment the``` LCD_SSD1306 lcd; ``` line and uncomment another one that corresponds to your screen type.
  #### Install on Windows PC:
  - [Download/Install Visual Studio 2017](https://www.visualstudio.com/downloads/)
  - Open ArduinoTemp.sln with Visual Studio
  - Go to Build>Build Solution
  - On the Windows Start menu or Start screen, open the Visual Studio 2017 folder, then run Developer Command Prompt as admin. 
  - Navigate to build folder using pushd (Build Output Directory) 
  - Type in to console:``` installutil ArudinoTemp.exe ```
    -Should say "The transacted install had completed." and "The Commit phase completed successfully."
  - Open services.msc and find ArduinoTemp
  - Start by right clicking on it and click start
  - To set to automatically start on startup, right click and select propertys and change from Manual to Automatic
   #### Uninstall/Update on Windows PC:
  - On the Windows Start menu or Start screen, open the Visual Studio 2017 folder, then run Developer Command Prompt as admin. 
  - Type in to console: ``` installutil /u ArudinoTemp.exe ```
  - Open services.msc and verify ArduinoTemp is no longer there.
  - If updating, follow the install instructions after completing the uninstall.
