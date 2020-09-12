import subprocess
import glob
import sys
import os

srcdir = os.path.abspath(os.path.dirname(__file__))
pandadir = os.path.abspath(sys.argv[1])

def run_command(cmd):
    p = subprocess.Popen(cmd, stdout=sys.stdout, stderr=sys.stderr, shell=True)
    ret = p.wait()

    if ret != 0:
        print("\n")
        print('The following command return a non-zero value (%d): %s' % (ret, cmd))
        sys.exit(ret)

def interrogate(module):
    print('Interrogating', module)
    cmd = os.path.join(pandadir, 'bin', 'interrogate')
    cmd += ' -D__inline -DCPPPARSER -DP3_INTERROGATE=1 -D__cplusplus -fnames -string -refcount -assert'
    cmd += ' -S"%(pandadir)s/include/parser-inc" -S"%(pandadir)s/include" -I"%(pandadir)s/include" -I"%(srcdir)s/suit" -I"%(srcdir)s/dna"'
    cmd += ' -I"%(srcdir)s/toontownbase"'
    if module == 'dnaLoader':
        cmd += ' -srcdir "%(srcdir)s/dna"'
    else:
        cmd += ' -srcdir "%(srcdir)s/%(module)s"'
    cmd += ' -oc "%(srcdir)s/%(module)s_igate.cxx" -od "%(srcdir)s/lib%(module)s.in" -python-native -DCPPPARSER -D__STDC__=1'
    cmd += ' -D__cplusplus -D__inline -D_X86_ -DWIN32_VC -DWIN32 -module libtoontown -library %(module)s -Dvolatile='

    cmd = cmd % {'pandadir': pandadir, 'module': module, 'srcdir': srcdir}
    if module == 'dnaLoader':
        files = glob.glob(os.path.join(srcdir, 'dna', '*.h'))
        files += glob.glob(os.path.join(srcdir, 'dna', '*.cxx'))
    else:
        files = glob.glob(os.path.join(srcdir, module, '*.h'))
        files += glob.glob(os.path.join(srcdir, module, '*.cxx'))
    for file in files:
        cmd += ' %s' % os.path.basename(file)
    
    run_command(cmd)

for module in ('suit', 'dnaLoader'):
    interrogate(module)

os.chdir(srcdir)
cmd = os.path.join(pandadir, 'bin', 'interrogate_module') + ' -python-native -oc libtoontown_module.cxx'
cmd += ' -library libtoontown -module libtoontown libsuit.in libdnaLoader.in'
run_command(cmd)
