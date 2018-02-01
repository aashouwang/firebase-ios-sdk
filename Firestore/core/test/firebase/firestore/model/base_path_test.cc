/*
 * Copyright 2018 Google
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "Firestore/core/src/firebase/firestore/model/base_path.h"

#include <initializer_list>
#include <string>
#include <vector>

#include "gtest/gtest.h"

namespace firebase {
namespace firestore {
namespace model {

// A simple struct to be able to instantiate BasePath.
struct Path : impl::BasePath<Path> {
  Path() = default;
  template <typename IterT>
  Path(const IterT begin, const IterT end) : BasePath{begin, end} {
  }
  Path(std::initializer_list<std::string> list) : BasePath{list} {
  }
};

TEST(BasePath, Constructor) {
  const Path empty_path;
  EXPECT_TRUE(empty_path.empty());
  EXPECT_EQ(0, empty_path.size());
  EXPECT_TRUE(empty_path.begin() == empty_path.end());

  const Path path_from_list{{"rooms", "Eros", "messages"}};
  EXPECT_FALSE(path_from_list.empty());
  EXPECT_EQ(3, path_from_list.size());
  EXPECT_TRUE(path_from_list.begin() + 3 == path_from_list.end());

  std::vector<std::string> segments{"rooms", "Eros", "messages"};
  const Path path_from_segments{segments.begin(), segments.end()};
  EXPECT_FALSE(path_from_segments.empty());
  EXPECT_EQ(3, path_from_segments.size());
  EXPECT_TRUE(path_from_segments.begin() + 3 == path_from_segments.end());

  // EXPECT_EQ(0, timestamp_zero.seconds());
}

// constructor
// indexing
// WithoutFirst
// WithoutLast
// Concatenated
// <
// isPrefixOf

// throws on invalid
// canonical string
// --//-- of substr?

}  // namespace model
}  // namespace firestore
}  // namespace firebase
