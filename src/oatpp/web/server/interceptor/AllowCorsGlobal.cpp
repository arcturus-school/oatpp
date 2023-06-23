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

#include "AllowCorsGlobal.hpp"

namespace oatpp { namespace web { namespace server { namespace interceptor {
// 跨域预检请求(options), 处理成功后返回状态码 204
std::shared_ptr<protocol::http::outgoing::Response> AllowOptionsGlobal::intercept(const std::shared_ptr<IncomingRequest> &request) {

  const auto &line = request->getStartingLine();

  if (line.method == "OPTIONS") {
    return OutgoingResponse::createShared(protocol::http::Status::CODE_204, nullptr);
  }

  return nullptr; // 不做处理

}

AllowCorsGlobal::AllowCorsGlobal(const oatpp::String &origin,
                                 const oatpp::String &methods,
                                 const oatpp::String &headers,
                                 const oatpp::String &maxAge)
  : m_origin(origin)
  , m_methods(methods)
  , m_headers(headers)
  , m_maxAge(maxAge)
{}

std::shared_ptr<protocol::http::outgoing::Response> AllowCorsGlobal::intercept(const std::shared_ptr<IncomingRequest>& request,
                                                                               const std::shared_ptr<OutgoingResponse>& response)
{
  // 设置响应头
  response->putHeaderIfNotExists(protocol::http::Header::CORS_ORIGIN, m_origin); // Access-Control-Allow-Origin
  response->putHeaderIfNotExists(protocol::http::Header::CORS_METHODS, m_methods); // Access-Control-Allow-Methods
  response->putHeaderIfNotExists(protocol::http::Header::CORS_HEADERS, m_headers); // Access-Control-Allow-Headers
  response->putHeaderIfNotExists(protocol::http::Header::CORS_MAX_AGE, m_maxAge); // Access-Control-Max-Age
  return response;
}

}}}}
