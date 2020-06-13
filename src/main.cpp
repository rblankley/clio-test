/**
 * @file main.cpp
 * @brief Logging example for libclio.
 *
 * @copyright Copyright (C) 2017 Randy Blankley. All rights reserved.
 *
 * @section LICENSE
 *
 * This file is part of clio-test.
 *
 * clio-test is free software: you can redistribute it and/or modify it under the terms of the
 * GNU General Public License as published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See
 * the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with this program. If
 * not, see <http://www.gnu.org/licenses/>.
 */

#if HAVE_CONFIG_H
#include <config.h>
#endif

#include "testcases.h"

#include <clio.h>

#ifdef HAVE_FILESYSTEM
#include <filesystem>
#endif

#include <chrono>
#include <cstdlib>
#include <iostream>
#include <thread>

#define UNUSED(x) [&x]{}()

#if _WIN32
static constexpr const char* PACKAGE_STRING = "clio-test 1.0.0";
#endif

///////////////////////////////////////////////////////////////////////////////////////////////////
void runTestCases()
{
    log1 log_1;
    log_1.test1();
    log_1.test2();

    log2_t1 log_21;
    log_21.test3();

    log2_t2 log_22;
    log_22.test3();

    test1::log3 log_3;
    log_3.test1();
    log_3.test3();

    test2::log4 log_4;
    log_4.test1();
    log_4.test3();
}

///////////////////////////////////////////////////////////////////////////////////////////////////
int main( int argc, const char *argv[] )
{
    UNUSED( argc );
    UNUSED( argv );

#ifdef HAVE_FILESYSTEM
    std::filesystem::copy( "clio-test-1.config", "clio-test.config", std::filesystem::copy_options::overwrite_existing );
#else
    ::system( "cp clio-test-1.config clio-test.config" );
#endif

    CLIO_INIT_WITH_INTERVAL( "clio-test.config", 1000 );

    std::cout << "Hello World!" << std::endl;
    std::cout << "This is " << PACKAGE_STRING << "." << std::endl;
    std::cout << "Using libclio version " << clioGetVersion() << "." << std::endl;

    LOG_FATAL << "Fatal error!";
    LOG_ERROR << "This is an error message";
    LOG_WARN << "WARNING";
    LOG_INFO << "Informational message";
    LOG_DEBUG << "Debug line";
    LOG_TRACE << "Tracing message";

    static const char buffer[] = {
        0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
        0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
        0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
        0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f };

    LOG_DEBUG << HEX_DUMP( buffer, sizeof(buffer) );
    LOG_DEBUG << HEX_DUMP_W( buffer, sizeof(buffer), 10 );

    // ---- //

    runTestCases();

#ifdef HAVE_FILESYSTEM
    std::filesystem::copy( "clio-test-2.config", "clio-test.config", std::filesystem::copy_options::overwrite_existing );
#else
    ::system( "cp clio-test-2.config clio-test.config" );
#endif

    std::this_thread::sleep_for( std::chrono::seconds( 5 ) );
    LOG_ERROR << "No more logging after this message!";

    runTestCases();

    // ---- //

    CLIO_FINALIZE

    return 0;
}
