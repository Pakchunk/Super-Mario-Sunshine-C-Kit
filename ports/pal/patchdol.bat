C:\devkitPro\devkitPPC\bin\powerpc-eabi-gcc.exe %1 -S -o %~n1.s -O1 -std=c99 -w
C:\devkitPro\devkitPPC\bin\powerpc-eabi-gcc.exe %1 -c -o %~n1.o -O1 -std=c99 -w
if ERRORLEVEL 1 pause
if ERRORLEVEL 1 exit
C:\devkitPro\devkitPPC\bin\powerpc-eabi-ld.exe -Os -T dollinker -T smsFuncs -o obj_%~n1.o %~n1.o -Map %~n1.map
if ERRORLEVEL 1 pause
if ERRORLEVEL 1 exit
C:\devkitPro\devkitPPC\bin\powerpc-eabi-objdump.exe obj_%~n1.o --full-content
if ERRORLEVEL 1 pause
if ERRORLEVEL 1 exit
C:\devkitPro\devkitPPC\bin\powerpc-eabi-objcopy.exe obj_%~n1.o %~n1.bin -O binary -R .eh_frame -R .comment -R .gnu.attributes -g -S
DolInsert.exe %~n1.bin -m %~n1.map -dol ./Start.dol -o %~n1.dol -c OnUpdate:0x8029e070:3 -c OnSetup:0x80291750:0 -c OnDraw2D:0x80138b50:0 -c OnWaterHitsGround:0x80277568:0 -c OnObjectTouchMario:0x801a81b4:3 -c OnAllNPCsUpdate:0x8003e140:0 -c OnSmallEnemyHitMario:0x80065e0c:3 -r EMarioControl:0x8003ff5c -r IsMario:0x80245898 -r EMarioReceiveMessage:0x80039624 -r MarioSendMessage:0x8026b5fc -r EMarioPlayerControl:0x8003febc -c OnMarioIncHP:0x8027ac6c:0x8027ac90:0x8027ad10:0x8027b1a0:0x8027b21c:0x8027b260:0 -c OnMarioDecHP:0x8023a89c:0 -r EMarioDamageExec:0x8003feb8 -r IsMultiplayerMap:0x802a0bd8
pause