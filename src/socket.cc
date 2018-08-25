#include <node_api.h>
#include <sys/socket.h>

#include "../include/testclass.h"

// napi_value Listen(napi_env env, napi_callback_info info) {
//   napi_status status;
//   napi_value connected;


// }

napi_value Hello(napi_env env, napi_callback_info info) {
  napi_status status;
  napi_value world;
  status = napi_create_string_utf8(env, "Hello world", 11, &world);
  if (status != napi_ok) return NULL;
  return world;
}

#define DECLARE_NAPI_METHOD(name, func) \
  { name, 0, func, 0, 0, 0, napi_default, 0 }

napi_value Init(napi_env env, napi_value exports) {
  napi_status status;
  napi_property_descriptor desc = DECLARE_NAPI_METHOD("hello", Hello);
  status = napi_define_properties(env, exports, 1, &desc);
  if (status != napi_ok) return NULL;
  return exports;
}

NAPI_MODULE(socket, Init)