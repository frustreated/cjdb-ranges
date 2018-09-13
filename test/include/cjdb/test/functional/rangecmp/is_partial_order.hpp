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
#ifndef CJDB_TEST_FUNCTIONAL_RANGECMP_IS_PARTIAL_ORDER_HPP
#define CJDB_TEST_FUNCTIONAL_RANGECMP_IS_PARTIAL_ORDER_HPP

#include "cjdb/test/functional/rangecmp/is_antisymmetric.hpp"
#include "cjdb/test/functional/rangecmp/is_reflexive.hpp"
#include "cjdb/test/functional/rangecmp/is_transitive.hpp"

#define CHECK_IS_PARTIAL_ORDER(r, a, b, c) \
   {                                       \
      CHECK_IS_REFLEXIVE(r, a);            \
      CHECK_IS_ANTISYMMETRIC(r, a, b);     \
      CHECK_IS_TRANSITIVE(r, a, b, c);     \
   }                                       \


#endif // CJDB_TEST_FUNCTIONAL_RANGECMP_IS_PARTIAL_ORDER_HPP