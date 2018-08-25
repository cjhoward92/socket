#include "../include/testclass.h"

TestClass::TestClass(int code) {
  _code = code;
}

TestClass::~TestClass() {
  _code = 0;
}

int TestClass::GetCode() {
  return _code;
}

void TestClass::Succ() {
  _code++;
}

napi_value TestClass::Init(napi_env env, napi_value exports) {
  
}