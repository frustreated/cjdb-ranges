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
#ifndef CJDB_DETAIL_CONCEPTS_CORE_COMMONREFERENCE_HPP
#define CJDB_DETAIL_CONCEPTS_CORE_COMMONREFERENCE_HPP

#include "cjdb/detail/concepts/core/convertibleto.hpp"
#include "cjdb/detail/concepts/core/same.hpp"
#include "cjdb/detail/type_traits/common_reference.hpp"

namespace cjdb {
   /// \see [concept.commonref]
   template<class T, class U>
   concept CommonReference =
      Same<common_reference_t<T, U>, common_reference_t<U, T>> and
      ConvertibleTo<T, common_reference_t<T, U>> and
      ConvertibleTo<U, common_reference_t<T, U>>;
} // namespace cjdb

#endif // CJDB_DETAIL_CONCEPTS_CORE_COMMONREFERENCE_HPP
