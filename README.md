# Milandr MCU 1986x CMSIS Pack Repository

The unofficial repository for [GNU ARM Eclipse CMSIS Packs](http://gnuarmeclipse.github.io/plugins/packs-manager/).<br>
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

[Milandr 32-bit АRМ Cortex-М microcontrollers](http://milandr.ru/en/index.php?mact=Products,cntnt01,default,0&cntnt01hierarchyid=5&cntnt01returnid=141)

- MDR1986BE91 (MDR32F9Q1)
- MDR1986BE92 (MDR32F9Q2)
- MDR1986BE93 (MDR32F9Q3)
- MDR1986BE1T
- MDR1986BE3T
- MDR1986BE4

## Source list

- [Milandr MCU 1986x Standard Peripherals Library](https://github.com/eldarkg/emdr1986x-std-per-lib)
- [Milandr MCU 1986x Standard Peripherals Library Documentation](https://github.com/eldarkg/emdr1986x-std-per-lib-doc)
- [Milandr MCU 1986BExx CMSIS Driver](https://github.com/in4lio/mdr1986x-pack-repo/tree/master/source/CMSIS_Driver)
- [Milandr MCU 1986x flashing with J-Link](https://github.com/in4lio/mdr1986x-JFlash)

## How to rebuild package

Just run `build.py` script.
