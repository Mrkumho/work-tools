
@echo off

set TSHARK="C:\Program Files\Wireshark\tshark.exe"

set INPUT="%~dpnx1"
set OUTPUT=%~dpnx1_input.txt

%TSHARK% -r %INPUT% > %OUTPUT% -x

@rem pause
