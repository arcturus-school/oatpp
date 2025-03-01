/***************************************************************************
 *
 * Project         _____    __   ____   _      _
 *                (  _  )  /__\ (_  _)_| |_  _| |_
 *                 )(_)(  /(__)\  )( (_   _)(_   _)
 *                (_____)(__)(__)(__)  |_|    |_|
 *
 *
 * Copyright 2018-present, Leonid Stryzhevskyi <lganzzzo@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ***************************************************************************/

#ifndef oatpp_web_protocol_http_encoding_ProviderCollection_hpp
#define oatpp_web_protocol_http_encoding_ProviderCollection_hpp

#include "EncoderProvider.hpp"
#include "oatpp/core/data/share/MemoryLabel.hpp"
#include <unordered_map>
#include <unordered_set>

namespace oatpp { namespace web { namespace protocol { namespace http { namespace encoding {

/**
 * EncoderProvider 集合
 * Collection of &id:oatpp::web::protocol::http::encoding::EncoderProvider;.
 */
class ProviderCollection {
private:
  std::unordered_map<data::share::StringKeyLabelCI, std::shared_ptr<EncoderProvider>> m_providers;
public:

  /**
   * Add encoder to collection.
   * @param provider
   */
  void add(const std::shared_ptr<EncoderProvider>& provider);

  /**
   * Get encoder by encoding name.
   * @param encoding - encoding name.
   * @return
   */
  std::shared_ptr<EncoderProvider> get(const data::share::StringKeyLabelCI& encoding) const;

  /**
   * Select available provider for set of encodings.
   * @param encodings - set of desired encodings
   * @return
   */
  std::shared_ptr<EncoderProvider> get(const std::unordered_set<data::share::StringKeyLabelCI>& encodings) const;

};

}}}}}

#endif // oatpp_web_protocol_http_encoding_ProviderCollection_hpp
