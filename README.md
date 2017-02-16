# Milandr MCU 1986x CMSIS Pack Repository

The unofficial repository for [GNU ARM Eclipse](http://gnuarmeclipse.github.io/plugins/packs-manager/).<br>
The contained package also compatible with Keil MDK 5.

#### How to install the package (Eclipse)

- [Add](http://gnuarmeclipse.github.io/plugins/packs-manager/#configuration) Milandr MCU repository:

```
Eclipse Menu → Window → Preferences → C/C++ → Packages → Repositories → Add...

type: CMSIS Pack
name: Milandr
url : https://github.com/in4lio/mdr1986x-pack-repo/raw/master/Milandr.idx
```

- [Open](http://gnuarmeclipse.github.io/plugins/packs-manager/#the-packs-perspective) Packs perspective
and [install](http://gnuarmeclipse.github.io/plugins/packs-manager/#pack-install) `Milandr.MDR1986BExx` package.

#### How to examine/modify the peripheral registers (Eclipse)

[The peripherals registers view](http://gnuarmeclipse.github.io/debug/peripheral-registers/)

#### Supported MCUs

[Milandr 32-bit АRМ Cortex-М microcontrollers](http://milandr.ru/en/index.php?mact=Products,cntnt01,default,0&cntnt01hierarchyid=5&cntnt01returnid=141)

- 1986BE9x (MDR32F9Qx)
- 1986BE1 (MDR32F1)
- 1986BE3
- 1986BE4

#### The package source list

- [Milandr MCU 1986x Standard Peripherals Library](https://github.com/eldarkg/emdr1986x-std-per-lib)
- [Milandr MCU 1986x Standard Peripherals Library Documentation](https://github.com/eldarkg/emdr1986x-std-per-lib-doc)
- [Milandr MCU 1986BExx CMSIS Driver](https://github.com/in4lio/mdr1986x-pack-repo/tree/master/source/CMSIS_Driver)
- [Milandr MCU 1986x flashing with J-Link](https://github.com/in4lio/mdr1986x-JFlash)
- [Example GNU ARM Eclipse Projects](https://github.com/in4lio/mdr1986x-pack-repo/tree/master/source/Example_Projects_Eclipse)

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
