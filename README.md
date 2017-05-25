# Milandr MCU 1986x CMSIS Pack Repository

The unofficial repository for [GNU ARM Eclipse](http://gnuarmeclipse.github.io/plugins/packs-manager/).<br>
The package that is maintained here – [`Milandr.MDR1986BExx.1.4.2.pack`](https://raw.githubusercontent.com/in4lio/mdr1986x-pack-repo/master/Milandr.MDR1986BExx.1.4.2.pack) also compatible with Keil MDK 5.

#### How to install the package (Eclipse)

- [Add](http://gnuarmeclipse.github.io/plugins/packs-manager/#configuration) Milandr MCU repository,
specifying the path to
the [`index.pidx`](https://raw.githubusercontent.com/in4lio/mdr1986x-pack-repo/master/index.pidx) file:
```
Eclipse Menu → Window → Preferences → C/C++ → Packages → Repositories → Add...

Type       CMSIS Pack
Name       Milandr
URL        https://raw.githubusercontent.com/in4lio/mdr1986x-pack-repo/master/index.pidx
```
  For old versions of Packs Manager you should use
  [`index.idx`](https://raw.githubusercontent.com/in4lio/mdr1986x-pack-repo/master/index.idx) file.

- [Open](http://gnuarmeclipse.github.io/plugins/packs-manager/#the-packs-perspective) the Packs perspective
and [install](http://gnuarmeclipse.github.io/plugins/packs-manager/#pack-install) the `MDR1986BExx` package
from the `Milandr` group.

- The path to packages is defined in `packs_path` macro, but for the plug-in version that I use,
this macro is not visible from tools configurations. Therefore, you may need to set the `packs_path` macro manually:
```
Eclipse Menu → Window → Preferences → Run/Debug → String Substitution → New...

Name       packs_path
Value      <path to packages>
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

- Clone this repository and its submodules, if they were not cloned yet:

```
git clone https://github.com/in4lio/mdr1986x-pack-repo.git
cd mdr1986x-pack-repo
git submodule update --init --recursive
```

- Update this repository and submodules, if they were not cloned just now:

```
cd mdr1986x-pack-repo
git pull origin master
git submodule foreach git pull origin master
```

- Run the build script with Python 2:

```
python .\build.py
```
