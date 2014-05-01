from distutils.core import setup
from distutils.extension import Extension

setup(name="lirecoin_subsidys",
    ext_modules=[
        Extension("lirecoin_subsidy", ["lirecoin_GetBlockBaseValue.cpp"],
        libraries = ["boost_python"])
    ])
