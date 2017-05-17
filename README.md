# Milandr MCU 1986x CMSIS Pack Repository

The unofficial repository for [GNU ARM Eclipse](http://gnuarmeclipse.github.io/plugins/packs-manager/).<br>
The contained package also compatible with Keil MDK 5.

#### How to install the package (Eclipse)

- [Add](http://gnuarmeclipse.github.io/plugins/packs-manager/#configuration) Milandr MCU repository:
```
Eclipse Menu → Window → Preferences → C/C++ → Packages → Repositories → Add...

Type: CMSIS Pack
Name: Milandr
URL:  https://raw.githubusercontent.com/in4lio/mdr1986x-pack-repo/master/index.idx
```

- [Open](http://gnuarmeclipse.github.io/plugins/packs-manager/#the-packs-perspective) Packs perspective
and [install](http://gnuarmeclipse.github.io/plugins/packs-manager/#pack-install) `Milandr.MDR1986BExx` package.

- The path to packages is defined in `packs_path` macro, but for the plug-in version that I use,
this macro isn't visible from tools configurations. Therefore, you may need to set `packs_path` macro manually,
here:
```
Eclipse Menu → Window → Preferences → Run/Debug → String Substitution → New...

variable: packs_path
value: <path to packages>
```

#### How to examine/modify the peripheral registers (Eclipse)

[The peripherals registers view](http://gnuarmeclipse.github.io/debug/peripheral-registers/)

#### Supported MCUs

[Milandr 32-bit АRМ Cortex-М microcontrollers](http://ic.milandr.ru/products/mikrokontrollery_i_protsessory/32_razryadnye_mikrokontrollery/)

- 1986BE9x (MDR32F9Qx)
- 1986BE1 (MDR32F1)
- 1986BE3
- 1986BE4

#### The package source list

- [Milandr MCU 1986x Standard Peripherals Library](https://github.com/eldarkg/emdr1986x-std-per-lib)
- [Milandr MCU 1986x Standard Peripherals Library Documentation](https://github.com/eldarkg/emdr1986x-std-per-lib-doc)
- [Milandr MCU 1986BExx CMSIS Driver](https://github.com/in4lio/mdr1986x-pack-repo/tree/master/source/CMSIS_Driver)
- [Milandr MCU 1986x flashing with J-Link](https://github.com/in4lio/mdr1986x-JFlash)
- [Milandr MCU 1986BE3T UDP Library](https://github.com/in4lio/mdr1986x-pack-repo/tree/master/source/Example_Projects_Eclipse/1986BE3_UDP)
- [Example Projects for GNU ARM Eclipse](https://github.com/in4lio/mdr1986x-pack-repo/tree/master/source/Example_Projects_Eclipse)

#### How to rebuild the package

- Clone this repository and its submodules, if weren't cloned yet:

```
git clone https://github.com/in4lio/mdr1986x-pack-repo.git
cd mdr1986x-pack-repo
git submodule update --init --recursive
```

- Update this repository and submodules, if weren't cloned just now:

```
cd mdr1986x-pack-repo
git pull origin master
git submodule foreach git pull origin master
```

- Run the build script with Python 2:

```
python .\build.py
```
