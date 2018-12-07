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
#ifndef CJDB_DETAIL_CONCEPTS_CORE_DESTRUCTIBLE_HPP
#define CJDB_DETAIL_CONCEPTS_CORE_DESTRUCTIBLE_HPP

#include "cjdb/detail/type_traits/type_traits.hpp"

namespace cjdb {
   /// \brief The `Destructible` concept specifies properties of all types, instances of which can
   ///        be destroyed at the end of their lifetime, or reference types.
   /// \note Unlike the _Cpp17Destructible_ requirements, this concept forbids destructors
   ///       that are potentially throwing, even if a particular invocation of the destructor does
   ///       not actually throw.
   /// \see [concepts.destructible]
   /// \see Table 29
   ///
   template<class T>
   concept Destructible = is_nothrow_destructible_v<T>;
} // namespace cjdb

#endif // CJDB_DETAIL_CONCEPTS_CORE_DESTRUCTIBLE_HPP
