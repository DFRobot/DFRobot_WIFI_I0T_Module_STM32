SET PATH=C:\Keil_v5\ARM\ARMCC\bin\;C:\Program Files (x86)\STMicroelectronics\st_toolset\asm;C:\Python38\Scripts\;C:\Python38\;C:\Program Files\Python36\Scripts\;C:\Program Files\Python36\;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Windows\System32\OpenSSH\;C:\Program Files\Git\cmd;C:\Program Files\nodejs\;C:\ProgramData\chocolatey\bin;C:\Users\Administrator.DESKTOP-LDL2QMG\AppData\Local\Mu\bin;C:\Users\Administrator.DESKTOP-LDL2QMG\AppData\Local\Mu\bin;C:\Users\Administrator.DESKTOP-LDL2QMG\AppData\Local\Mu\bin;C:\Users\Administrator.DESKTOP-LDL2QMG\AppData\Local\Mu\bin;C:\Users\Administrator.DESKTOP-LDL2QMG\AppData\Local\Mu\bin;C:\Users\Administrator.DESKTOP-LDL2QMG\AppData\Local\Mu\bin;C:\Users\Administrator.DESKTOP-LDL2QMG\AppData\Local\Mu\bin;C:\Users\Administrator.DESKTOP-LDL2QMG\AppData\Local\Mu\bin;C:\Users\Administrator.DESKTOP-LDL2QMG\AppData\Local\Mu\bin;C:\Users\Administrator.DESKTOP-LDL2QMG\AppData\Local\Mu\bin;C:\Users\Administrator.DESKTOP-LDL2QMG\AppData\Local\Mu\bin;C:\Users\Administrator.DESKTOP-LDL2QMG\AppData\Local\Mu\bin;C:\Program Files\Python36;C:\Users\Administrator.DESKTOP-LDL2QMG\AppData\Local\Microsoft\WindowsApps;F:\PyCharm Community Edition 2019.3.1\bin;F:\Microsoft VS Code\bin;C:\ProgramData\Anaconda3;C:\Users\Administrator.DESKTOP-LDL2QMG\AppData\Roaming\npm;D:\MinGW\bin;
SET CPU_TYPE=STM32F103ZE
SET CPU_VENDOR=STMicroelectronics
SET UV2_TARGET=Target 1
SET CPU_CLOCK=0x044AA200
"C:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via ".\obj\main.__i"
"C:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via ".\obj\stm32f10x_it.__i"
"C:\Keil_v5\ARM\ARMCC\bin\ArmAsm" --Via ".\obj\startup_stm32f10x_hd._ia"
"C:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via ".\obj\stm32f10x_gpio.__i"
"C:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via ".\obj\stm32f10x_rcc.__i"
"C:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via ".\obj\stm32f10x_usart.__i"
"C:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via ".\obj\stm32f10x_tim.__i"
"C:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via ".\obj\misc.__i"
"C:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via ".\obj\stm32f10x_exti.__i"
"C:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via ".\obj\system_stm32f10x.__i"
"C:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via ".\obj\core_cm3.__i"
"C:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via ".\obj\led.__i"
"C:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via ".\obj\dfrobot_wifi_iot.__i"
"C:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via ".\obj\system.__i"
"C:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via ".\obj\systick.__i"
"C:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via ".\obj\usart.__i"
"C:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via ".\obj\dfrobot_queue.__i"
"C:\Keil_v5\ARM\ARMCC\bin\ArmLink" --Via ".\Obj\Template.lnp"
"C:\Keil_v5\ARM\ARMCC\bin\fromelf.exe" ".\Obj\Template.axf" --i32combined --output ".\Obj\Template.hex"
