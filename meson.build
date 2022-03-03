# -----------------------------------------------------------------------------
#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus/)
# Copyright (c) 2022 Liviu Ionescu
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# If a copy of the license was not distributed with this file, it can
# be obtained from https://opensource.org/licenses/MIT/.
#
# -----------------------------------------------------------------------------

# This file is intended to be consumed by applications with:
#
# `subdir('xpacks/xpack-3rd-party-boost-ut')`
#
# The result is a library that can be refered as:
#
# ```
#  dependencies: [ xpack_3rd_party_xxx_yyy_dependency ],
# ```

# Note: the meson configuration is provided only as a proof of concept,
# for production it might need some refinements.

# -----------------------------------------------------------------------------

message('Processing xPack @xpack-3rd-party/boost-ut...')

xpack_common_args = []
xpack_c_args = []
xpack_cpp_args = []
xpack_include_directories = []
xpack_sources = []
xpack_compile_definitions = []

xpack_common_args += [
  '-Wno-padded',
  '-Wno-aggregate-return',
]

if c_compiler.get_id() == 'gcc'
  xpack_common_args += [
  ]
elif c_compiler.get_id().contains('clang')
  xpack_common_args += [
    '-Wno-c++98-c++11-c++14-c++17-compat-pedantic',
    '-Wno-c++98-c++11-compat',
    '-Wno-c++98-compat',
    '-Wno-c++98-compat-pedantic',
    '-Wno-c99-extensions',
    '-Wno-pedantic',

    '-Wno-exit-time-destructors',
    '-Wno-ctad-maybe-unsupported',
    '-Wno-global-constructors',
    '-Wno-extra-semi-stmt',
  ]
endif

xpack_cpp_args += [
]

if c_compiler.get_id() == 'gcc'
  xpack_cpp_args += [
  ]
endif

xpack_include_directories += [
  'include',
]

# https://mesonbuild.com/Reference-manual_functions.html#declare_dependency
xpack_3rd_party_boost_ut_dependency = declare_dependency(
  include_directories: include_directories(xpack_include_directories),
  compile_args: xpack_common_args
)

# Dependencies cannot store language specific definitions, the only
# way is to pass them via global variables. All applications including
# this dependency must also consider them.
xpack_3rd_party_boost_ut_dependency_c_args = xpack_c_args
xpack_3rd_party_boost_ut_dependency_cpp_args = xpack_cpp_args

foreach name : xpack_include_directories
  message('+ -I ' + name)
endforeach
foreach name : xpack_sources + xpack_common_args
  message('+ ' + name)
endforeach
message('> xpack_3rd_party_boost_ut_dependency')

# -----------------------------------------------------------------------------

if(false)
project('boost.ut', 'cpp')
boostut_dep = declare_dependency(include_directories : include_directories('include'))
if meson.version().version_compare('>=0.54.0')
  meson.override_dependency('boost.ut', boostut_dep)
endif
endif
