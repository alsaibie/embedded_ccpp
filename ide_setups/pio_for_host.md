@def title = "Compiling C/C++ for Host with PlatformIO"
@def hascode = true

# Compiling C/C++ for Host with PlatformIO

The PlatformIO extension is targeted for building and flashing code into microcontrollers. It can also setup a compiler for host PC (Windows). This tutorial shows you how to do that.

## Prerequisites
Make sure you have installed the latest [VSCode](https://code.visualstudio.com/Download). In addition to the following extensions
- PlatformIO
- Code Runner

## Installing MinGW
MinGW is a Windows port of the GNU Compiler Collection (GCC). GCC comes with compilers for a wide range of systems including many microcontrollers. You can download and install it separately from [MinGW](https://sourceforge.net/projects/mingw/) download site. But we can install a slimmer version using PlatformIO. 

Start VSCode, and click on the Alien icon on the left for PlatformIO tab, and click on PlatformIO Core CLI (Platform IO Command Line Interface). 
 
~~~
<center><img src="/assets/ide_setups/pio_for_host/media/PIOTab.jpg" style="max-width:420px"></center>~~~

A new terminal window will open within VSCode. Type `pio -h` and help commands for the pio cli will be printed. 

~~~
<center><img src="/assets/ide_setups/pio_for_host/media/pio_help.jpg" style="max-width:620px"></center>~~~

We want to install the required tools for compiling to Windows. 

Type in the following command in the PIO CLI
```
>pio platform install windows_x86
```
This will install the required packages to compile C/C++ for you host PC (Windows). It will install the minGW binaries in the following directory. 

`{HOME}\.platformio\packages\toolchain-gccmingw32\bin`


Where `{HOME}` is where your user directory is, for standard installations of PlatformIO.

~~~
<center><img src="/assets/ide_setups/pio_for_host/media/mingw_bin_dir.jpg" style="max-width:720px"></center>~~~

Now we want to add this MinGW binary directory to the environment path, so when we call the C++ compiler command `g++` the system knows where it exists. 

Click the start menu and search for and open "Edit System Environment Variables". Then click on "Environment Variables..."
~~~
<center><img src="/assets/ide_setups/pio_for_host/media/edit_environ_variables.jpg" style="max-width:720px"></center>~~~

Under user variables. Go to **Path** variables and click edit. 
~~~
<center><img src="/assets/ide_setups/pio_for_host/media/env_user_variables.jpg" style="max-width:720px"></center>~~~ 

Then click **New** to add a new directory to path. The directories under Path are where the system searches for any command you try to execute in the terminal, including the terminal inside VSCode. 
~~~
<center><img src="/assets/ide_setups/pio_for_host/media/Path_edit.jpg" style="max-width:720px"></center>~~~ 

And past the bin directory for the MinGW tools. If you've installed MinGW separately, you can follow the same steps to add the bin directory to the path. 

Save and close the Environment Variables editing window. Then make sure you close all instances of VSCode and restart it. 

After you start VSCode, open a terminal tab. You can press `ctrl+J` to open the existing terminal tab, or start a new terminal from the top menu in VSCode. 

To verify that VSCode can reach the g++ compiler, type
```
>g++ -v
```
And you should get the version of g++ installed. 

~~~
<center><img src="/assets/ide_setups/pio_for_host/media/gppversion.jpg" style="max-width:780px"></center>~~~ 

You could verify where it found the binary by typing the following
```
>where g++
```

## Creating a new C/C++ project

There are several ways to create a new C/C++ project, we will present two. 

### PlatformIO Project

### Bare VSCode



