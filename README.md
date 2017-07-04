# Korbo
Open source cross platform Minecraft mod manager

## Building
### Windows
 * Base
   * [MSYS2 20161025](http://repo.msys2.org/distrib/x86_64/msys2-x86_64-20161025.exe) or higher
   * ```pacman -Syyu``` do that till no more updates
   * ```pacman -S mingw-w64-x86_64-gtk3```
   * ```pacman -S mingw-w64-x86_64-gtkmm3```
   * ```pacman -S mingw-w64-x86_64-toolchain base-devel```
   * ```pacman -S mingw-w64-x86_64-cmake```
   * ```git clone https://github.com/Txuritan/korbo.git```
   * ```cd korbo && mkdir build && cd build```
   * ```cmake .. -G "MSYS Makefiles"```
   * ```cmake --build . --config Release```
   * ```make```