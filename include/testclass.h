#ifndef __TEST_CLASS_H__
#define __TEST_CLASS_H__

#include <node_api.h>

class TestClass {
  public:
    static napi_value Init(napi_env env, napi_value exports);
    static void Destructor(napi_env env, void *nativeObj, void *finalize_hint);

  private:
    explicit TestClass(int code);
    ~TestClass();

    int GetCode();
    void Succ();

    static napi_value New(napi_env env, napi_callback_info info);
    static napi_value GetCode(napi_env env, napi_callback_info info);
    static void Succ(napi_env env, napi_callback_info info);
    static napi_ref constructor;

    int _code;
    napi_env _env;
    napi_ref _wrapper;
};

#endif