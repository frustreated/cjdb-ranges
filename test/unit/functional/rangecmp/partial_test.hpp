// Copyright (c) Christopher Di Bella.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
#ifndef CJDB_TEST_FUNCTIONAL_RANGECMP_PARTIAL_TEST_HPP
#define CJDB_TEST_FUNCTIONAL_RANGECMP_PARTIAL_TEST_HPP

#include <algorithm> // FIXME(cjdb): change to "cjdb/algorithm/find_if.hpp"
#include "cjdb/test/simple_test.hpp"
#include <iterator>  // FIXME(cjdb): change to "cjdb/range/access.hpp"
#include <numeric>   // FIXME(cjdb): change to "cjdb/range/iota_view.hpp"
#include <vector>

namespace cjdb_test {
	// FIXME(cjdb): change function to `view::iota | view::take` when it's available
	inline std::vector<int> generate_ints(int const size = 10) noexcept {
		auto result = std::vector<int>(static_cast<std::vector<int>::size_type>(size));
		std::iota(std::begin(result), std::end(result), 0);
		return result;
	}

	// FIXME(cjdb): s/class R/InputRange R/
	// FIXME(cjdb): s/class PartialPred/IndirectUnaryInvocable<range_value_t<R>>/
	// FIXME(cjdb): s/class Pred/IndirectUnaryInvocable<range_value_t<R>>/
	template<class R, class PartialPred, class Pred>
	void check_iterators_match(R&& r, PartialPred partial_pred, Pred pred) noexcept {
		// FIXME(cjdb): s/std::find_if(std::begin(r), std::end(r)/cjdb::ranges::find_if(r/
		auto const actual = std::find_if(std::begin(r), std::end(r), partial_pred);

		// FIXME(cjdb): s/std::find_if(std::begin(r), std::end(r)/cjdb::ranges::find_if(r/
		auto const expected = std::find_if(std::begin(r), std::end(r),
			[&](auto const& x) noexcept { return pred(partial_pred.value(), x); });
		CHECK(actual == expected);
	}
} // namespace cjdb_test

#endif // CJDB_TEST_FUNCTIONAL_RANGECMP_PARTIAL_TEST_HPP
