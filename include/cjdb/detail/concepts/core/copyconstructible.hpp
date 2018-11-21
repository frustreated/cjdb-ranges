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
#ifndef CJDB_DETAIL_CONCEPTS_CORE_COPYCONSTRUCTIBLE_HPP
#define CJDB_DETAIL_CONCEPTS_CORE_COPYCONSTRUCTIBLE_HPP

#include "cjdb/detail/concepts/core/constructible.hpp"
#include "cjdb/detail/concepts/core/moveconstructible.hpp"

namespace cjdb {
   /// \see [concepts.copyconstructible]
   ///
   template<class T>
   concept CopyConstructible =
      MoveConstructible<T> and
      Constructible<T, T&> and
      ConvertibleTo<T&, T> and
      Constructible<T, const T&> and
      ConvertibleTo<const T&, T> and
      Constructible<T, const T> and
      ConvertibleTo<const T, T>;
} // namespace cjdb

#endif // CJDB_DETAIL_CONCEPTS_CORE_COPYCONSTRUCTIBLE_HPP