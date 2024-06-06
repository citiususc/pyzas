import os
import sys
from setuptools import Extension, setup


cmd = ['build', '--build-lib', os.getcwd()]
sys.argv.extend(cmd)

setup(
    ext_modules=[
        Extension(
            name="pyzas.pyzas",
            sources=["c/pyzas.c", "c/methods.c"],
        ),
    ]
)