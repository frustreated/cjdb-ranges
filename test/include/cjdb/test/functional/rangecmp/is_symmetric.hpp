//
//  Copyright 2019 Christopher Di Bella
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
#ifndef CJDB_TEST_FUNCTIONAL_RANGECMP_IS_SYMMETRIC_HPP
#define CJDB_TEST_FUNCTIONAL_RANGECMP_IS_SYMMETRIC_HPP

#include "cjdb/concepts/callable/relation.hpp"
#include "cjdb/test/constexpr_check.hpp"
#include "cjdb/test/functional/rangecmp/relation.hpp"
#include <utility>

namespace cjdb_test {
   template<class R>
   class is_symmetric : protected relation<R> {
   public:
      constexpr explicit is_symmetric(R r)
         : relation<R>(std::move(r))
      {}

      /// \brief Checks that the relation is symmetric, with respect to types T and U.
      /// \param a Parameter to check.
      /// \param b Parameter to check.
      /// \returns invoke(r, a, b) == invoke(r, b, a)
      ///
      template<class A, class B>
      requires cjdb::Relation<R, A, B>
      constexpr bool symmetric(A const& a, B const& b) noexcept
      { return symmetric_impl(*this, a, b); }

      /// \brief Checks that the relation is symmetric, with respect to types T and U.
      /// \param a Parameter to check.
      /// \param b Parameter to check.
      /// \returns invoke(r, a, b) == invoke(r, b, a)
      ///
      template<class A, class B>
      requires cjdb::Relation<R, A, B>
      constexpr bool symmetric(A const& a, B const& b) const noexcept
      { return symmetric_impl(*this, a, b); }
   private:
      template<class Self, class A, class B>
      constexpr static bool symmetric_impl(Self& self, A const& a, B const& b) noexcept
      { return self(a, b) == self(b, a); }
   };
} // namespace cjdb

#define CHECK_IS_SYMMETRIC(r, a, b)                          \
   {                                                         \
      using cjdb_test::is_symmetric;                         \
      CJDB_CONSTEXPR_CHECK(is_symmetric{r}.symmetric(a, b)); \
   }                                                         \


#endif // CJDB_TEST_FUNCTIONAL_RANGECMP_IS_SYMMETRIC_HPP