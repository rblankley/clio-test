/**
 * @file testcases.h
 * @brief Test cases.
 *
 * @copyright Copyright (C) 2020 Randy Blankley. All rights reserved.
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

#ifndef TESTCASES_H
#define TESTCASES_H

#include <clio.h>

///////////////////////////////////////////////////////////////////////////////////////////////////
class log1
{
public:
    log1() {}
    ~log1() {}

    void test1() {
        LOG_INFO << "Should see this line";
    }
    
    void test2() const {
        LOG_TRACE << "Should NOT see this line";
    }

};

///////////////////////////////////////////////////////////////////////////////////////////////////
class log2_t1
{
public:
    log2_t1() {}
    ~log2_t1() {}

    void test3() {
        LOG_INFO << "Should see this line in log2";
    }

};

///////////////////////////////////////////////////////////////////////////////////////////////////
class log2_t2
{
public:
    log2_t2() {}
    ~log2_t2() {}

    void test3() {
        LOG_INFO << "Should see this line in log2";
    }

};

///////////////////////////////////////////////////////////////////////////////////////////////////
namespace test1
{
    class log3
    {
    public:
        log3() {}
        ~log3() {}

        void test1() {
            LOG_INFO << "Should see this line in log3";
        }

        void test3() {
            LOG_INFO << "Should see this line in log3"; // matches test1.* pattern before *.XXX
        }

    };

}

///////////////////////////////////////////////////////////////////////////////////////////////////
namespace test2
{
    class log4
    {
    public:
        log4() {}
        ~log4() {}

        void test1() {
            LOG_INFO << "Should see this line in log4 AND Console";
        }

        void test3() {
            LOG_INFO << "Should see this line in log2 AND Console";
        }

    };

}

///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TESTCASES_H