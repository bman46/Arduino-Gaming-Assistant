# Arduino Gaming Assistant:
[![Build status](https://ci.appveyor.com/api/projects/status/1mwgon2hh7qqcg89?svg=true)](https://ci.appveyor.com/project/bman46/gpu-arduino-temp-monitor)

A windows service application that communicates with an arduino and sends temperature information about GPU Temp and CS:GO kills, Arduino recives data through serial and displays it on a OLED screen. This was formerly known as ArduinoTemp.
## Setup:
  #### Arduino:
  - Verify that [MultiLCD Library](https://github.com/stanleyhuangyc/MultiLCD) is installed
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
  - Type in to console:``` installutil ArduinoTemp.exe ```
    -Should say "The transacted install had completed." and "The Commit phase completed successfully."
  - Open services.msc and find ArduinoTemp
  - Start by right clicking on it and click start
  - To set to automatically start on startup, right click and select propertys and change from Manual to Automatic
   #### Uninstall/Update on Windows PC:
  - On the Windows Start menu or Start screen, open the Visual Studio 2017 folder, then run Developer Command Prompt as admin. 
  - Type in to console: ``` installutil /u ArduinoTemp.exe ```
  - Open services.msc and verify ArduinoTemp is no longer there.
  - If updating, follow the install instructions after completing the uninstall.
  #### Add .cfg Files to CS:GO:
  - Download the gamestate_integration_ArduinoTemp.cfg
  - Place the file in the CS:GO cfg folder:
    - for example: ```D:\Steam\steamapps\common\Counter-Strike Global Offensive\csgo\cfg\```
  - CS:GO Support thanks to the [CSGSI Library](https://github.com/rakijah/CSGSI)
  - ##### Note: This should not get you VAC banned as it is supported by valve. However, dont go messing around in other folders unless you know what your doing. [Read More Here](https://developer.valvesoftware.com/wiki/Counter-Strike:_Global_Offensive_Game_State_Integration)
