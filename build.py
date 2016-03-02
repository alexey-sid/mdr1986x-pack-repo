r"""
build.py -- Build Milandr MCU 1986x CMSIS Package
"""

import os
import glob
import stat
import shutil
from distutils.dir_util import copy_tree
from distutils.file_util import copy_file

SOURCE_PATH = './source/'
BUILD_PATH = './build/'
BUILD_BAK_PATH = './build.bak/'

copylist = (
    ( 'emdr1986x-std-per-lib/CMSIS/'                      , 'Libraries/CMSIS/' ),
    ( 'emdr1986x-std-per-lib/MDR32F9Qx_StdPeriph_Driver/' , 'Libraries/MDR32F9Qx_StdPeriph_Driver/' ),
    ( 'emdr1986x-std-per-lib/MDR1986BE4_StdPeriph_Driver/', 'Libraries/MDR1986BE4_StdPeriph_Driver/' ),
    ( 'emdr1986x-std-per-lib/README.md'                   , 'Libraries/' ),
    ( 'emdr1986x-std-per-lib/Config/'                     , 'Config/' ),

    ( 'diff/emdr1986x-std-per-lib/'                       , 'Libraries/' ),

    ( 'emdr1986x-std-per-lib-doc/Example_Projects/'       , 'Example_Projects/' ),
    ( 'emdr1986x-std-per-lib-doc/Examples/'               , 'Examples/' ),
    ( 'emdr1986x-std-per-lib-doc/Flash/'                  , 'Flash/' ),
    ( 'emdr1986x-std-per-lib-doc/IDE/keil/'               , 'IDE/keil/' ),

    ( 'CMSIS_Driver/'                                     , 'CMSIS_Driver/' ),

    ( '../Milandr.MDR1986BExx.pdsc'                       , '' ),
)

def on_rm_error( func, path, exc_info ):
    os.chmod( path, stat.S_IWRITE )

if os.path.exists( BUILD_PATH ):
    print 'Backup', BUILD_PATH
    if os.path.exists( BUILD_BAK_PATH ):
        shutil.rmtree( BUILD_BAK_PATH, onerror = on_rm_error )
    os.rename( BUILD_PATH, BUILD_BAK_PATH )

for op in copylist:
    p = os.path.join( BUILD_PATH, op[ 1 ])
    if not os.path.exists( p ):
        os.makedirs( p )
    print 'Copy to', p
    n = 0
    for f in glob.glob( os.path.join( SOURCE_PATH, op[ 0 ])):
        print f
        n += 1
        if os.path.isdir( f ):
            copy_tree( f, p )
        else:
            copy_file( f, p )

    if n == 0:
        print '*** ERROR *** Nothing was copied here.'
        print

#TODO: get version
#TODO: zip
