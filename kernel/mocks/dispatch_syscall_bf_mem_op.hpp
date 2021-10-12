/// @copyright
/// Copyright (C) 2020 Assured Information Security, Inc.
///
/// @copyright
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
///
/// @copyright
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
///
/// @copyright
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
/// SOFTWARE.

#ifndef MOCKS_DISPATCH_SYSCALL_BF_MEM_OP_HPP
#define MOCKS_DISPATCH_SYSCALL_BF_MEM_OP_HPP

#include <bf_constants.hpp>
#include <bf_types.hpp>
#include <huge_pool_t.hpp>
#include <page_pool_t.hpp>
#include <tls_t.hpp>

#include <bsl/discard.hpp>
#include <bsl/errc_type.hpp>

namespace mk
{
    /// @brief defines a unit testing specific error code
    constexpr bsl::errc_type SYSCALL_BF_MEM_OP_FAILS{-80000};

    /// <!-- description -->
    ///   @brief Dispatches the bf_mem_op syscalls
    ///
    /// <!-- inputs/outputs -->
    ///   @param tls the current TLS block
    ///   @param page_pool the page_pool_t to use
    ///   @param huge_pool the huge pool to use
    ///   @return Returns a bf_status_t containing success or failure
    ///
    [[nodiscard]] constexpr auto
    dispatch_syscall_bf_mem_op(
        tls_t const &tls, page_pool_t const &page_pool, huge_pool_t const &huge_pool) noexcept
        -> syscall::bf_status_t
    {
        bsl::discard(page_pool);
        bsl::discard(huge_pool);

        if (SYSCALL_BF_MEM_OP_FAILS == tls.test_ret) {
            return syscall::BF_STATUS_FAILURE_UNKNOWN;
        }

        return syscall::BF_STATUS_SUCCESS;
    }
}

#endif
