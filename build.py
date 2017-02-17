r"""
build.py -- Build Milandr MCU 1986x CMSIS Package
"""

import os
import glob
import stat
import shutil
import json
import time
from distutils.dir_util import copy_tree
from distutils.dir_util import remove_tree
from distutils.file_util import copy_file
from distutils.file_util import move_file
from xml.dom import minidom

SOURCE_DIR = './source/'
BUILD_DIR  = './build/'
PDSC_FILE  = './Milandr.MDR1986BExx.pdsc'
PACK_TEMPL = './Milandr.MDR1986BExx.%s.pack'
IDX_FILE   = './Milandr.idx'

copylist = (
    ( 'emdr1986x-std-per-lib/CMSIS/'                      , 'Libraries/CMSIS/' ),
    ( 'emdr1986x-std-per-lib/MDR32F9Qx_StdPeriph_Driver/' , 'Libraries/MDR32F9Qx_StdPeriph_Driver/' ),
    ( 'emdr1986x-std-per-lib/MDR1986BE4_StdPeriph_Driver/', 'Libraries/MDR1986BE4_StdPeriph_Driver/' ),
    ( 'emdr1986x-std-per-lib/README.md'                   , 'Libraries/' ),
    ( 'emdr1986x-std-per-lib/Config/'                     , 'Config/' ),

#    ( 'diff/emdr1986x-std-per-lib/'                       , 'Libraries/' ),

    ( 'emdr1986x-std-per-lib-doc/Example_Projects/'       , 'Example_Projects/' ),
    ( 'emdr1986x-std-per-lib-doc/Examples/'               , 'Examples/' ),
    ( 'emdr1986x-std-per-lib-doc/Flash/'                  , 'Flash/' ),
    ( 'emdr1986x-std-per-lib-doc/IDE/keil/'               , 'IDE/keil/' ),

    ( 'CMSIS_Driver/'                                     , 'CMSIS_Driver/' ),
    ( 'mdr1986x-JFlash/'                                  , 'JFlash/' ),
    ( 'Example_Projects_Eclipse/'                         , 'Example_Projects_Eclipse/' ),
)

#  @ - remove according to the list of files
dellist = (
    'IDE/keil/SFD/MDR1901VC1T.SFR',
    'IDE/keil/SFD/MDR1901VC1T.svd',
    'JFlash/.git',
    '@Example_Projects_Eclipse/mdr1986x_RTT/.gitignore',
)

print 'Clean build'
if os.path.exists( BUILD_DIR ):
    remove_tree( BUILD_DIR )
    time.sleep( 0.5 )

os.makedirs( BUILD_DIR )

ver = minidom.parse( PDSC_FILE ).getElementsByTagName( 'release' )[ 0 ].attributes[ 'version' ].value
print 'Version', ver

pack = PACK_TEMPL % ver

if os.path.exists( pack ):
    print 'Backup', pack
    bak = pack + '.bak'
    if os.path.exists( bak ):
        os.remove( bak )
    move_file( pack, bak )

print 'Copy'
print ' ', PDSC_FILE
copy_file( PDSC_FILE, BUILD_DIR )

for op in copylist:
    p = os.path.join( BUILD_DIR, op[ 1 ])
    if not os.path.exists( p ):
        os.makedirs( p )
    print 'Copy to', p
    n = 0
    for f in glob.glob( os.path.join( SOURCE_DIR, op[ 0 ])):
        print ' ', f
        n += 1
        if os.path.isdir( f ):
            copy_tree( f, p )
        else:
            copy_file( f, p )

    if n == 0:
        print '*** ERROR *** Nothing was copied here.'
        print

print 'Remove'
for op in dellist:
    if op.startswith( '@' ):
        f = os.path.join( BUILD_DIR, op[ 1: ])
        d = os.path.dirname( f )
        try:
            sublist = [ os.path.join( d, x[ 1: ]) if x.startswith( '/' ) else os.path.join( d, x ) for x in open( f ).read().splitlines()]
        except IOError:
            sublist = []
            print '*** ERROR *** Failed to get a removal list from "%s".' % ( f )
            print
    else:
        sublist = [ os.path.join( BUILD_DIR, op )]
    for f in sublist:
        print ' ', f
        if os.path.isdir( f ):
            remove_tree( f )
        else:
            os.remove( f )

print 'Zip to', pack
shutil.make_archive( pack, format='zip', root_dir=BUILD_DIR )
move_file( pack + '.zip', pack )

print 'Write version to', IDX_FILE
idx = minidom.parse( IDX_FILE )
idx.getElementsByTagName( 'pdsc' )[ 0 ].attributes[ 'version' ].value = ver
print idx.toxml()
idx.writexml( open( IDX_FILE, "wb" ), newl="\n" )

open( os.path.join( BUILD_DIR, '.gitignore' ), 'w' ).write( '*' )
print 'Done'
