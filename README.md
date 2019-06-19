#####################################################
#####   HOW TO LAUNCH BOMBERMAN (Indie Studio)  #####
#####################################################

/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\
/\  WINDOWS (and Linux if you can't compile with the instructions above)  /\
/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\

Change the paths on the CMakeLists.txt (l. 13/14)

If you don't have the libraries, you can find both
of them at this link :  bit.ly/IndieLibraries

Or you can download them on the Official Website

Vesion 2.4.2 for SFML
Version 1.8.4 for Irrlicht

/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\
/\            WINDOWS ONLY            /\
/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\

1.  Open the project on Visual Studio 2017 (Right click -> Open with Visual Studio)
On the solution explorator :
2.  Right click on the project name (OOP_indie_strudio_2018)
3.  Then "Open Developer Command Prompt"
4.  Enter the command "cmake ." (if it don't work, try "cmake CMakeLists.txt")
5.  If no error occurs, use the command "cmake --build ." (in case of error, restart from the point 4)
6.  You're game has compile, enjoy it !

/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\
/\          UNIX SYSTEM ONLY          /\
/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\

1.  Open a terminal on the root path of your project
2.  Enter the command "cmake ." (if it don't work, try "cmake CMakeLists.txt")
3.  If it still don't work, follow the instructions line 9 of the README
4.  use the command "make" at the root of the repository
5.  You're game has compile, enjoy it ! (using the "./bomberman" command or with your GUI Environment)

If you can't compile, run the two following commands and restart from the begining (for Fedora) :
-   "sudo dnf install sfml-devel"
-   "sudo dnf install irrlicht-devel"

#####################################################
#####            PROGRAM PURPOSE BY:            #####
#####       ABRANEL Billy                       #####
#####       BOYER Sandjey                       #####
#####       DEMOL Axel                          #####
#####       FONTAINE Donovan                    #####
#####       OUSSENI Ambdouroihaman              #####
#####       POTHIN Loïc                         #####
#####################################################

3D Assets from : https://github.com/Romain-P/bomberman
Block Texture from : purbdcraft.net
