Music Player Linux
================

Music Player Linux- simple, foobar2000-like music player.

BUILDING
================

Tested on: QtCreator, Qt 5.3, BASS library 2.4.10, Taglib 1.9.1, GCC 4.8

Instructions:
1. Open .pro file in QtCreator
2. Build project using GCC 4.8
3. Download archive with Linux or Windows version of 
	BASS library from http://www.un4seen.com/
4. Extract archive
5. Copy bass.dll (32-bit version is in the top
	folder of the archive) to build folder
	(where executable file is located)
6. Get Taglib either from http://taglib.github.io/ or by
    installing packages in your Linux distribution.
7. Modify TAGLIB_PATH and TAGLIB_BIN_PATH variables in .pro file
6. Build and run application from QtCreator
