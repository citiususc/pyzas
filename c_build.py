import os
import sys
import shlex
from setuptools import Extension, setup

extra_compile_args = []
cmd = ['build', '--build-lib', os.getcwd()]
sys.argv.extend(cmd)

if "PYZAS_CFLAGS" in os.environ:
    extra_compile_args = shlex.split(os.environ["PYZAS_CFLAGS"])

setup(
    ext_modules=[
        Extension(
            name="pyzas.pyzas",
            sources=["c/pyzas.c", "c/methods.c"],
            extra_compile_args=extra_compile_args,
        ),
    ]
)
