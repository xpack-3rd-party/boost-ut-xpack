/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus/)
 * Copyright (c) 2022 Liviu Ionescu.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from https://opensource.org/licenses/MIT/.
 */

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_INCLUDE_CONFIG_H)
#include <micro-os-plus/config.h>
#endif // MICRO_OS_PLUS_INCLUDE_CONFIG_H

#include <micro-os-plus/platform.h>
#include <boost/ut.hpp>
#include <cstring>

// ----------------------------------------------------------------------------

// #pragma GCC diagnostic ignored "-Waggregate-return"

// ----------------------------------------------------------------------------

// Simple examples of functions to be tested.
static int
compute_one (void)
{
  return 1;
}

static const char*
compute_aaa (void)
{
  return "aaa";
}

static bool
compute_condition (void)
{
  return true;
}

int
main ([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
  using namespace boost::ut;

  "something"_test = [] {
    expect(compute_one() == 1_i);
    expect(strcmp(compute_aaa(), "aaa") == 0);
    expect(compute_condition());
  };

  "main args"_test = [argc, argv]() {
    expect(argc == 3_i);
    expect(strcmp(argv[1], "one") == 0);
    expect(strcmp(argv[2], "two") == 0);
  };
}

// ----------------------------------------------------------------------------
