import subprocess, os, sys, shutil


bin_deps = [
    'cmake',
    'make',
    'g++'
]
dep_fail = False
for dep in bin_deps:
    if shutil.which(dep) is None:
        print("[-] Missing " + dep)
        dep_fail = True
if dep_fail is True:
    print("[-] One or more build dependencies are missing.. please correct and try again")
    sys.exit(0)

if not os.path.isfile("CMakeLists.txt"):
    print("[-] Missing CMake file")
    sys.exit(0)

print("[+] Generating Makefile with CMake")
os.mkdir("build")
os.chdir("build")
ret = subprocess.call(['cmake', '..'])
if ret != 0:
    print("[-] CMake build failed, check corresponding error message")
if os.path.isfile("/home/" + os.getenv("USER") + "/bin/todo"):
    print("[-] Todo executable already exists in local bin folder. Halting installation..")
    sys.exit(0)
if not os.path.isdir("/home/" + os.getenv("USER") + "/bin"):
    print("[-] Local 'bin' dir does not exist, creating directory.. Consider adding this directory"
          " to your $PATH")
    os.mkdir("/home/" + os.getenv("USER") + "/bin")


print("[+] Copying 'todo' executable to local bin folder..")
subprocess.call(['cp', 'todo', '/home/' + os.getenv("USER") + '/bin'])

if not os.path.isdir("/etc/bash_completion.d"):
    print("[-] Bash completion script directory does not exist, creating..."
          " You will probably need to source this directory in your bashrc to enable auto-completion features")
    subprocess.call(['sudo', 'mkdir', '/etc/bash_completion.d'])
    os.mkdir("/etc/bash_completion.d")

os.chdir("..")
print("[+] Copying bash completion script..")
subprocess.call(['sudo', 'cp', 'scripts/todo_completion.sh', '/etc/bash_completion.d'])

print("[+] Done")




