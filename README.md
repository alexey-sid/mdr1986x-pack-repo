# Milandr MCU 1986x CMSIS Pack Repository

The repository for [GNU ARM Eclipse CMSIS Packs](http://gnuarmeclipse.github.io/plugins/packs-manager/).<br>
The contained package also compatible with Keil MDK 5.

## Configuration

```
Eclipse Menu → Window → Preferences → C/C++ → Packages → Repositories → Add...
```

```
type: CMSIS Pack
name: Milandr
url : https://github.com/in4lio/mdr1986x-pack-repo/raw/master/Milandr.idx 
```

[The peripherals registers view](http://gnuarmeclipse.github.io/debug/peripheral-registers/)

## Contents

[Milandr 32-bit АRМ Cortex-М microprocessors](http://milandr.ru/en/index.php?mact=Products,cntnt01,default,0&cntnt01hierarchyid=5&cntnt01returnid=141)

- MDR1986BE91 (MDR32F9Q1)
- MDR1986BE92 (MDR32F9Q2)
- MDR1986BE93 (MDR32F9Q3)
- MDR1986BE1T
- MDR1986BE3T
- MDR1986BE4

## Source

[Milandr MCU 1986x Standard Peripherals Library](https://github.com/eldarkg/emdr1986x-std-per-lib)<br>
[Milandr MCU 1986x Standard Peripherals Library Documentation](https://github.com/eldarkg/emdr1986x-std-per-lib-doc)

Format: MDK5 Software Pack

```
Structure of Milandr.MDR1986BExx.0.0.0.pack (zipped)

  Config\                         <--  emdr1986x-std-per-lib

  Example_Projects\               <--  emdr1986x-std-per-lib-doc
  Examples\                       <--  ...
  Flash\                          <--  ...
  IDE\
    keil\                         <--  ...
                                   X     iar_arm\
                                   X     Phyton_CodeMaster\
	
  Libraries\                      
    CMSIS\                        <--  emdr1986x-std-per-lib
    MDR32F9Qx_StdPeriph_Driver\   <--  ...
    MDR1986BE4_StdPeriph_Driver\  <--  ...
	
  Milandr.MDR1986BExx.pdsc        <--  mdr1986x-pack-repo
```
