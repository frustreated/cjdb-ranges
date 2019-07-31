//
//  Copyright Christopher Di Bella
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
#ifndef CJDB_CONCEPTS_CALLABLE_PREDICATE_HPP
#define CJDB_CONCEPTS_CALLABLE_PREDICATE_HPP

#include "cjdb/concepts/core/convertible_to.hpp"
#include "cjdb/concepts/callable/regular_invocable.hpp"
#include "cjdb/type_traits/type_traits.hpp"

namespace cjdb {
   /// \see [concept.predicate]
   ///
   template<class F, class... Args>
   concept predicate =
      regular_invocable<F, Args...> and
      convertible_to<invoke_result_t<F, Args...>, bool>;
} // namespace cjdb

#endif // CJDB_CONCEPTS_CALLABLE_PREDICATE_HPP
