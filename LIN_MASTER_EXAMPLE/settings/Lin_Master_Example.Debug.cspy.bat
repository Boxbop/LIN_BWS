@REM This batch file has been generated by the IAR Embedded Workbench
@REM C-SPY Debugger, as an aid to preparing a command line for running
@REM the cspybat command line utility using the appropriate settings.
@REM
@REM Note that this file is generated every time a new debug session
@REM is initialized, so you may want to move or rename the file before
@REM making changes.
@REM
@REM You can launch cspybat by typing the name of this batch file followed
@REM by the name of the debug file (usually an ELF/DWARF or UBROF file).
@REM
@REM Read about available command line parameters in the C-SPY Debugging
@REM Guide. Hints about additional command line parameters that may be
@REM useful in specific cases:
@REM   --download_only   Downloads a code image without starting a debug
@REM                     session afterwards.
@REM   --silent          Omits the sign-on message.
@REM   --timeout         Limits the maximum allowed execution time.
@REM 


"C:\Program Files (x86)\IAR Systems\Embedded Workbench 7.0\common\bin\cspybat" "C:\Program Files (x86)\IAR Systems\Embedded Workbench 7.0\avr\bin\avrproc.dll" "C:\Program Files (x86)\IAR Systems\Embedded Workbench 7.0\avr\bin\avrJtagIce.dll"  %1 --plugin "C:\Program Files (x86)\IAR Systems\Embedded Workbench 7.0\avr\bin\avrlibsupportbat.dll" --backend -B "--cpu=can128" "--enhanced_core" "-p" "C:\Program Files (x86)\IAR Systems\Embedded Workbench 7.0\avr\Config\iocan128.ddf" "--eeprom_size" "4096" "-d" "jtagIce" "--drv_communication=COM4" "--jtagice_clock=100000" "--jtagice_leave_timers_running" "--drv_set_putchar_breakpoint" "--drv_set_getchar_breakpoint" 


