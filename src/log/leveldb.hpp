/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __LOG_LEVELDB_HPP__
#define __LOG_LEVELDB_HPP__

#include <leveldb/db.h>

#include "log/storage.hpp"

namespace mesos {
namespace internal {
namespace log {

// Concrete implementation of the storage interface using leveldb.
class LevelDBStorage : public Storage
{
public:
  LevelDBStorage();
  virtual ~LevelDBStorage();

  virtual Try<State> restore(const std::string& path);
  virtual Try<Nothing> persist(const Metadata& metadata);
  virtual Try<Nothing> persist(const Action& action);
  virtual Try<Action> read(uint64_t position);

private:
  leveldb::DB* db;
  uint64_t first; // First position still in leveldb, used during truncation.
};

} // namespace log {
} // namespace internal {
} // namespace mesos {

#endif // __LOG_LEVELDB_HPP__
