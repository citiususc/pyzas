import os
import sys
import shlex
import sys
import re
from setuptools import Extension, setup

extra_compile_args = []
cmd = ['build', '--build-lib', os.getcwd()]
sys.argv.extend(cmd)

if "PYZAS_CFLAGS" in os.environ:
    extra_compile_args = shlex.split(os.environ["PYZAS_CFLAGS"])

if "PYZAS_FIX_GIL" in os.environ:
    extra_compile_args.append("-DPy_GIL_DISABLED=1")

setup(
    ext_modules=[
        Extension(
            name="pyzas.pyzas",
            sources=["c/pyzas.c", "c/methods.c"],
            extra_compile_args=extra_compile_args,
        ),
    ]
)

if "PYZAS_FIX_GIL" in os.environ:
    base_name = f"cp3{str(sys.version_info[1])}"
    expected_name = f"{base_name}t"
    for file in os.listdir("pyzas"):
        expected_name = re.sub(r"(cp313)([^t])", r"\1t\2", file)
        if file != expected_name:
                os.rename(os.path.join("pyzas", file), os.path.join("pyzas", expected_name))
